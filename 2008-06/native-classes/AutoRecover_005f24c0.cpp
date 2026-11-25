// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the owning class is unknown. The visible code calls virtual slot
// 0x3c (index 15) with argument 1 inside a try block (EH state 0). The
// remainder is reconstructed as a boost::iostreams-style close sequence:
// close(in), close(out), each guarded by try/catch(...), then a flag byte at
// +0x41 is cleared and the dword at +0x54 is zeroed.
struct SelfLayout {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual void slot4() = 0;
    virtual void slot5() = 0;
    virtual void slot6() = 0;
    virtual void slot7() = 0;
    virtual void slot8() = 0;
    virtual void slot9() = 0;
    virtual void slot10() = 0;
    virtual void slot11() = 0;
    virtual void slot12() = 0;
    virtual void slot13() = 0;
    virtual void slot14() = 0;
    virtual void slot15(int which) = 0;   // vtable +0x3c

    char pad04[0x41 - 0x04];              // 0x04..0x40
    char flag41;                          // INFERRED: 0x41
    char pad42[0x54 - 0x42];              // 0x42..0x53
    int field54;                          // INFERRED: 0x54
};

extern "C" void __fastcall fn_005f24c0(SelfLayout* self, int unusedEdx)
{
    try {
        self->slot15(1);
    } catch (...) {
    }
    // INFERRED: second close call with "out" mode
    try {
        self->slot15(2);
    } catch (...) {
    }
    // INFERRED: post-close state reset
    if (self->flag41)
        self->flag41 = 0;
    self->field54 = 0;
}
