/*************************************************************************
  KD8CEC's CAT Library for uBITX and HAM
  This source code is written for uBITX, but it can also be used on other radios.
  
  The CAT protocol is used by many radios to provide remote control to comptuers through
  the serial port.
  it is based on FT-817, uBITX's only protocol has been added and will be added in the future.
  In addition, simple things such as FT-857 frequency control and PTT control can also be 
  transmitted to the FT-857 protocol.

  This code refers to the following code.
  - FT857D CAT Library, by Pavel Milanes, CO7WT, pavelmc@gmail.com 
    https://github.com/pavelmc/FT857d/
  - Ham Radio Control Libraries, https://sourceforge.net/projects/hamlib/
  - Not found protocols decription were analyzed using an RS-232 analyzer.
    using FT-817 and 
  - http://www.ka7oei.com/ft817_meow.html <-- It was a great help here.
  
-----------------------------------------------------------------------------
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.

**************************************************************************/

#include "ubitx.h"

//for broken protocol
#define CAT_RECEIVE_TIMEOUT 500 

#define CAT_MODE_LSB            0x00
#define CAT_MODE_USB            0x01
#define CAT_MODE_CW             0x02
#define CAT_MODE_CWR            0x03
#define CAT_MODE_AM             0x04
#define CAT_MODE_FM             0x08
#define CAT_MODE_DIG            0x0A
#define CAT_MODE_PKT            0x0C
#define CAT_MODE_FMN            0x88

#define ACK 0x00                    //mjh change to make unambitious. was 0

unsigned int skipTimeCount = 0;
byte CAT_BUFF[5];
byte CAT_SNDBUFF[5];

void SendCatData(byte sendCount)
{
  for (byte i = 0; i < sendCount; i++)
      Serial.write((byte)CAT_BUFF[i]);
  Serial.flush();  //mjh
}

//PROTOCOL : 0x01
//Computer ->(frequency)-> TRCV CAT_BUFF
void CatSetFreq(byte fromType)
{
  //CAT_BUFF
  byte i;
  unsigned long tempFreq = 0;

  if (fromType == 2 || fromType == 3) {
    Serial.write((byte)ACK);  
    return;  
  }

  //2 digit in 1 byte (4 bit + 4bit) * 4.5 byte
  for (i = 0; i < 4; i++) 
  {
    tempFreq *= 10;
    tempFreq += CAT_BUFF[i] >> 4;
    tempFreq *= 10;
    tempFreq += CAT_BUFF[i] & 0x0f;
  }

  tempFreq *= 10;
  tempFreq += CAT_BUFF[4] >> 4;

  if (!inTx && (frequency != tempFreq))
  {
    //Check Frequency Range
    if (tempFreq >= LOWEST_FREQ_DIAL && tempFreq <= HIGHEST_FREQ_DIAL)
    {
      setFrequency(tempFreq);
      updateDisplay();
    }
    else
    {
        //KD8CEC
        //Remark for rduce program size, if you need, you can remove remark, 
        //however alomost rig control software available 1.0 ~ 50Mhz
        //printLine(0, "OUT OF RANGE!!!");
        //delay_background(300, 0);
    }
  }

  Serial.write((byte)ACK);  
}

//#define BCD_LEN 9
//PROTOCOL : 0x03
//Computer <-(frequency)-> TRCV CAT_BUFF
//void CatGetFreqMode(unsigned long freq, byte fromType)
void CatGetFreqMode(unsigned long freq) //for remove warning messages
{
  int i;
  byte tmpValue;
  unsigned BCD_LEN = 9;

  if (BCD_LEN & 1) {
    CAT_BUFF[BCD_LEN / 2] &= 0x0f;
    CAT_BUFF[BCD_LEN / 2] |= (freq % 10) << 4;

    freq /= 10;
  }
  for (i = (BCD_LEN / 2) - 1; i >= 0; i--) {
    tmpValue = freq % 10;
    freq /= 10;
    tmpValue |= (freq % 10) << 4;
    freq /= 10;
    CAT_BUFF[i] = tmpValue;
  }

  //Mode Check
  if (cwMode == 0)
  {
    if (isUSB)
      CAT_BUFF[4] = CAT_MODE_USB;
    else
      CAT_BUFF[4] = CAT_MODE_LSB;
  }
  else if (cwMode == 1)
  {
      CAT_BUFF[4] = CAT_MODE_CW;
  }
  else
  {
      CAT_BUFF[4] = CAT_MODE_CW;
  }

  SendCatData(5);
}

//void CatSetSplit(boolean isSplit, byte fromType)
void CatSetSplit(boolean isSplit) //for remove warning messages
{
  if (isSplit)
    splitOn = 1;
  else
    splitOn = 0;
    
  Serial.write((byte)ACK);
}

void CatSetPTT(boolean isPTTOn, byte fromType)
{
  //
  if ((!inTx) && (fromType == 2 || fromType == 3)) {
    Serial.write((byte)ACK);  
    return;  
  }
  
  // Set PTT Mode
  if (isPTTOn)
  {
    if (!inTx)
    {
      txCAT = true;
      startTx(TX_SSB, 1);
      //Exit menu, Memory Keyer... ETC
      if (isCWAutoMode > 0) {
        isCWAutoMode = 0;
        printLineF2(F("AutoKey Exit/CAT"));
        //delay_background(1000, 0);
      }
    }
  }
  else
  {
    if (inTx)
    {
      stopTx();
      txCAT = false;
    }
  }

  Serial.write((byte)ACK);
}

void CatVFOToggle(boolean isSendACK, byte fromType)
{
  if (fromType != 2 && fromType != 3) {
    menuVfoToggle(1);
  }  

  if (isSendACK)
    Serial.write((byte)ACK);  //Time 
}

void CatSetMode(byte tmpMode, byte fromType)    //Seems to be missing function to switch to CWU
{
  if (fromType == 2 || fromType == 3) {
    Serial.write((byte)ACK);  
    return;  
  }  
  
  if (!inTx)
  {
    if (tmpMode == CAT_MODE_CW)
    {
      cwMode = 1;                     //Switching to CWL
    }
    else if (tmpMode == CAT_MODE_USB)
    {
      cwMode = 0;
      isUSB = true;                   //Switching to USB
    }
    else
    {
      cwMode = 0;
      isUSB = false;                  //Switching to LSB
    }
    SetCarrierFreq();                 //mjh not in original Mode command
    setFrequency(frequency);
    updateDisplay();
  }
  Serial.write((byte)ACK);
}

//Read EEProm by uBITX Manager Software
//void ReadEEPRom(byte fromType)
void ReadEEPRom() //for remove warnings.
{
  //5BYTES
  //CAT_BUFF[0] [1] [2] [3] [4] //4 COMMAND
  //0, 1 START ADDRESS
  // NOTE: The use of 2 bytes for start and length of EEPROM fetches
  // Limits max EEPROM to 32k
  //
  uint16_t eepromStartIndex = CAT_BUFF[0] + CAT_BUFF[1] * 256;
  uint16_t eepromReadLength = CAT_BUFF[2] + CAT_BUFF[3] * 256;
  byte checkSum = 0;
  byte read1Byte = 0;

  Serial.write((byte)0x02); //STX
  checkSum = 0x02;

  //I2C Scanner
  //Magic Key Start 59414, Length : 48583
  //if (eepromStartIndex == 59414 && eepromReadLength == 48583)
  if (CAT_BUFF[0] == 0x16  && CAT_BUFF[1] == 0xe8)
  {
    for (uint8_t i = 1; i < 127; i++)
    {

      Wire.beginTransmission(i);
      read1Byte = Wire.endTransmission();
      if (read1Byte == 0)
      {
        Serial.write((byte)i);
      }
      else
      {
        Serial.write((byte)0);
      }
    }
  }
  else
  { 
    for (uint16_t i = 0; i < eepromReadLength; i++)
    {
      read1Byte = EEPROMTYPE.read(eepromStartIndex + i);
      checkSum += read1Byte;
      Serial.write((byte)read1Byte);
    }
  }
  
  Serial.write((byte)checkSum);
  Serial.write((byte)ACK);
}

void GetEEPRomSize() 
{
  //5BYTES
  //CAT_BUFF[0] [1] [2] [3] [4] //4 COMMAND
  //0, 1, 2, 3 are don't cares

  uint8_t checkSum = 0;
  uint8_t byteToSend;
  

  Serial.write((byte)0x02); //STX
  checkSum = 0x02;

  for (byte i = 0; i<4; i++)
  {
    byteToSend = (eepromSize >> (8*i)) & 0xff;
    Serial.write((byte)byteToSend);
    checkSum = (checkSum + byteToSend) & 0xff ;
  }

  Serial.write((byte)checkSum);
  Serial.write((byte)ACK);
}

//Write just proecess 1byes
//void WriteEEPRom(byte fromType)
void WriteEEPRom(void)  //for remove warning
{
  //5BYTES
  uint16_t eepromStartIndex = CAT_BUFF[0] + CAT_BUFF[1] * 256;
  byte write1Byte = CAT_BUFF[2];

  //Check Checksum
  if (CAT_BUFF[3] != ((CAT_BUFF[0] + CAT_BUFF[1] + CAT_BUFF[2]) % 256))
  {
    Serial.write((byte)0x56); //CHECK SUM ERROR
    Serial.write((byte)ACK);
  }
  else
  {
    //Special Command
    if (eepromStartIndex == 13131)  //Magic Key
    {
      if (write1Byte == 0x51) //Restart
      {
        #if defined(NANO33IOT)  || defined(NANOBLE) || defined(NANORP2040) || defined(RASPBERRYPIPICO)
           NVIC_SystemReset();
        #elif defined(TEENSY) || defined(TEENSY41)
            SCB_AIRCR = 0x05FA0004;
        #elif defined (NANOEVERY)
            CPU_CCP = CCP_IOREG_gc;
            RSTCTRL.SWRR = RSTCTRL_SWRE_bm;
        #else
            asm volatile ("  jmp 0");
        #endif
      }
    }
    else
    {
      EEPROMTYPE.write(eepromStartIndex, write1Byte);
    }
    
    Serial.write((byte)0x77); //OK  
    Serial.write((byte)ACK);
  }
}

//void ReadEEPRom_FT817(byte fromType)
void ReadEEPRom_FT817(void) //for remove warnings
{
  byte temp0 = CAT_BUFF[0];
  byte temp1 = CAT_BUFF[1];

  CAT_BUFF[0] = 0;
  CAT_BUFF[1] = 0;
  
  switch (temp1)
  {
    case 0x45 : //
      if (temp0 == 0x03)
      {
        CAT_BUFF[0] = 0x00;
        CAT_BUFF[1] = 0xD0;
      }
      break;
    case 0x47 : //
      if (temp0 == 0x03)
      {
        CAT_BUFF[0] = 0xDC;
        CAT_BUFF[1] = 0xE0;
      }
      break;
    case 0x55 :
      //0 : VFO A/B  0 = VFO-A, 1 = VFO-B
      //1 : MTQMB Select  0 = (Not MTQMB), 1 = MTQMB ("Memory Tune Quick Memory Bank")
      //2 : QMB Select  0 = (Not QMB), 1 = QMB  ("Quick Memory Bank")
      //3 :
      //4 : Home Select  0 = (Not HOME), 1 = HOME memory
      //5 : Memory/MTUNE select  0 = Memory, 1 = MTUNE
      //6 :
      //7 : MEM/VFO Select  0 = Memory, 1 = VFO (A or B - see bit 0)
      CAT_BUFF[0] = 0x80 + (vfoActive == VFO_B ? 1 : 0);
      CAT_BUFF[1] = 0x00;
      break;
    case 0x57 : //
      //0 : 1-0  AGC Mode  00 = Auto, 01 = Fast, 10 = Slow, 11 = Off
      //2  DSP On/Off  0 = Off, 1 = On  (Display format)
      //4  PBT On/Off  0 = Off, 1 = On  (Passband Tuning)
      //5  NB On/Off 0 = Off, 1 = On  (Noise Blanker)
      //6  Lock On/Off 0 = Off, 1 = On  (Dial Lock)
      //7  FST (Fast Tuning) On/Off  0 = Off, 1 = On  (Fast tuning)

      CAT_BUFF[0] = 0xC0;
      CAT_BUFF[1] = 0x40;
      break;
    case 0x59 : //  band select VFO A Band Select  0000 = 160 M, 0001 = 75 M, 0010 = 40 M, 0011 = 30 M, 0100 = 20 M, 0101 = 17 M, 0110 = 15 M, 0111 = 12 M, 1000 = 10 M, 1001 = 6 M, 1010 = FM BCB, 1011 = Air, 1100 = 2 M, 1101 = UHF, 1110 = (Phantom)
      //http://www.ka7oei.com/ft817_memmap.html
      //CAT_BUFF[0] = 0xC2;
      //CAT_BUFF[1] = 0x82;
      break;
    case 0x5C : //Beep Volume (0-100) (#13)
      CAT_BUFF[0] = 0xB2;
      CAT_BUFF[1] = 0x42;
      break;
    case 0x5E :
      //3-0 : CW Pitch (300-1000 Hz) (#20)  From 0 to E (HEX) with 0 = 300 Hz and each step representing 50 Hz
      //5-4 :  Lock Mode (#32) 00 = Dial, 01 = Freq, 10 = Panel
      //7-6 :  Op Filter (#38) 00 = Off, 01 = SSB, 10 = CW
      //CAT_BUFF[0] = 0x08;
      CAT_BUFF[0] = sideTonePitch;
      CAT_BUFF[1] = 0x25;
      break;
    case 0x61 : //Sidetone (Volume) (#44)
      CAT_BUFF[0] = sideToneSub;
      CAT_BUFF[1] = 0x08;
      break;
    case  0x5F : //
      //4-0  CW Weight (1.:2.5-1:4.5) (#22)  From 0 to 14 (HEX) with 0 = 1:2.5, incrementing in 0.1 weight steps
      //5  420 ARS (#2)  0 = Off, 1 = On
      //6  144 ARS (#1)  0 = Off, 1 = On
      //7  Sql/RF-G (#45)  0 = Off, 1 = On
      CAT_BUFF[0] = 0x32;
      CAT_BUFF[1] = 0x08;
      break;
    case 0x60 : //CW Delay (10-2500 ms) (#17)  From 1 to 250 (decimal) with each step representing 10 ms
      CAT_BUFF[0] = cwDelayTime;
      CAT_BUFF[1] = 0x32;
      break;
    case 0x62 : //
      //5-0  CW Speed (4-60 WPM) (#21) From 0 to 38 (HEX) with 0 = 4 WPM and 38 = 60 WPM (1 WPM steps)
      //7-6  Batt-Chg (6/8/10 Hours (#11)  00 = 6 Hours, 01 = 8 Hours, 10 = 10 Hours
      //CAT_BUFF[0] = 0x08;
      CAT_BUFF[0] = 1200 / cwSpeed - 4;
      CAT_BUFF[1] = 0xB2;
      break;
    case 0x63 : //
      //6-0  VOX Gain (#51)  Contains 1-100 (decimal) as displayed
      //7  Disable AM/FM Dial (#4) 0 = Enable, 1 = Disable
      CAT_BUFF[0] = 0xB2;
      CAT_BUFF[1] = 0xA5;
      break;
    case 0x64 : //
      break;
    case 0x67 : //6-0  SSB Mic (#46) Contains 0-100 (decimal) as displayed
      CAT_BUFF[0] = 0xB2;
      CAT_BUFF[1] = 0xB2;
      break;      case 0x69 : //FM Mic (#29)  Contains 0-100 (decimal) as displayed
    case 0x78 :
      if (cwMode == 0)
      {
        if (isUSB)
          CAT_BUFF[0] = CAT_MODE_USB;
        else
          CAT_BUFF[0] = CAT_MODE_LSB;
      }
      else if (cwMode == 1)
      {
          CAT_BUFF[0] = CAT_MODE_CW;
      }
      else if (cwMode == 2)
      {
          CAT_BUFF[0] = CAT_MODE_CW;
      }
        
      if (CAT_BUFF[0] != 0) CAT_BUFF[0] = 1 << 5;
      break;
    case  0x79 : //
      //1-0  TX Power (All bands)  00 = High, 01 = L3, 10 = L2, 11 = L1
      //3  PRI On/Off  0 = Off, 1 = On
      //DW On/Off  0 = Off, 1 = On
      //SCN (Scan) Mode  00 = No scan, 10 = Scan up, 11 = Scan down
      //ART On/Off  0 = Off, 1 = On
      CAT_BUFF[0] = 0x00;
      CAT_BUFF[1] = 0x00;
      break;
    case 0x7A : //SPLIT
      //7A  0 HF Antenna Select 0 = Front, 1 = Rear
      //7A  1 6 M Antenna Select  0 = Front, 1 = Rear
      //7A  2 FM BCB Antenna Select 0 = Front, 1 = Rear
      //7A  3 Air Antenna Select  0 = Front, 1 = Rear
      //7A  4 2 M Antenna Select  0 = Front, 1 = Rear
      //7A  5 UHF Antenna Select  0 = Front, 1 = Rear
      //7A  6 ? ?
      //7A  7 SPL On/Off  0 = Off, 1 = On

      CAT_BUFF[0] = (splitOn ? 0xFF : 0x7F);
      break;
    case 0xB3 : //
      CAT_BUFF[0] = 0x00;
      CAT_BUFF[1] = 0x4D;
      break;

  }

  // sent the data
  SendCatData(2);
}

void WriteEEPRom_FT817(byte fromType)
{
  //byte temp0 = CAT_BUFF[0];
  byte temp1 = CAT_BUFF[1];

  CAT_BUFF[0] = 0;
  CAT_BUFF[1] = 0;

  if (fromType == 2 || fromType == 3) {
    SendCatData(2);
    Serial.write((byte)ACK);
    return;  
  }
  switch (temp1)
  {
    case 0x55 :
      //0 : VFO A/B  0 = VFO-A, 1 = VFO-B
      //1 : MTQMB Select  0 = (Not MTQMB), 1 = MTQMB ("Memory Tune Quick Memory Bank")
      //2 : QMB Select  0 = (Not QMB), 1 = QMB  ("Quick Memory Bank")
      //3 :
      //4 : Home Select  0 = (Not HOME), 1 = HOME memory
      //5 : Memory/MTUNE select  0 = Memory, 1 = MTUNE
      //6 :
      //7 : MEM/VFO Select  0 = Memory, 1 = VFO (A or B - see bit 0)
      if (CAT_BUFF[2] & 0x01)  //vfoB
      {
        //nowVFO Check
        if (vfoActive != VFO_B)
        {
          CatVFOToggle(false, fromType);
        }
      }
      else
      {
        //vfoA
        if (vfoActive != VFO_A)
        {
          CatVFOToggle(false, fromType);
        }
      }
      break;
    /*
      case 0x57 : //
      //0 : 1-0  AGC Mode  00 = Auto, 01 = Fast, 10 = Slow, 11 = Off
      //2  DSP On/Off  0 = Off, 1 = On  (Display format)
      //4  PBT On/Off  0 = Off, 1 = On  (Passband Tuning)
      //5  NB On/Off 0 = Off, 1 = On  (Noise Blanker)
      //6  Lock On/Off 0 = Off, 1 = On  (Dial Lock)
      //7  FST (Fast Tuning) On/Off  0 = Off, 1 = On  (Fast tuning)

      CAT_BUFF[0] = 0xC0;
      CAT_BUFF[1] = 0x40;
      break;
      case 0x59 : //  band select VFO A Band Select  0000 = 160 M, 0001 = 75 M, 0010 = 40 M, 0011 = 30 M, 0100 = 20 M, 0101 = 17 M, 0110 = 15 M, 0111 = 12 M, 1000 = 10 M, 1001 = 6 M, 1010 = FM BCB, 1011 = Air, 1100 = 2 M, 1101 = UHF, 1110 = (Phantom)
      //http://www.ka7oei.com/ft817_memmap.html
      //CAT_BUFF[0] = 0xC2;
      //CAT_BUFF[1] = 0x82;
      break;
      case 0x5C : //Beep Volume (0-100) (#13)
      CAT_BUFF[0] = 0xB2;
      CAT_BUFF[1] = 0x42;
      break;
    */
    case 0x5E :
      //3-0 : CW Pitch (300-1000 Hz) (#20)  From 0 to E (HEX) with 0 = 300 Hz and each step representing 50 Hz
      //5-4 :  Lock Mode (#32) 00 = Dial, 01 = Freq, 10 = Panel
      //7-6 :  Op Filter (#38) 00 = Off, 01 = SSB, 10 = CW
      sideTonePitch = (CAT_BUFF[2] & 0x0F);

      if (sideTonePitch != 0 || sideToneSub != 0)
      {
        sideTone = (sideTonePitch * 50 + 300) + sideToneSub;
        printLineF2(F("Sidetone set! CAT"));
        EEPROMTYPE.put(CW_SIDETONE, sideTone);
        delay(300);                       //If timeout errors occur in the calling software, remove them
        clearLine2();
      }
      break;

    case 0x61 : //Sidetone (Volume) (#44)
      sideToneSub = (CAT_BUFF[2] & 0x7F);
      if (sideTonePitch != 0 || sideToneSub != 0)
      {
        sideTone = (sideTonePitch * 50 + 300) + sideToneSub;
        printLineF2(F("Sidetone set! CAT"));
        EEPROMTYPE.put(CW_SIDETONE, sideTone);
        delay(300);                   //If timeout errors occur in the calling software, remove them
        clearLine2();
        line2DisplayStatus = 0;
      }
      break;

    /*
      case  0x5F : //
      //4-0  CW Weight (1.:2.5-1:4.5) (#22)  From 0 to 14 (HEX) with 0 = 1:2.5, incrementing in 0.1 weight steps
      //5  420 ARS (#2)  0 = Off, 1 = On
      //6  144 ARS (#1)  0 = Off, 1 = On
      //7  Sql/RF-G (#45)  0 = Off, 1 = On
      CAT_BUFF[0] = 0x32;
      CAT_BUFF[1] = 0x08;
      break;
    */
    case 0x60 : //CW Delay (10-2500 ms) (#17)  From 1 to 250 (decimal) with each step representing 10 ms
      //CAT_BUFF[0] = 0x19;
      cwDelayTime = CAT_BUFF[2];
      printLineF2(F("CW Speed set!"));
      EEPROMTYPE.put(CW_DELAY, cwDelayTime);
      delay(300);
      clearLine2();
      break;
    case 0x62 : //
      //5-0  CW Speed (4-60 WPM) (#21) From 0 to 38 (HEX) with 0 = 4 WPM and 38 = 60 WPM (1 WPM steps)
      //7-6  Batt-Chg (6/8/10 Hours (#11)  00 = 6 Hours, 01 = 8 Hours, 10 = 10 Hours
      cwSpeed = 1200 / ((CAT_BUFF[2] & 0x3F) + 4);
      printLineF2(F("CW Speed set!"));
      EEPROMTYPE.put(CW_SPEED, cwSpeed);
      delay(300);
      clearLine2();

      break;
      /*
        case 0x63 : //
        //6-0  VOX Gain (#51)  Contains 1-100 (decimal) as displayed
        //7  Disable AM/FM Dial (#4) 0 = Enable, 1 = Disable
        CAT_BUFF[0] = 0xB2;
        CAT_BUFF[1] = 0xA5;
        break;
        case 0x64 : //
        //CAT_BUFF[0] = 0xA5;
        //CAT_BUFF[1] = 0x00;
        break;
        case 0x67 : //6-0  SSB Mic (#46) Contains 0-100 (decimal) as displayed
        CAT_BUFF[0] = 0xB2;
        CAT_BUFF[1] = 0xB2;
        //break;      case 0x69 : //FM Mic (#29)  Contains 0-100 (decimal) as displayed
        //CAT_BUFF[0] = 0x32;
        //CAT_BUFF[1] = 0x32;
        //break;
        case 0x78 :
        CAT_BUFF[0] = catGetMode();
        // check, it must be a bit argument
        if (CAT_BUFF[0] != 0) CAT_BUFF[0] = 1<<5;
        break;
        case  0x79 : //
        //1-0  TX Power (All bands)  00 = High, 01 = L3, 10 = L2, 11 = L1
        //3  PRI On/Off  0 = Off, 1 = On
        //DW On/Off  0 = Off, 1 = On
        //SCN (Scan) Mode  00 = No scan, 10 = Scan up, 11 = Scan down
        //ART On/Off  0 = Off, 1 = On
        CAT_BUFF[0] = 0x00;
        CAT_BUFF[1] = 0x00;
        break;
        case 0x7A : //SPLIT
        //7A  0 HF Antenna Select 0 = Front, 1 = Rear
        //7A  1 6 M Antenna Select  0 = Front, 1 = Rear
        //7A  2 FM BCB Antenna Select 0 = Front, 1 = Rear
        //7A  3 Air Antenna Select  0 = Front, 1 = Rear
        //7A  4 2 M Antenna Select  0 = Front, 1 = Rear
        //7A  5 UHF Antenna Select  0 = Front, 1 = Rear
        //7A  6 ? ?
        //7A  7 SPL On/Off  0 = Off, 1 = On

        CAT_BUFF[0] = (isSplitOn ? 0xFF : 0x7F);
        break;
        case 0xB3 : //
        CAT_BUFF[0] = 0x00;
        CAT_BUFF[1] = 0x4D;
        break;
        */
  }

  // sent the data
  SendCatData(2);
  Serial.write((byte)ACK);
}

//Read ADC Value by uBITX Manager Software
void ReadADCValue(void)
{
  //ADC MAP for uBITX
  int readedADCValue;
  //5BYTES
  //CAT_BUFF[0] [1] [2] [3] [4] //4 COMMAND
  //0 READ ADDRESS
  //
  //MJH     The following was written much more elegantly originally using an array of pins and a simple loop to get the data.
  //        However, because R6 and R7 are NinaPins (i.e. assigned to the Nina co-processor) on RP Connect, there was no way
  //        I could figure out how to put a NinaPin in this array. Kept throwing a compile error...  Although, not elegant, an perhaps
  //        a maintenance issue that someone will face in the future, this at least works on all processors.
  //        Also note the pinMode(pin, INPUT_PULLUPS) that are required because some processors turn off the pullups after an analog read.

   switch(CAT_BUFF[0]){
          case 0:
              #ifdef USE_DIGITAL_ENCODER                   //MJH Analog pin not used eith digital encoders
                readedADCValue = 0;
              #else
                readedADCValue = analogRead(ENC_A);
                pinMode(ENC_A, INPUT_PULLUP);
              #endif
                break;
          case 1:
              #ifdef USE_DIGITAL_ENCODER                   //MJH Analog pin not used eith digital encoders
                readedADCValue = 0;
              #else
                readedADCValue = analogRead(ENC_B);
                pinMode(ENC_B, INPUT_PULLUP);
              #endif
                break;
          case 2:
              #ifdef USE_DIGITAL_ENCODER                   //MJH Analog pin not used eith digital encoders
                readedADCValue = 0;
              #else
                readedADCValue = analogRead(FBUTTON);
                pinMode(FBUTTON, INPUT_PULLUP);
              #endif
                break;
          case 3:
              #ifdef USE_DIGITAL_ENCODER                   //MJH Analog pin not used eith digital encoders
                readedADCValue = 0;
              #else
                readedADCValue = analogRead(PTT);
                pinMode(PTT,INPUT_PULLUP); 
              #endif
                break;
          case 6:
                readedADCValue = analogRead(ANALOG_KEYER);
                pinMode(ANALOG_KEYER,INPUT_PULLUP);
                break;
          case 7:
                readedADCValue = analogRead(ANALOG_SMETER);
                pinMode(ANALOG_SMETER,INPUT_PULLUP);
                break;
          default:        //mjh Should never be reached....
                readedADCValue = 0;
          }

  CAT_BUFF[0] = readedADCValue >> 8;
  CAT_BUFF[1] = readedADCValue;
  SendCatData(2);
  Serial.write((byte)ACK);
}

void ReadVFO(unsigned long freq)
{
  CAT_BUFF[0] =  (byte)(freq & 0xff);                    //convert vfo value to bytes
  CAT_BUFF[1] = (byte)((freq >> 8 ) &0xff);
  CAT_BUFF[2] = (byte)((freq >> 16 ) &0xff);
  CAT_BUFF[3] = (byte)((freq >> 24 ) &0xff);
  
  SendCatData(4);                                     //Send these 4 bytes

}

void ReadCalValues(void)          //Read and return Calibration values (Master, SSBBFO, CWBFO)
{
  CAT_BUFF[0] = (byte)(calibration & 0xff);                    //convert master calibration value to bytes
  CAT_BUFF[1] = (byte)((calibration >> 8 ) &0xff);
  CAT_BUFF[2] = (byte)((calibration >> 16 ) &0xff);
  CAT_BUFF[3] = (byte)((calibration >> 24 ) &0xff);
  
  SendCatData(4);                                     //Send these 4 bytes

  CAT_BUFF[0] = (byte)(usbCarrier & 0xff);                     //convert SSB BFO calibration value to bytes
  CAT_BUFF[1] = (byte)((usbCarrier >> 8 ) &0xff);
  CAT_BUFF[2] = (byte)((usbCarrier >> 16 ) &0xff);
  CAT_BUFF[3] = (byte)((usbCarrier >> 24 ) &0xff);

  SendCatData(4);                                     //Send these 4 bytes

  CAT_BUFF[0] = (byte)(cwmCarrier & 0xff);                     //convert CW BFO calibration value to bytes
  CAT_BUFF[1] = (byte)((cwmCarrier >> 8 ) &0xff);
  CAT_BUFF[2] = (byte)((cwmCarrier >> 16 ) &0xff);
  CAT_BUFF[3] = (byte)((cwmCarrier >> 24 ) &0xff);

  SendCatData(4);                                     //Send these 4 bytes

  Serial.write((byte)ACK);                            //End with an ACK

  return;
} 

void WriteMasterCalToMemory(){       //Update in memory Master Calibration values 
// long casting required to be done in this way to support 16 bit processors like the Nano
// Also had to use "+" instead of "||" to make it work on teensy (32 bit) go figure...
  calibration = (long)CAT_BUFF[0]  + ((long)CAT_BUFF[1]  << 8 ) + ((long)CAT_BUFF[2] << 16 ) + ((long)CAT_BUFF[3] << 24 );
  si5351_set_calibration(calibration);
  setFrequency(frequency); 

}

void WriteSSBBFOToMemory()  {       //Update in memory SSBBFO value
// 
  usbCarrier = (long)CAT_BUFF[0]  + ((long)CAT_BUFF[1]  << 8 ) + ((long)CAT_BUFF[2] << 16 ) + ((long)CAT_BUFF[3] << 24 );
  SetCarrierFreq();
  setFrequency(frequency);
}

void WriteCWBFOToMemory()   {       //Update in memory CWBFO value
  cwmCarrier = (long)CAT_BUFF[0]  + ((long)CAT_BUFF[1]  << 8 ) + ((long)CAT_BUFF[2] << 16 ) + ((long)CAT_BUFF[3] << 24 );
  SetCarrierFreq();
  setFrequency(frequency);
} 


void StoreCalToEEPROM(void)                 //stores current calibration values to EEPROM
{
  EEPROMTYPE.put(MASTER_CAL, calibration);
  EEPROMTYPE.put(CW_CAL, cwmCarrier);
  EEPROMTYPE.put(USB_CAL, usbCarrier);
}  


void SetIFSValue(void)
{
  //Set IFShift Value
  isIFShift = CAT_BUFF[0];
  ifShiftValue = CAT_BUFF[1] + CAT_BUFF[2] * 256;
  setFrequency(frequency);
  SetCarrierFreq();
  updateLine2Buffer(1); //option, perhap not need
  Serial.write((byte)ACK);
}

//void CatRxStatus(byte fromType) 
void CatRxStatus(void)  //for remove warning
{
  byte sMeterValue = 0;

  /*
    http://www.ka7oei.com/ft817_meow.html
    Command E7 - Read Receiver Status:  This command returns one byte.  Its contents are valid only when the '817 is in receive mode and it should be ignored when transmitting.
    The lower 4 bits (0-3) of this byte indicate the current S-meter reading.  00 refers to an S-Zero reading, 04 = S4, 09 = S9, 0A = "10 over," 0B = "20 over" and so on up to 0F.
    Bit 4  contains no useful information.
    Bit 5 is 0 in non-FM modes, and it is 0 if the discriminator is centered (within 3.5 kHz for standard FM) when in the FM, FMN, or PKT modes, and 1 if the receiver is off-frequency.
    Bit 6 is 0 if the CTCSS or DCS is turned off (or in a mode where it is not available.)  It is also 0 if there is a signal being receive and the correct CTCSS tone or DCS code is being decoded.
    It is 1 if there is a signal and the CTCSS/DCS decoding is enable, but the wrong CTCSS tone, DCS code, or no CTCSS/DCS is present.
    Bit 7 is 0 if there is a signal present, or 1 if the receiver is squelched.
  */
  // The lower 4 bits (0-3) of this byte indicate the current S-meter reading.  00 refers to an S-Zero reading, 04 = S4, 09 = S9, 0A = "10 over," 0B = "20 over" and so on up to 0F.
  //0~8
  switch (scaledSMeter)
  {
  case 8 : sMeterValue = 0x0B;
    break;
  case 7 : sMeterValue = 0x0A;
    break;
  case 6 : sMeterValue = 0x09;
    break;
  case 5 : sMeterValue = 0x07;
    break;
  case 4 : sMeterValue = 0x05;
    break;
  case 3 : sMeterValue = 0x04;
    break;
  case 2 : sMeterValue = 0x02;
    break;
  case 1 : sMeterValue = 0x01;
    break;
  }

/*
  sMeterValue = (scaledSMeter * 2) -1;
  if (sMeterValue > 0)
    sMeterValue--;
*/    
   
  CAT_BUFF[0] = sMeterValue & 0b00001111;
  SendCatData(1);
}


//void CatTxStatus(byte fromType)
void CatTxStatus(void)  //for remove warning
{
  boolean isHighSWR = false;
  boolean isSplitOn = false;
  
  /*
    Inverted -> *ptt = ((p->tx_status & 0x80) == 0); <-- souce code in ft817.c (hamlib)
  */
  CAT_BUFF[0] = ((inTx ? 0 : 1) << 7) +
          ((isHighSWR ? 1 : 0) << 6) +  //hi swr off / on
          ((isSplitOn ? 1 : 0) << 5) + //Split on / off
          (0 << 4) +  //dummy data
          0x08;  //P0 meter data

  SendCatData(1);
}

unsigned long rxBufferArriveTime = 0;
byte rxBufferCheckCount = 0;

//Prevent Stack Overflow
byte isProcessCheck_Cat = 0;

//fromType normal : 0, TX : 1, CW_STRAIGHT : 2, CW_PADDLE : 3, CW_AUTOMODE : 4
//if cw mode, no delay
void Check_Cat(byte fromType)
{
  byte i;

  //Check Serial Port Buffer
  if (Serial.available() == 0) 
  {
    //Set Buffer Clear status
    rxBufferCheckCount = 0;
    return;
  }
  else if (Serial.available() < 5)
  {
    //First Arrived
    if (rxBufferCheckCount == 0)
    {
      rxBufferCheckCount = Serial.available();
      rxBufferArriveTime = millis() + CAT_RECEIVE_TIMEOUT;  //Set time for timeout
    }
    else if (rxBufferArriveTime < millis()) //timeout
    {
      //Clear Buffer
      for (i = 0; i < Serial.available(); i++)
        rxBufferCheckCount = Serial.read();

       rxBufferCheckCount = 0;
    }
    else if (rxBufferCheckCount < Serial.available()) //increase buffer count, slow arrived
    {
      rxBufferCheckCount = Serial.available();
      rxBufferArriveTime = millis() + CAT_RECEIVE_TIMEOUT;  //Set time for timeout
    }
    return;
  }

  //Arived CAT DATA
  for (i = 0; i < 5; i++)
    CAT_BUFF[i] = Serial.read();

  if (isProcessCheck_Cat == 1)
    return;

  isProcessCheck_Cat = 1;

  //reference : http://www.ka7oei.com/ft817_meow.html
 

  switch(CAT_BUFF[4])
  {
      //The stability has not been verified and there seems to be no need. so i remarked codes,
      //if you need, unmark lines
    /*
      case 0x00 :   //Lock On
        if (isDialLock == 1)  //This command returns 00 if it was unlocked, and F0 if already locked.
          CAT_BUFF[0] = 0xF0; 
        else {
          CAT_BUFF[0] = 0x00; 
          setDialLock(1, fromType);
        }
        Serial.write((byte)CAT_BUFF[0]);  //Time 
        break;
      case 0x80 :   //Lock Off
        if (isDialLock == 0)  //This command returns 00 if the '817 was already locked, and F0 (HEX) if already unlocked.
          CAT_BUFF[0] = 0xF0; 
        else {
          CAT_BUFF[0] = 0x00; 
          setDialLock(0, fromType);
        }
        Serial.write((byte)CAT_BUFF[0]);  //Time 
        break;
     */

    case 0x01 :   //Set Frequency
      CatSetFreq(fromType);
      break;
      
    case 0x02 : //Split On
    case 0x82:  //Split Off
      CatSetSplit(CAT_BUFF[4] == 0x02);
      break;

    case 0x03 :   //Read Frequency and mode
      CatGetFreqMode(frequency);
      break;

    case 0x07 :   //Set Operating  Mode
      CatSetMode(CAT_BUFF[0], fromType);
      break;

    case 0x08 : //Set PTT_ON
    case 0x88:  //Set PTT Off
      CatSetPTT(CAT_BUFF[4] == 0x08, fromType);
      break;

    case 0x81:  //Toggle VFO
      CatVFOToggle(true, fromType);
      break;

    case 0xDB:  //Read uBITX EEPROM Data
      ReadEEPRom(); //Call by uBITX Manager Program
      break;
      
    case 0xBB:  //Read FT-817 EEPROM Data  (for comfirtable)
      ReadEEPRom_FT817();
      break;

    case 0xBC:  //Write FT-817 EEPROM Data  (for comfirtable)
      WriteEEPRom_FT817(fromType);
      break;

    // MJH New CAT commands added here
    case 0xC0:
      ReadCalValues();          //Read and return Calibration values (Master, SSBBFO, CWBFO)
      break;

    case 0xC1:
      WriteMasterCalToMemory();         //Update in memory Calibration values (Master, SSBBFO, CWBFO)
      break;

    case 0xC2:
      WriteSSBBFOToMemory();         //Update in memory Calibration values (Master, SSBBFO, CWBFO)
      break;

    case 0xC3:
      WriteCWBFOToMemory();         //Update in memory Calibration values (Master, SSBBFO, CWBFO)
      break;

    case 0xC4:
      StoreCalToEEPROM();            //Update EEPROM Calibration values (Master, SSBBFO, CWBFO)
      break;

    case 0xC5:
      ReadVFO(frequency);                    //Return current frequency to HZ
      break;

    case 0xDD:          //Added by MJH to communicate with Settings Manager calibration      
      ReadADCValue();           //Read and return ADC Value
      break;

    case 0xDF:          //Get EEPROM size
      GetEEPRomSize();
      break; 
    // End added CAT commands


    case 0xDC:  //Write uBITX EEPROM Data
      WriteEEPRom(); //Call by uBITX Manager Program
      break;

    case 0xDE:          //IF-Shift Control by CAT
      SetIFSValue();   //
      break;
     
    case 0xE7 :       //Read RX Status
      CatRxStatus();
      break;
    case 0xF7:      //Read TX Status
      CatTxStatus();
      break;
    default:
    /*
      char buff[16];
      sprintf(buff, "DEFAULT : %x", CAT_BUFF[4]);
      printLine2(buff);
    */
      Serial.write((byte)ACK);
      break;
  } //end of switch

  isProcessCheck_Cat = 0;
}

void Init_Cat(long baud, int portConfig)
{
  #ifndef TEENSY
    Serial.begin(baud, portConfig);
    Serial.flush();
  #endif
}
