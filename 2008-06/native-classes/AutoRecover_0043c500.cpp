// native-flags: /O1 /Ob2 /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the real class is unknown. The slot is declared __fastcall with one
// int argument so that edx stays live (it is forwarded unchanged). The compiler
// then cannot use edx to hold the jump target and emits "jmp [eax+0x100]".
struct Local_0043c500
{
    virtual void s00() = 0; virtual void s01() = 0; virtual void s02() = 0; virtual void s03() = 0;
    virtual void s04() = 0; virtual void s05() = 0; virtual void s06() = 0; virtual void s07() = 0;
    virtual void s08() = 0; virtual void s09() = 0; virtual void s10() = 0; virtual void s11() = 0;
    virtual void s12() = 0; virtual void s13() = 0; virtual void s14() = 0; virtual void s15() = 0;
    virtual void s16() = 0; virtual void s17() = 0; virtual void s18() = 0; virtual void s19() = 0;
    virtual void s20() = 0; virtual void s21() = 0; virtual void s22() = 0; virtual void s23() = 0;
    virtual void s24() = 0; virtual void s25() = 0; virtual void s26() = 0; virtual void s27() = 0;
    virtual void s28() = 0; virtual void s29() = 0; virtual void s30() = 0; virtual void s31() = 0;
    virtual void s32() = 0; virtual void s33() = 0; virtual void s34() = 0; virtual void s35() = 0;
    virtual void s36() = 0; virtual void s37() = 0; virtual void s38() = 0; virtual void s39() = 0;
    virtual void s40() = 0; virtual void s41() = 0; virtual void s42() = 0; virtual void s43() = 0;
    virtual void s44() = 0; virtual void s45() = 0; virtual void s46() = 0; virtual void s47() = 0;
    virtual void s48() = 0; virtual void s49() = 0; virtual void s50() = 0; virtual void s51() = 0;
    virtual void s52() = 0; virtual void s53() = 0; virtual void s54() = 0; virtual void s55() = 0;
    virtual void s56() = 0; virtual void s57() = 0; virtual void s58() = 0; virtual void s59() = 0;
    virtual void s60() = 0; virtual void s61() = 0; virtual void s62() = 0; virtual void s63() = 0;
    virtual void s64() = 0; // offset 0x100
};

extern "C" void __fastcall fn_0043c500(Local_0043c500* self)
{
    self->s64();
}
