#ifndef D_MENU_ITEM_H
#define D_MENU_ITEM_H

#include "dolphin/types.h"
#include "d/d_menu_base.h"
#include "f_op/f_op_msg_mng.h"
#include "m_Do/m_Do_hostIO.h"

class JKRArchive;
class JUTFont;
class J2DPane;
class J2DScreen;
class JPABaseEmitter;
class STControl;
class dDlst_2DOutFont_c;
class dMenu_save_c;

class dMenu_Item_c : public dMenu_base_c {
public:
    void alphaChange(fopMsgM_pane_class*, f32) {}
    virtual void draw() {_draw();}
    u8 getItemMode() { return mItemMode; }
    u8 getNowItem() { return mNowItem; }
    void setNowItem(u8 val) { mNowItem = val; }
    void setArchive(JKRArchive* arc) { mpArc = arc; }
    void setFont(JUTFont* font, JUTFont* rfont) {
        mFont = font;
        mRFont = rfont;
    }
    void setItemTexBuffer(int idx, void* buffer) { mItemTexBuffer[idx] = buffer; }
    void setSubItemTexBuffer(int idx, void* buffer) { mSubItemTexBuffer[idx] = buffer; }
    void setTextArea(char* name0, char* name1, char* note0, char* note1, char* dummy0, char* dummy1) {
        name[0] = name0;
        name[1] = name1;
        note[0] = note0;
        note[1] = note1;
        dummy[0] = dummy0;
        dummy[1] = dummy1;
    }
    void setTimer(s16 val) { mTimer = val; }
    void setTriggerInfo(u8 info) { mTriggerInfo = info; }

    void initialize();
    void screenSet();
    void cursorAnime();
    void cursorMainMove();
    void cursorSubMove();
    void checkMove();
    bool itemplaceCheck(int);
    void itemDecide();
    void itemMove();
    void itemScale();
    void subWindowInit();
    void subWindowDelete();
    void subItemDecide();
    void itemnameMove();
    void itemnameSet();
    void itemnoteSet();
    void outFontInit();
    void outFontMove();
    void outFontDraw();
    u8 noteCheck();
    void noteInit();
    void noteAppear();
    void noteOpen();
    void noteClose();
    void mainTrans(float, float);
    void titleTrans(float, float);
    void noteRotate(float, float);
    void nameTrans(float, float);
    void mainOpenProc(short, short, short);
    void titleOpenProc(short, short);
    void noteOpenProc(short, short);
    void nameOpenProc(short, short);
    void numberSet(J2DPane*, unsigned char);
    void numberColor(J2DPane*, unsigned char);
    void itemNumberSet();
    void itemCheck(int);
    void itemBitCheck(bool);
    void arrowLightAnime();
    void bottleFwaterCheck();
    void recollectBossCheck();
    void cornerMove();
    void equipBeastItem(int);
    virtual void _create();
    virtual void _delete();
    virtual void _move();
    virtual void _draw();
    virtual bool _open();
    virtual bool _close();
    bool _open2();
    bool _close2();

private:
    /* 0x0000 */ // vtable
    /* 0x0004 */ J2DScreen* mpScreen;             // "menu_item_02.blo"
    /* 0x0008 */ fopMsgM_pane_class m008;         // "ft15"
    /* 0x0040 */ fopMsgM_pane_class m040;         // "ft16"
    /* 0x0078 */ fopMsgM_pane_class m078;         // "ft17"
    /* 0x00B0 */ fopMsgM_pane_class m0B0[15];     // l_ft
    /* 0x03F8 */ fopMsgM_pane_class m3F8[15];     // l_fd
    /* 0x0740 */ fopMsgM_pane_class m740;         // "str0"
    /* 0x0778 */ fopMsgM_pane_class m778;         // "st00"
    /* 0x07B0 */ fopMsgM_pane_class m7B0;         // "nt00"
    /* 0x07E8 */ fopMsgM_pane_class m7E8;         // "nk00"
    /* 0x0820 */ fopMsgM_pane_class m820;         // "no11"
    /* 0x0858 */ fopMsgM_pane_class m858;         // "wd"
    /* 0x0890 */ fopMsgM_pane_class m890;         // "nm00"
    /* 0x08C8 */ fopMsgM_pane_class m8C8;         // "nm01"
    /* 0x0900 */ fopMsgM_pane_class m900;         // "itnm"
    /* 0x0938 */ fopMsgM_pane_class m938;         // "itnk"
    /* 0x0970 */ fopMsgM_pane_class m970;         // "msk0"
    /* 0x09A8 */ fopMsgM_pane_class m9A8;         // "lt00"
    /* 0x09E0 */ fopMsgM_pane_class m9E0;         // "tk00"
    /* 0x0A18 */ fopMsgM_pane_class mA18[4];      // l_car (cursors)
    /* 0x0AF8 */ fopMsgM_pane_class mAF8[8];      // l_sin_01
    /* 0x0CB8 */ fopMsgM_pane_class mCB8[8];      // l_sin_10
    /* 0x0E78 */ fopMsgM_pane_class mE78[8];      // l_sit
    /* 0x1038 */ fopMsgM_pane_class m1038;        // "it29"
    /* 0x1070 */ fopMsgM_pane_class m1070[8];     // l_sik
    /* 0x1230 */ fopMsgM_pane_class m1230;        // "ik29"
    /* 0x1268 */ fopMsgM_pane_class m1268[9];     // l_sb
    /* 0x1460 */ fopMsgM_pane_class m1460;        // "blak"
    /* 0x1498 */ fopMsgM_pane_class m1498;        // "wdsv"
    /* 0x14D0 */ fopMsgM_pane_class m14D0;        // "wk01" (J2DWindow)
    /* 0x1508 */ fopMsgM_pane_class m1508;        // "wk00" (J2DWindow)
    /* 0x1540 */ fopMsgM_pane_class m1540;        // "0301"
    /* 0x1578 */ fopMsgM_pane_class m1578;        // "1301"
    /* 0x15B0 */ fopMsgM_pane_class m15B0;        // "1310"
    /* 0x15E8 */ fopMsgM_pane_class m15E8;        // "1401"
    /* 0x1620 */ fopMsgM_pane_class m1620;        // "1410"
    /* 0x1658 */ fopMsgM_pane_class m1658[21];    // l_it (item icons)
    /* 0x1AF0 */ fopMsgM_pane_class m1AF0[21];    // l_ik
    /* 0x1F88 */ fopMsgM_pane_class m1F88;        // "bwl1"
    /* 0x1FC0 */ fopMsgM_pane_class m1FC0;        // "bwl2"
    /* 0x1FF8 */ fopMsgM_pane_class m1FF8;        // "bwl3"
    /* 0x2030 */ fopMsgM_pane_class m2030;        // "chk1"
    /* 0x2068 */ fopMsgM_pane_class m2068;        // "chk2"
    /* 0x20A0 */ fopMsgM_pane_class m20A0;        // "chk3"
    /* 0x20D8 */ fopMsgM_pane_class m20D8[6];     // l_ip
    /* 0x2228 */ fopMsgM_pane_class m2228;        // "cc35"
    /* 0x2260 */ fopMsgM_pane_class m2260;        // "cc22"
    /* 0x2298 */ fopMsgM_pane_class m2298;        // "cc11"
    /* 0x22D0 */ fopMsgM_pane_class m22D0;        // "cc00"
    /* 0x2308 */ STControl* mpStick;
    /* 0x230C */ dDlst_2DOutFont_c* mpOutFont;
    /* 0x2310 */ JKRArchive* mpArc;
    /* 0x2314 */ JUTFont* mFont;
    /* 0x2318 */ JUTFont* mRFont;
    /* 0x231C */ J2DPane* m2DPane;                // "ROOT"
    /* 0x2320 */ JUtility::TColor color_0x2320;
    /* 0x2324 */ JUtility::TColor color_0x2324;
    /* 0x2328 */ JUtility::TColor color_0x2328;
    /* 0x232C */ JUtility::TColor color_0x232C;
    /* 0x2330 */ dMenu_save_c* mpMenuSave;
    /* 0x2334 */ void* mItemTexBuffer[24];        // only [0..20] used
    /* 0x2394 */ void* mSubItemTexBuffer[9];
    /* 0x23B8 */ JPABaseEmitter* mpEmitter[2];
    /* 0x23C0 */ f32 m23C0[4];                    // cursor offset X
    /* 0x23D0 */ f32 m23D0[4];                    // cursor offset Y
    /* 0x23E0 */ char* name[2];
    /* 0x23E8 */ char* note[2];
    /* 0x23F0 */ char* dummy[2];
    /* 0x23F8 */ u16 mTimer;
    /* 0x23FA */ s16 m23FA[2];
    /* 0x23FE */ u8 mItemMode;
    /* 0x23FF */ u8 mNowItem;
    /* 0x2400 */ u8 m2400[0x21];                  // [0] page base item, [1] selected, [4] equip slot, [6..26] item ids
    /* 0x2421 */ u8 mTriggerInfo;
    /* 0x2422 */ u8 m2422;
    /* 0x2423 */ u8 m2423;
}; // Size: 0x2424

STATIC_ASSERT(sizeof(dMenu_Item_c) == 0x2424);

class dMi_HIO_c : public JORReflexible {
public:
    dMi_HIO_c();
    virtual ~dMi_HIO_c() {}

    void genMessage(JORMContext* ctx) {}

    static const int ARR_SIZE = 5;

public:
    /* 0x04 */ s8 mNo;
    /* 0x08 */ f32 field_0x08;
    /* 0x0C */ s16 field_0x0C;
    /* 0x0E */ s16 arr_0x0E[ARR_SIZE];
    /* 0x18 */ s16 field_0x18;
    /* 0x1A */ s16 arr_0x1A[ARR_SIZE];
    /* 0x24 */ s16 field_0x24;
    /* 0x26 */ s16 field_0x26;
    /* 0x28 */ s16 field_0x28;
    /* 0x2A */ s16 field_0x2A;
    /* 0x2C */ s16 field_0x2C;
    /* 0x2E */ s16 field_0x2E;
    /* 0x30 */ s16 field_0x30;
    /* 0x32 */ s16 field_0x32;
    /* 0x34 */ s16 field_0x34;
    /* 0x36 */ s16 field_0x36;
    /* 0x38 */ s16 field_0x38;
    /* 0x3A */ s16 field_0x3A;
    /* 0x3C */ s16 field_0x3C;
    /* 0x3E */ s16 field_0x3E;
    /* 0x40 */ s16 field_0x40;
    /* 0x42 */ s16 field_0x42;
    /* 0x44 */ s16 field_0x44;
    /* 0x46 */ s16 field_0x46;
    /* 0x48 */ s16 field_0x48;
    /* 0x4A */ u8 padding_0x4A[0x4C - 0x4A];
    /* 0x4C */ JUtility::TColor mBlackColor;
    /* 0x50 */ JUtility::TColor mWhiteColor;
    /* 0x54 */ GXColor mClothColor;
    /* 0x58 */ GXColor mShadowColor;
    /* 0x5C */ u8 field_0x5C;
};

extern dMi_HIO_c g_miHIO;

#endif /* D_MENU_ITEM_H */
