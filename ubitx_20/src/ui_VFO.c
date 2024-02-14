// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.3.6
// Project name: ubitx_20_ux

#include "ui.h"

void ui_VFO_screen_init(void)
{
    ui_VFO = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_VFO, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_VFOTuningPanel1 = lv_obj_create(ui_VFO);
    lv_obj_set_width(ui_VFOTuningPanel1, 320);
    lv_obj_set_height(ui_VFOTuningPanel1, 240);
    lv_obj_set_align(ui_VFOTuningPanel1, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_VFOTuningPanel1, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_VFOTuningPanel1, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_VFOTuningPanel1,
                      LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_radius(ui_VFOTuningPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_VFOTuningPanel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_VFOTuningPanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_VFOTuningPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_VFOTuningPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_VFOTuningPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_VFOTuningPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_VFOTuningPanel1, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_VFOTuningPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel4 = lv_obj_create(ui_VFOTuningPanel1);
    lv_obj_set_height(ui_Panel4, 24);
    lv_obj_set_width(ui_Panel4, lv_pct(100));
    lv_obj_set_align(ui_Panel4, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Panel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel4, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Panel4, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VFOTitleLabel1 = lv_label_create(ui_Panel4);
    lv_obj_set_height(ui_VFOTitleLabel1, 30);
    lv_obj_set_width(ui_VFOTitleLabel1, lv_pct(75));
    lv_obj_set_x(ui_VFOTitleLabel1, -1);
    lv_obj_set_y(ui_VFOTitleLabel1, 0);
    lv_obj_set_align(ui_VFOTitleLabel1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_VFOTitleLabel1, "VFO");
    lv_obj_set_style_text_color(ui_VFOTitleLabel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VFOTitleLabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_VFOTitleLabel1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VFOTitleLabel1, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_VFOTitleLabel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_VFOTitleLabel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_VFOTitleLabel1, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_VFOTitleLabel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Container2 = lv_obj_create(ui_VFOTuningPanel1);
    lv_obj_remove_style_all(ui_Container2);
    lv_obj_set_height(ui_Container2, 50);
    lv_obj_set_width(ui_Container2, lv_pct(100));
    lv_obj_set_x(ui_Container2, 0);
    lv_obj_set_y(ui_Container2, 52);
    lv_obj_set_align(ui_Container2, LV_ALIGN_TOP_RIGHT);
    lv_obj_set_flex_flow(ui_Container2, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container2, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_Container2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_left(ui_Container2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Container2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Container2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Container2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_Container2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_Container2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_pad_left(ui_Container2, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Container2, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Container2, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Container2, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_Container2, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_Container2, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    ui_Button2 = lv_btn_create(ui_Container2);
    lv_obj_set_width(ui_Button2, 30);
    lv_obj_set_height(ui_Button2, 34);
    lv_obj_set_x(ui_Button2, -139);
    lv_obj_set_y(ui_Button2, -49);
    lv_obj_set_align(ui_Button2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_left(ui_Button2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Button2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Button2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Button2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_Button2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_Button2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Button2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Button2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Button2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label3 = lv_label_create(ui_Button2);
    lv_obj_set_width(ui_Label3, 30);
    lv_obj_set_height(ui_Label3, 23);
    lv_obj_set_x(ui_Label3, 0);
    lv_obj_set_y(ui_Label3, -10);
    lv_obj_set_align(ui_Label3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label3, "-");
    lv_obj_set_style_text_color(ui_Label3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label3, &ui_font_RobertoMonoRegular44, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Label3, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Label3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Label3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Label3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Label3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_Label3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_Label3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_vfoSpinBox = lv_spinbox_create(ui_Container2);
    lv_obj_set_width(ui_vfoSpinBox, 226);
    lv_obj_set_height(ui_vfoSpinBox, 54);
    lv_obj_set_x(ui_vfoSpinBox, 9);
    lv_obj_set_y(ui_vfoSpinBox, 6);
    lv_obj_set_align(ui_vfoSpinBox, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_vfoSpinBox, LV_OBJ_FLAG_SCROLL_WITH_ARROW);     /// Flags
    lv_spinbox_set_digit_format(ui_vfoSpinBox, 7, 0);
    lv_spinbox_set_range(ui_vfoSpinBox, 0, 9000000);
    lv_spinbox_set_step(ui_vfoSpinBox, round(pow(10, 1 - 1)));
    lv_obj_set_style_radius(ui_vfoSpinBox, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_vfoSpinBox, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_vfoSpinBox, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_vfoSpinBox, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_vfoSpinBox, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_vfoSpinBox, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_vfoSpinBox, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_vfoSpinBox, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_vfoSpinBox, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_vfoSpinBox, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_vfoSpinBox, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_vfoSpinBox, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_vfoSpinBox, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_vfoSpinBox, &ui_font_RobertoMonoRegular44, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_border_side(ui_vfoSpinBox, LV_BORDER_SIDE_NONE, LV_PART_CURSOR | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_vfoSpinBox, &ui_font_RobertoMonoRegular44, LV_PART_CURSOR | LV_STATE_DEFAULT);

    ui_vfo0Digit = lv_label_create(ui_vfoSpinBox);
    lv_obj_set_width(ui_vfo0Digit, 30);
    lv_obj_set_height(ui_vfo0Digit, 40);
    lv_obj_set_x(ui_vfo0Digit, 93);
    lv_obj_set_y(ui_vfo0Digit, -5);
    lv_obj_set_align(ui_vfo0Digit, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_vfo0Digit, LV_LABEL_LONG_CLIP);
    lv_label_set_text(ui_vfo0Digit, "0");
    lv_obj_set_scrollbar_mode(ui_vfo0Digit, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_text_color(ui_vfo0Digit, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_vfo0Digit, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_vfo0Digit, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_vfo0Digit, &ui_font_RobertoMonoRegular44, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_vfo0Digit, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_vfo0Digit, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_vfo0Digit, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_vfo0Digit, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_vfo0Digit, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_vfo0Digit, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_vfo0Digit, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_vfo0Digit, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_decimal1 = lv_label_create(ui_vfoSpinBox);
    lv_obj_set_width(ui_decimal1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_decimal1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_decimal1, 22);
    lv_obj_set_y(ui_decimal1, 0);
    lv_obj_set_align(ui_decimal1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_decimal1, ".");
    lv_obj_add_flag(ui_decimal1, LV_OBJ_FLAG_IGNORE_LAYOUT);     /// Flags
    lv_obj_set_style_text_font(ui_decimal1, &ui_font_RobertoMonoRegular44, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_decimal2 = lv_label_create(ui_vfoSpinBox);
    lv_obj_set_width(ui_decimal2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_decimal2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_decimal2, -55);
    lv_obj_set_y(ui_decimal2, 0);
    lv_obj_set_align(ui_decimal2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_decimal2, ".");
    lv_obj_add_flag(ui_decimal2, LV_OBJ_FLAG_IGNORE_LAYOUT);     /// Flags
    lv_obj_set_style_text_font(ui_decimal2, &ui_font_RobertoMonoRegular44, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button3 = lv_btn_create(ui_Container2);
    lv_obj_set_width(ui_Button3, 30);
    lv_obj_set_height(ui_Button3, 33);
    lv_obj_set_x(ui_Button3, 135);
    lv_obj_set_y(ui_Button3, -37);
    lv_obj_set_align(ui_Button3, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button3, lv_color_hex(0x2095F6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Button3, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Button3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Button3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Button3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Button3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_Button3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_Button3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Button3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Button3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Button3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label8 = lv_label_create(ui_Button3);
    lv_obj_set_width(ui_Label8, 30);
    lv_obj_set_height(ui_Label8, 24);
    lv_obj_set_x(ui_Label8, 0);
    lv_obj_set_y(ui_Label8, -9);
    lv_obj_set_align(ui_Label8, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label8, "+");
    lv_obj_set_style_text_color(ui_Label8, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label8, &ui_font_RobertoMonoRegular44, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Label8, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Label8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Label8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Label8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Label8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_Label8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_Label8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel5 = lv_obj_create(ui_VFOTuningPanel1);
    lv_obj_set_height(ui_Panel5, 36);
    lv_obj_set_width(ui_Panel5, lv_pct(100));
    lv_obj_set_align(ui_Panel5, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Panel5, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Panel5, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_Panel5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Panel5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel5, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Panel5, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Panel5, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Panel5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Panel5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Panel5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_Panel5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_Panel5, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VFOmodeSelectButton1 = lv_btn_create(ui_Panel5);
    lv_obj_set_width(ui_VFOmodeSelectButton1, 50);
    lv_obj_set_height(ui_VFOmodeSelectButton1, 28);
    lv_obj_set_x(ui_VFOmodeSelectButton1, 20);
    lv_obj_set_y(ui_VFOmodeSelectButton1, 44);
    lv_obj_add_flag(ui_VFOmodeSelectButton1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_VFOmodeSelectButton1,
                      LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE);     /// Flags
    lv_obj_set_style_pad_left(ui_VFOmodeSelectButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_VFOmodeSelectButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_VFOmodeSelectButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_VFOmodeSelectButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_VFOmodeSelectButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_VFOmodeSelectButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VFOmodeSelectLabel = lv_label_create(ui_VFOmodeSelectButton1);
    lv_obj_set_width(ui_VFOmodeSelectLabel, lv_pct(100));
    lv_obj_set_height(ui_VFOmodeSelectLabel, lv_pct(100));
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

    ui_storeButton = lv_btn_create(ui_Panel5);
    lv_obj_set_width(ui_storeButton, 55);
    lv_obj_set_height(ui_storeButton, 28);
    lv_obj_set_x(ui_storeButton, 124);
    lv_obj_set_y(ui_storeButton, -31);
    lv_obj_set_align(ui_storeButton, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_storeButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_storeButton, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_side(ui_storeButton, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label6 = lv_label_create(ui_storeButton);
    lv_obj_set_width(ui_Label6, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label6, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label6, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label6, "STORE");
    lv_obj_set_style_text_font(ui_Label6, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button4 = lv_btn_create(ui_Panel5);
    lv_obj_set_width(ui_Button4, 55);
    lv_obj_set_height(ui_Button4, 28);
    lv_obj_set_x(ui_Button4, 125);
    lv_obj_set_y(ui_Button4, 13);
    lv_obj_set_align(ui_Button4, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button4, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_side(ui_Button4, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_recallButton = lv_label_create(ui_Button4);
    lv_obj_set_width(ui_recallButton, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_recallButton, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_recallButton, LV_ALIGN_CENTER);
    lv_label_set_text(ui_recallButton, "RECALL");
    lv_obj_set_style_text_font(ui_recallButton, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_QSYButton = lv_btn_create(ui_Panel5);
    lv_obj_set_width(ui_QSYButton, 55);
    lv_obj_set_height(ui_QSYButton, 28);
    lv_obj_set_x(ui_QSYButton, 130);
    lv_obj_set_y(ui_QSYButton, 13);
    lv_obj_set_align(ui_QSYButton, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_QSYButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_QSYButton, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_side(ui_QSYButton, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_QSYLabel = lv_label_create(ui_QSYButton);
    lv_obj_set_width(ui_QSYLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_QSYLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_QSYLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_QSYLabel, "QSY");
    lv_obj_set_style_text_font(ui_QSYLabel, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_QSYLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_QSYLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_QSYLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_QSYLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_QSYLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_QSYLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel6 = lv_obj_create(ui_VFOTuningPanel1);
    lv_obj_set_height(ui_Panel6, 99);
    lv_obj_set_width(ui_Panel6, lv_pct(100));
    lv_obj_set_align(ui_Panel6, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Panel6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel6, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Panel6, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Panel6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Panel6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Panel6, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Panel6, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_Panel6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_Panel6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_border_side(ui_Panel6, LV_BORDER_SIDE_NONE, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    ui_memoryRoller = lv_roller_create(ui_Panel6);
    lv_roller_set_options(ui_memoryRoller, "CH-01	 7.032.000 CWL\nCH-02	 14.032.000 CWU\nCH-03	 7.025.000 CWL",
                          LV_ROLLER_MODE_INFINITE);
    lv_obj_set_height(ui_memoryRoller, 91);
    lv_obj_set_width(ui_memoryRoller, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_x(ui_memoryRoller, 18);
    lv_obj_set_y(ui_memoryRoller, -2);
    lv_obj_set_align(ui_memoryRoller, LV_ALIGN_CENTER);
    lv_obj_set_style_text_align(ui_memoryRoller, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_memoryRoller, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_memoryRoller, lv_color_hex(0x696969), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_memoryRoller, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_font(ui_memoryRoller, &lv_font_montserrat_20, LV_PART_SELECTED | LV_STATE_DEFAULT);

    ui_vfoModeSelectPanel = lv_obj_create(ui_VFOTuningPanel1);
    lv_obj_set_width(ui_vfoModeSelectPanel, 219);
    lv_obj_set_height(ui_vfoModeSelectPanel, 28);
    lv_obj_set_x(ui_vfoModeSelectPanel, 43);
    lv_obj_set_y(ui_vfoModeSelectPanel, 0);
    lv_obj_set_align(ui_vfoModeSelectPanel, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_vfoModeSelectPanel, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_vfoModeSelectPanel, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_add_flag(ui_vfoModeSelectPanel, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_IGNORE_LAYOUT);     /// Flags
    lv_obj_clear_flag(ui_vfoModeSelectPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_vfoModeSelectPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_vfoModeSelectPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_vfoModeSelectPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_vfoModeSelectPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_vfoModeSelectPanel, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_vfoModeSelectPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_vfoModeSelectPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_vfoModeSelectPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_vfoModeSelectPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_vfoModeSelectPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_vfoModeSelectPanel, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LSBModeButton1 = lv_btn_create(ui_vfoModeSelectPanel);
    lv_obj_set_height(ui_LSBModeButton1, 28);
    lv_obj_set_flex_grow(ui_LSBModeButton1, 1);
    lv_obj_add_flag(ui_LSBModeButton1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_LSBModeButton1,
                      LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE);     /// Flags
    lv_obj_set_style_border_side(ui_LSBModeButton1, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LSBModeButton1, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LSBModeLabel1 = lv_label_create(ui_LSBModeButton1);
    lv_obj_set_width(ui_LSBModeLabel1, 32);
    lv_obj_set_height(ui_LSBModeLabel1, lv_pct(100));
    lv_obj_set_align(ui_LSBModeLabel1, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_LSBModeLabel1, LV_LABEL_LONG_CLIP);
    lv_label_set_text(ui_LSBModeLabel1, "LSB");
    lv_obj_set_style_text_align(ui_LSBModeLabel1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LSBModeLabel1, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_USBModeButton1 = lv_btn_create(ui_vfoModeSelectPanel);
    lv_obj_set_height(ui_USBModeButton1, 28);
    lv_obj_set_flex_grow(ui_USBModeButton1, 1);
    lv_obj_add_flag(ui_USBModeButton1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_USBModeButton1,
                      LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE);     /// Flags
    lv_obj_set_style_border_side(ui_USBModeButton1, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_USBModeLabel1 = lv_label_create(ui_USBModeButton1);
    lv_obj_set_width(ui_USBModeLabel1, 32);
    lv_obj_set_height(ui_USBModeLabel1, lv_pct(100));
    lv_obj_set_x(ui_USBModeLabel1, 2);
    lv_obj_set_y(ui_USBModeLabel1, 0);
    lv_obj_set_align(ui_USBModeLabel1, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_USBModeLabel1, LV_LABEL_LONG_CLIP);
    lv_label_set_text(ui_USBModeLabel1, "USB");
    lv_obj_set_style_text_align(ui_USBModeLabel1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_USBModeLabel1, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CWLModeButton1 = lv_btn_create(ui_vfoModeSelectPanel);
    lv_obj_set_height(ui_CWLModeButton1, 28);
    lv_obj_set_flex_grow(ui_CWLModeButton1, 1);
    lv_obj_add_flag(ui_CWLModeButton1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_CWLModeButton1,
                      LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE);     /// Flags
    lv_obj_set_style_border_side(ui_CWLModeButton1, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CWLModeLabel1 = lv_label_create(ui_CWLModeButton1);
    lv_obj_set_width(ui_CWLModeLabel1, 32);
    lv_obj_set_height(ui_CWLModeLabel1, lv_pct(100));
    lv_obj_set_align(ui_CWLModeLabel1, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_CWLModeLabel1, LV_LABEL_LONG_CLIP);
    lv_label_set_text(ui_CWLModeLabel1, "CWL");
    lv_obj_set_style_text_align(ui_CWLModeLabel1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_CWLModeLabel1, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CWUModeButton1 = lv_btn_create(ui_vfoModeSelectPanel);
    lv_obj_set_height(ui_CWUModeButton1, 28);
    lv_obj_set_flex_grow(ui_CWUModeButton1, 1);
    lv_obj_add_flag(ui_CWUModeButton1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_CWUModeButton1,
                      LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE);     /// Flags
    lv_obj_set_style_border_side(ui_CWUModeButton1, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CWUModeLabel1 = lv_label_create(ui_CWUModeButton1);
    lv_obj_set_width(ui_CWUModeLabel1, 32);
    lv_obj_set_height(ui_CWUModeLabel1, lv_pct(100));
    lv_obj_set_align(ui_CWUModeLabel1, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_CWUModeLabel1, LV_LABEL_LONG_CLIP);
    lv_label_set_text(ui_CWUModeLabel1, "CWU");
    lv_obj_set_style_text_align(ui_CWUModeLabel1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_CWUModeLabel1, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_enterChannelNamePanel = lv_obj_create(ui_VFOTuningPanel1);
    lv_obj_set_height(ui_enterChannelNamePanel, 200);
    lv_obj_set_width(ui_enterChannelNamePanel, lv_pct(100));
    lv_obj_set_align(ui_enterChannelNamePanel, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_enterChannelNamePanel, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_enterChannelNamePanel, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);
    lv_obj_add_flag(ui_enterChannelNamePanel, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_IGNORE_LAYOUT);     /// Flags
    lv_obj_clear_flag(ui_enterChannelNamePanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_left(ui_enterChannelNamePanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_enterChannelNamePanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_enterChannelNamePanel, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_enterChannelNamePanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_enterChannelNamePanel, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_enterChannelNamePanel, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label9 = lv_label_create(ui_enterChannelNamePanel);
    lv_obj_set_width(ui_Label9, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label9, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label9, -141);
    lv_obj_set_y(ui_Label9, -70);
    lv_obj_set_align(ui_Label9, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label9, "Channel (5 chars max):");
    lv_obj_set_style_text_font(ui_Label9, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Label9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Label9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Label9, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Label9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_Label9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_Label9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_newChannelTextarea = lv_textarea_create(ui_enterChannelNamePanel);
    lv_obj_set_width(ui_newChannelTextarea, 67);
    lv_obj_set_height(ui_newChannelTextarea, LV_SIZE_CONTENT);    /// 20
    lv_obj_set_x(ui_newChannelTextarea, 0);
    lv_obj_set_y(ui_newChannelTextarea, 1);
    lv_obj_set_align(ui_newChannelTextarea, LV_ALIGN_CENTER);
    lv_textarea_set_max_length(ui_newChannelTextarea, 5);
    lv_textarea_set_one_line(ui_newChannelTextarea, true);
    lv_obj_set_style_text_font(ui_newChannelTextarea, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_newChannelTextarea, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_newChannelTextarea, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_newChannelTextarea, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_newChannelTextarea, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_newChannelTextarea, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_newChannelTextarea, 0, LV_PART_MAIN | LV_STATE_DEFAULT);



    ui_cancelMemStoreButton = lv_btn_create(ui_enterChannelNamePanel);
    lv_obj_set_width(ui_cancelMemStoreButton, 50);
    lv_obj_set_height(ui_cancelMemStoreButton, 25);
    lv_obj_set_x(ui_cancelMemStoreButton, 0);
    lv_obj_set_y(ui_cancelMemStoreButton, -4);
    lv_obj_set_align(ui_cancelMemStoreButton, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_cancelMemStoreButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_cancelMemStoreButton, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_cancelMemStoreButton, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_cancelMemStoreButton, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_cancelMemStoreButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_cancelMemStoreButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_cancelMemStoreButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_cancelMemStoreButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_cancelMemStoreButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_cancelMemStoreButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_cancelMemStoreButton, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label11 = lv_label_create(ui_cancelMemStoreButton);
    lv_obj_set_width(ui_Label11, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label11, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label11, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label11, "Cancel");

    ui_Keyboard1 = lv_keyboard_create(ui_enterChannelNamePanel);
    lv_keyboard_set_mode(ui_Keyboard1, LV_KEYBOARD_MODE_TEXT_UPPER);
    lv_obj_set_height(ui_Keyboard1, 150);
    lv_obj_set_width(ui_Keyboard1, lv_pct(100));
    lv_obj_set_align(ui_Keyboard1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Keyboard1, LV_OBJ_FLAG_FLEX_IN_NEW_TRACK);     /// Flags

    lv_obj_set_style_bg_color(ui_Keyboard1, lv_color_hex(0x2095F6), LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Keyboard1, 255, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Keyboard1, lv_color_hex(0xFFFFFF), LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Keyboard1, 255, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Keyboard1, &lv_font_montserrat_14, LV_PART_ITEMS | LV_STATE_DEFAULT);

    ui_ImgButton2 = lv_imgbtn_create(ui_VFOTuningPanel1);
    lv_imgbtn_set_src(ui_ImgButton2, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_homebutton_png, NULL);
    lv_obj_set_height(ui_ImgButton2, 28);
    lv_obj_set_width(ui_ImgButton2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_x(ui_ImgButton2, -140);
    lv_obj_set_y(ui_ImgButton2, 101);
    lv_obj_set_align(ui_ImgButton2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ImgButton2, LV_OBJ_FLAG_IGNORE_LAYOUT);     /// Flags
    lv_obj_set_style_radius(ui_ImgButton2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ImgButton2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ImgButton2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Button2, ui_event_Button2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_vfo0Digit, ui_event_vfo0Digit, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button3, ui_event_Button3, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_VFOmodeSelectButton1, ui_event_VFOmodeSelectButton1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_storeButton, ui_event_storeButton, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_QSYButton, ui_event_QSYButton, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_LSBModeButton1, ui_event_LSBModeButton1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_USBModeButton1, ui_event_USBModeButton1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_CWLModeButton1, ui_event_CWLModeButton1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_CWUModeButton1, ui_event_CWUModeButton1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_newChannelTextarea, ui_event_newChannelTextarea, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_cancelMemStoreButton, ui_event_cancelMemStoreButton, LV_EVENT_ALL, NULL);
    lv_keyboard_set_textarea(ui_Keyboard1, ui_newChannelTextarea);
    lv_obj_add_event_cb(ui_Keyboard1, ui_event_Keyboard1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_enterChannelNamePanel, ui_event_enterChannelNamePanel, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ImgButton2, ui_event_ImgButton2, LV_EVENT_ALL, NULL);

}
