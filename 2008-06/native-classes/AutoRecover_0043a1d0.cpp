// native-flags: /Ox /Oy- /Ob2 /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: tail-jump thunk to virtual method at vtable offset 0xfc (slot 63)
// INFERRED: slot declared __fastcall with the pass-through edx so the compiler keeps edx live and emits jmp [eax+0xfc]
struct Local_0043a1d0 {
    virtual void s0();  virtual void s1();  virtual void s2();  virtual void s3();
    virtual void s4();  virtual void s5();  virtual void s6();  virtual void s7();
    virtual void s8();  virtual void s9();  virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27();
    virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
    virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35();
    virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
    virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43();
    virtual void s44(); virtual void s45(); virtual void s46(); virtual void s47();
    virtual void s48(); virtual void s49(); virtual void s50(); virtual void s51();
    virtual void s52(); virtual void s53(); virtual void s54(); virtual void s55();
    virtual void s56(); virtual void s57(); virtual void s58(); virtual void s59();
    virtual void s60(); virtual void s61(); virtual void s62();
    virtual void s63();
};

extern "C" void __fastcall fn_0043a1d0(Local_0043a1d0* self)
{
    self->s63();
}
