/* vim:set et ts=4 sts=4:
 *
 * libpyzy - The Chinese PinYin and Bopomofo conversion library.
 *
 * Copyright (c) 2008-2010 Peng Huang <shawn.p.huang@gmail.com>
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 2.1 of the
 * License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 * USA
 */
#ifndef __PYZY_CONFIG_H_
#define __PYZY_CONFIG_H_

namespace PyZy {

#define PINYIN_INCOMPLETE_PINYIN    (1U << 0)

#define PINYIN_CORRECT_GN_TO_NG     (1U << 1)
#define PINYIN_CORRECT_MG_TO_NG     (1U << 2)
#define PINYIN_CORRECT_IOU_TO_IU    (1U << 3)
#define PINYIN_CORRECT_UEI_TO_UI    (1U << 4)
#define PINYIN_CORRECT_UEN_TO_UN    (1U << 5)
#define PINYIN_CORRECT_UE_TO_VE     (1U << 6)
#define PINYIN_CORRECT_V_TO_U       (1U << 7)
#define PINYIN_CORRECT_ON_TO_ONG    (1U << 8)
#define PINYIN_CORRECT_ALL          (0x000001fe)

#define PINYIN_FUZZY_C_CH           (1U << 9)
#define PINYIN_FUZZY_CH_C           (1U << 10)
#define PINYIN_FUZZY_Z_ZH           (1U << 11)
#define PINYIN_FUZZY_ZH_Z           (1U << 12)
#define PINYIN_FUZZY_S_SH           (1U << 13)
#define PINYIN_FUZZY_SH_S           (1U << 14)
#define PINYIN_FUZZY_L_N            (1U << 15)
#define PINYIN_FUZZY_N_L            (1U << 16)
#define PINYIN_FUZZY_F_H            (1U << 17)
#define PINYIN_FUZZY_H_F            (1U << 18)
#define PINYIN_FUZZY_L_R            (1U << 19)
#define PINYIN_FUZZY_R_L            (1U << 20)
#define PINYIN_FUZZY_K_G            (1U << 21)
#define PINYIN_FUZZY_G_K            (1U << 22)

#define PINYIN_FUZZY_AN_ANG         (1U << 23)
#define PINYIN_FUZZY_ANG_AN         (1U << 24)
#define PINYIN_FUZZY_EN_ENG         (1U << 25)
#define PINYIN_FUZZY_ENG_EN         (1U << 26)
#define PINYIN_FUZZY_IN_ING         (1U << 27)
#define PINYIN_FUZZY_ING_IN         (1U << 28)
#define PINYIN_FUZZY_IAN_IANG       PINYIN_FUZZY_AN_ANG
#define PINYIN_FUZZY_IANG_IAN       PINYIN_FUZZY_ANG_AN
#define PINYIN_FUZZY_UAN_UANG       PINYIN_FUZZY_AN_ANG
#define PINYIN_FUZZY_UANG_UAN       PINYIN_FUZZY_ANG_AN
#define PINYIN_FUZZY_ALL            (0x1ffffe00)

#define DOUBLE_PINYIN_KEYBOARD_MSPY   (0)
#define DOUBLE_PINYIN_KEYBOARD_ZRM    (1)
#define DOUBLE_PINYIN_KEYBOARD_ABC    (2)
#define DOUBLE_PINYIN_KEYBOARD_ZGPY   (3)
#define DOUBLE_PINYIN_KEYBOARD_PYJJ   (4)
#define DOUBLE_PINYIN_KEYBOARD_XHE    (5)
#define DOUBLE_PINYIN_KEYBOARD_LAST   (5)

#define BOPOMOFO_KEYBOARD_STANDARD    (0)
#define BOPOMOFO_KEYBOARD_CHING_YEAH  (1)
#define BOPOMOFO_KEYBOARD_ETAN        (2)
#define BOPOMOFO_KEYBOARD_IBM         (3)
#define BOPOMOFO_KEYBOARD_LAST        (3)

class Config {
protected:
    Config (void);
    virtual ~Config (void);

private:
    Config (const Config & obj) { }

public:
    virtual void readDefaultValues (void);

    unsigned int option (void) const;
    unsigned int doublePinyinSchema (void) const;
    bool specialPhrases (void) const;
    bool modeSimp (void) const;
    unsigned int bopomofoKeyboardMapping (void) const;

    void setOption (unsigned int value);
    void setDoublePinyinSchema (unsigned int value);
    void setSpecialPhrases (bool value);
    void setModeSimp (bool value);
    void setBopomofoKeyboardMapping (unsigned int value);

protected:
    struct ConfigImpl;
    ConfigImpl *m_impl;
};

/* PinyinConfig */
class PinyinConfig : public Config {
public:
    static PinyinConfig & instance (void);
    virtual void readDefaultValues (void);

protected:
    PinyinConfig ();

private:
    struct PinyinConfigImpl;
    PinyinConfigImpl *m_pinyin_impl;
};

/* Bopomofo Config */
class BopomofoConfig : public Config {
public:
    static BopomofoConfig & instance (void);
    virtual void readDefaultValues (void);

protected:
    BopomofoConfig ();

private:
    struct BopomofoConfigImpl;
    BopomofoConfigImpl *m_bopomofo_impl;
};

};  // namespace PyZy

#endif  // __PYZY_CONFIG_H_
