// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the target appears to be a boost::iostreams streambuf close routine.
// It calls virtual slot 15 (vtable +0x3c) with 1 and then with 2. Each call is in
// its own try/catch(...) that swallows exceptions. It then resets an optional-like
// member (storage at +0x40, "initialized" flag at +0x48 within it) and clears the
// int at +0x9c.

// INFERRED: destructor of the value held in the optional at +0x40. Its real address
// is unknown because the call target was masked. It is declared with only the
// object pointer so that edx is not loaded at the call site, as in the original.
extern "C" void __fastcall fn_005f7000(void* inner);

struct OptionalLike {
    char storage[0x48];   // 0x40..0x88
    bool initialized;     // 0x88

    void reset()
    {
        if (initialized) {
            fn_005f7000(this);
            initialized = false;
        }
    }
};

struct Obj15 {
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
    virtual void slot15(int which) = 0;

    char pad1[0x3c];      // 0x04..0x40
    OptionalLike opt;     // 0x40..0x89
    char pad2[0x13];      // 0x89..0x9c
    int  state;           // 0x9c
};

extern "C" void __fastcall fn_005f7340(Obj15* self, int unusedEdx)
{
    try {
        self->slot15(1);
    } catch (...) {
    }
    try {
        self->slot15(2);
    } catch (...) {
    }
    self->opt.reset();
    self->state = 0;
}
