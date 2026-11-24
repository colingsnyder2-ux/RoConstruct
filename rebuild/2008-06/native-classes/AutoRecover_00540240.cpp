// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

extern "C" int __fastcall fn_00540fb0(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_00540b10(void* self, int unusedEdx, void* a1, void* a2);
extern "C" void __fastcall fn_00541030(void* self);

// INFERRED: 8-byte temporary built by fn_00540fb0 and destroyed by fn_00541030
// (the disassembly names that callee as a ctype destructor, which looks like a misidentification).
struct Tmp540240
{
    char data[8];
    explicit Tmp540240(int a)
    {
        fn_00540fb0(this, 0, a);
    }
    ~Tmp540240()
    {
        fn_00541030(this);
    }
};

extern "C" void __fastcall fn_00540240(char* self, int unusedEdx, int arg1, unsigned char flag)
{
    // INFERRED: the 12-byte result is discarded, so it is a plain buffer with no destructor.
    char result[12];
    if (flag)
    {
        Tmp540240 t(arg1);
        fn_00540b10(self + 0x28, 0, result, &t);
    }
    else
    {
        Tmp540240 t(arg1);
        fn_00540b10(self + 0x48, 0, result, &t);
    }
}
