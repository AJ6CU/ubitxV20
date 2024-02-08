// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.3.6
// Project name: ubitx_20_ux

#include "ui.h"

void ui_VFO_screen_init(void)
{
    ui_VFO = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_VFO, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_VFOTuningPanel = lv_obj_create(ui_VFO);
    lv_obj_set_width(ui_VFOTuningPanel, 320);
    lv_obj_set_height(ui_VFOTuningPanel, 240);
    lv_obj_set_align(ui_VFOTuningPanel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_VFOTuningPanel,
                      LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_radius(ui_VFOTuningPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_VFOTuningPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_VFOTuningPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_VFOTuningPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_VFOTuningPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_VFOTuningPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_VFOTuningPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_VFOTuningPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_VFOTuningPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VFOTitleLabel = lv_label_create(ui_VFOTuningPanel);
    lv_obj_set_height(ui_VFOTitleLabel, 30);
    lv_obj_set_width(ui_VFOTitleLabel, lv_pct(100));
    lv_obj_set_x(ui_VFOTitleLabel, -1);
    lv_obj_set_y(ui_VFOTitleLabel, -99);
    lv_obj_set_align(ui_VFOTitleLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_VFOTitleLabel, "Set VFO");
    lv_obj_set_style_text_color(ui_VFOTitleLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VFOTitleLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_VFOTitleLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VFOTitleLabel, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_VFOTitleLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_VFOTitleLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_VFOTitleLabel, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_VFOTitleLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImgButton1 = lv_imgbtn_create(ui_VFOTuningPanel);
    lv_imgbtn_set_src(ui_ImgButton1, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_homebutton_png, NULL);
    lv_obj_set_height(ui_ImgButton1, 28);
    lv_obj_set_width(ui_ImgButton1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_x(ui_ImgButton1, -140);
    lv_obj_set_y(ui_ImgButton1, -98);
    lv_obj_set_align(ui_ImgButton1, LV_ALIGN_CENTER);

    ui_Panel16 = lv_obj_create(ui_VFOTuningPanel);
    lv_obj_set_height(ui_Panel16, 133);
    lv_obj_set_width(ui_Panel16, lv_pct(100));
    lv_obj_set_x(ui_Panel16, 0);
    lv_obj_set_y(ui_Panel16, -6);
    lv_obj_set_align(ui_Panel16, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Panel16, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Panel16, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_Panel16, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel16, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel16, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Panel16, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_Panel16, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_Panel16, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Roller7 = lv_roller_create(ui_Panel16);
    lv_roller_set_options(ui_Roller7, "0\n1\n2\n3\n4\n5", LV_ROLLER_MODE_NORMAL);
    lv_obj_set_width(ui_Roller7, 31);
    lv_obj_set_height(ui_Roller7, lv_pct(100));
    lv_obj_set_align(ui_Roller7, LV_ALIGN_CENTER);
    lv_obj_set_style_text_color(ui_Roller7, lv_color_hex(0x080808), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Roller7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Roller7, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_font(ui_Roller7, &lv_font_montserrat_20, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Roller7, LV_BORDER_SIDE_NONE, LV_PART_SELECTED | LV_STATE_DEFAULT);

    ui_Roller6 = lv_roller_create(ui_Panel16);
    lv_roller_set_options(ui_Roller6, "0\n1\n2\n3\n4\n5\n6\n7\n8\n9", LV_ROLLER_MODE_NORMAL);
    lv_obj_set_height(ui_Roller6, lv_pct(100));
    lv_obj_set_flex_grow(ui_Roller6, 1);
    lv_obj_set_align(ui_Roller6, LV_ALIGN_CENTER);
    lv_obj_set_style_text_color(ui_Roller6, lv_color_hex(0x080808), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Roller6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Roller6, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label30 = lv_label_create(ui_Panel16);
    lv_obj_set_height(ui_Label30, lv_pct(100));
    lv_obj_set_width(ui_Label30, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_align(ui_Label30, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label30, ".");
    lv_obj_set_style_text_color(ui_Label30, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label30, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_decor(ui_Label30, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label30, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Label30, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Label30, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Label30, 25, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Label30, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Roller5 = lv_roller_create(ui_Panel16);
    lv_roller_set_options(ui_Roller5, "0\n1\n2\n3\n4\n5\n6\n7\n8\n9", LV_ROLLER_MODE_NORMAL);
    lv_obj_set_height(ui_Roller5, lv_pct(100));
    lv_obj_set_flex_grow(ui_Roller5, 1);
    lv_obj_set_align(ui_Roller5, LV_ALIGN_CENTER);
    lv_obj_set_style_text_color(ui_Roller5, lv_color_hex(0x080808), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Roller5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Roller5, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Roller4 = lv_roller_create(ui_Panel16);
    lv_roller_set_options(ui_Roller4, "0\n1\n2\n3\n4\n5\n6\n7\n8\n9", LV_ROLLER_MODE_NORMAL);
    lv_obj_set_height(ui_Roller4, lv_pct(100));
    lv_obj_set_flex_grow(ui_Roller4, 1);
    lv_obj_set_align(ui_Roller4, LV_ALIGN_CENTER);
    lv_obj_set_style_text_font(ui_Roller4, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Roller3 = lv_roller_create(ui_Panel16);
    lv_roller_set_options(ui_Roller3, "0\n1\n2\n3\n4\n5\n6\n7\n8\n9", LV_ROLLER_MODE_NORMAL);
    lv_obj_set_height(ui_Roller3, lv_pct(100));
    lv_obj_set_flex_grow(ui_Roller3, 1);
    lv_obj_set_align(ui_Roller3, LV_ALIGN_CENTER);
    lv_obj_set_style_text_font(ui_Roller3, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label29 = lv_label_create(ui_Panel16);
    lv_obj_set_height(ui_Label29, lv_pct(100));
    lv_obj_set_width(ui_Label29, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_align(ui_Label29, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label29, ".");
    lv_obj_set_style_text_color(ui_Label29, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label29, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_decor(ui_Label29, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label29, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Label29, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Label29, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Label29, 25, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Label29, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Roller2 = lv_roller_create(ui_Panel16);
    lv_roller_set_options(ui_Roller2, "0\n1\n2\n3\n4\n5\n6\n7\n8\n9", LV_ROLLER_MODE_NORMAL);
    lv_obj_set_height(ui_Roller2, lv_pct(100));
    lv_obj_set_flex_grow(ui_Roller2, 1);
    lv_obj_set_align(ui_Roller2, LV_ALIGN_CENTER);
    lv_obj_set_style_text_font(ui_Roller2, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Roller1 = lv_roller_create(ui_Panel16);
    lv_roller_set_options(ui_Roller1, "0\n1\n2\n3\n4\n5\n6\n7\n8\n9", LV_ROLLER_MODE_NORMAL);
    lv_obj_set_height(ui_Roller1, lv_pct(100));
    lv_obj_set_flex_grow(ui_Roller1, 1);
    lv_obj_set_align(ui_Roller1, LV_ALIGN_CENTER);
    lv_obj_set_style_text_font(ui_Roller1, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Roller0 = lv_roller_create(ui_Panel16);
    lv_roller_set_options(ui_Roller0, "0", LV_ROLLER_MODE_NORMAL);
    lv_obj_set_height(ui_Roller0, lv_pct(100));
    lv_obj_set_flex_grow(ui_Roller0, 1);
    lv_obj_set_align(ui_Roller0, LV_ALIGN_CENTER);
    lv_obj_set_style_text_font(ui_Roller0, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VFOmodeSelectButton = lv_btn_create(ui_VFOTuningPanel);
    lv_obj_set_width(ui_VFOmodeSelectButton, 50);
    lv_obj_set_height(ui_VFOmodeSelectButton, 30);
    lv_obj_set_x(ui_VFOmodeSelectButton, 10);
    lv_obj_set_y(ui_VFOmodeSelectButton, 191);
    lv_obj_add_flag(ui_VFOmodeSelectButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_VFOmodeSelectButton,
                      LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE);     /// Flags
    lv_obj_set_style_pad_left(ui_VFOmodeSelectButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_VFOmodeSelectButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_VFOmodeSelectButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_VFOmodeSelectButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_VFOmodeSelectButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_VFOmodeSelectButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VFOmodeSelectLabel = lv_label_create(ui_VFOmodeSelectButton);
    lv_obj_set_width(ui_VFOmodeSelectLabel, lv_pct(100));
    lv_obj_set_height(ui_VFOmodeSelectLabel, lv_pct(100));
    lv_obj_set_x(ui_VFOmodeSelectLabel, 0);
    lv_obj_set_y(ui_VFOmodeSelectLabel, -1);
    lv_obj_set_align(ui_VFOmodeSelectLabel, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_VFOmodeSelectLabel, LV_LABEL_LONG_CLIP);
    lv_label_set_text(ui_VFOmodeSelectLabel, "LSB");
    lv_obj_set_style_text_align(ui_VFOmodeSelectLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VFOmodeSelectLabel, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_VFOmodeSelectLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_VFOmodeSelectLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_VFOmodeSelectLabel, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_VFOmodeSelectLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_VFOmodeSelectLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_VFOmodeSelectLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VFOmodeSelectPanel = lv_obj_create(ui_VFOTuningPanel);
    lv_obj_set_width(ui_VFOmodeSelectPanel, 205);
    lv_obj_set_height(ui_VFOmodeSelectPanel, 30);
    lv_obj_set_x(ui_VFOmodeSelectPanel, 15);
    lv_obj_set_y(ui_VFOmodeSelectPanel, 88);
    lv_obj_set_align(ui_VFOmodeSelectPanel, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_VFOmodeSelectPanel, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_VFOmodeSelectPanel, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_add_flag(ui_VFOmodeSelectPanel, LV_OBJ_FLAG_IGNORE_LAYOUT);     /// Flags
    lv_obj_clear_flag(ui_VFOmodeSelectPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_VFOmodeSelectPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_VFOmodeSelectPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_VFOmodeSelectPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_VFOmodeSelectPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_VFOmodeSelectPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_VFOmodeSelectPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_VFOmodeSelectPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_VFOmodeSelectPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_VFOmodeSelectPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_VFOmodeSelectPanel, 4, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VFOLSBModeButton = lv_btn_create(ui_VFOmodeSelectPanel);
    lv_obj_set_height(ui_VFOLSBModeButton, lv_pct(100));
    lv_obj_set_flex_grow(ui_VFOLSBModeButton, 1);
    lv_obj_add_flag(ui_VFOLSBModeButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_VFOLSBModeButton,
                      LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE);     /// Flags

    ui_VFOLSBModeLabel = lv_label_create(ui_VFOLSBModeButton);
    lv_obj_set_width(ui_VFOLSBModeLabel, 32);
    lv_obj_set_height(ui_VFOLSBModeLabel, lv_pct(100));
    lv_obj_set_align(ui_VFOLSBModeLabel, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_VFOLSBModeLabel, LV_LABEL_LONG_CLIP);
    lv_label_set_text(ui_VFOLSBModeLabel, "LSB");
    lv_obj_set_style_text_align(ui_VFOLSBModeLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VFOLSBModeLabel, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VFOUSBModeButton = lv_btn_create(ui_VFOmodeSelectPanel);
    lv_obj_set_height(ui_VFOUSBModeButton, lv_pct(100));
    lv_obj_set_flex_grow(ui_VFOUSBModeButton, 1);
    lv_obj_add_flag(ui_VFOUSBModeButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_VFOUSBModeButton,
                      LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE);     /// Flags

    ui_VFOUSBModeLabel = lv_label_create(ui_VFOUSBModeButton);
    lv_obj_set_width(ui_VFOUSBModeLabel, 32);
    lv_obj_set_height(ui_VFOUSBModeLabel, lv_pct(100));
    lv_obj_set_align(ui_VFOUSBModeLabel, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_VFOUSBModeLabel, LV_LABEL_LONG_CLIP);
    lv_label_set_text(ui_VFOUSBModeLabel, "USB");
    lv_obj_set_style_text_align(ui_VFOUSBModeLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VFOUSBModeLabel, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VFOCWLModeButton = lv_btn_create(ui_VFOmodeSelectPanel);
    lv_obj_set_height(ui_VFOCWLModeButton, lv_pct(100));
    lv_obj_set_flex_grow(ui_VFOCWLModeButton, 1);
    lv_obj_add_flag(ui_VFOCWLModeButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_VFOCWLModeButton,
                      LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE);     /// Flags

    ui_VFOCWLModeLabel = lv_label_create(ui_VFOCWLModeButton);
    lv_obj_set_width(ui_VFOCWLModeLabel, 32);
    lv_obj_set_height(ui_VFOCWLModeLabel, lv_pct(100));
    lv_obj_set_align(ui_VFOCWLModeLabel, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_VFOCWLModeLabel, LV_LABEL_LONG_CLIP);
    lv_label_set_text(ui_VFOCWLModeLabel, "CWL");
    lv_obj_set_style_text_align(ui_VFOCWLModeLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VFOCWLModeLabel, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VFOCWUModeButton = lv_btn_create(ui_VFOmodeSelectPanel);
    lv_obj_set_height(ui_VFOCWUModeButton, lv_pct(100));
    lv_obj_set_flex_grow(ui_VFOCWUModeButton, 1);
    lv_obj_add_flag(ui_VFOCWUModeButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_VFOCWUModeButton,
                      LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE);     /// Flags

    ui_VFOCWUModeLabel = lv_label_create(ui_VFOCWUModeButton);
    lv_obj_set_width(ui_VFOCWUModeLabel, 32);
    lv_obj_set_height(ui_VFOCWUModeLabel, lv_pct(100));
    lv_obj_set_align(ui_VFOCWUModeLabel, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_VFOCWUModeLabel, LV_LABEL_LONG_CLIP);
    lv_label_set_text(ui_VFOCWUModeLabel, "CWU");
    lv_obj_set_style_text_align(ui_VFOCWUModeLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VFOCWUModeLabel, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_ImgButton1, ui_event_ImgButton1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Roller7, ui_event_Roller7, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Roller6, ui_event_Roller6, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Roller5, ui_event_Roller5, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Roller4, ui_event_Roller4, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Roller3, ui_event_Roller3, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Roller2, ui_event_Roller2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Roller1, ui_event_Roller1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_VFOmodeSelectButton, ui_event_VFOmodeSelectButton, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_VFOLSBModeButton, ui_event_VFOLSBModeButton, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_VFOUSBModeButton, ui_event_VFOUSBModeButton, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_VFOCWLModeButton, ui_event_VFOCWLModeButton, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_VFOCWUModeButton, ui_event_VFOCWUModeButton, LV_EVENT_ALL, NULL);

}
