// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: Likely boost::iostreams indirect_streambuf::close() (from filtering_stream).
// The visible code calls virtual slot 0x3c with argument 1 inside a try block.
// Everything after that jump is not in the excerpt. It is reconstructed as close(out)
// in a second try block, then a reset of an optional member and of a flags word.
// The class layout is a guess.

struct OptStorage005f7510 {
    char data[0x58];
    bool initialized; // object +0x98
};

struct FnObj005f7510 {
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void closeSide(int which); // vtable offset 0x3c
    char pad[0x40 - 4];
    OptStorage005f7510 opt;            // +0x40
    char pad2[0xb0 - 0x40 - sizeof(OptStorage005f7510)];
    int flags;                         // +0xb0
};

extern "C" void __fastcall fn_005f7510(FnObj005f7510* self, int unusedEdx)
{
    try {
        self->closeSide(1);
    } catch (...) {
    }
    // INFERRED: the remainder of the function is not visible in the disassembly excerpt.
    try {
        self->closeSide(2);
    } catch (...) {
    }
    // INFERRED: reset of the optional member (storage assumed trivially destructible).
    if (self->opt.initialized) {
        self->opt.initialized = false;
    }
    self->flags = 0;
}
