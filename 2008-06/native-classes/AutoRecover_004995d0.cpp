// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: 16-byte G3D::Array<Vector4> passed by value; bytes at +0xc/+0xd are flags copied after _copy.
struct Vec4Array16;
extern "C" void __fastcall fn_00496ef0(Vec4Array16* self, int unusedEdx, const Vec4Array16* src);

struct Vec4Array16 {
    char data[12];
    unsigned char flagA;
    unsigned char flagB;
    char pad[2];
    Vec4Array16(const Vec4Array16& o) {
        fn_00496ef0(this, 0, &o);
        flagA = o.flagA;
        flagB = o.flagB;
    }
};

struct Target;

extern "C" unsigned char g_byte_00970298;
extern "C" void fn_004974f0();
extern "C" void fn_00499430(Vec4Array16 arr, void* outBuf, void (*cb)(), int zero, Target* self, int flag);
extern "C" void __fastcall fn_004984d0(Target* self, int unusedEdx);
extern "C" void __fastcall fn_004995d0(Target* self, int unusedEdx, Vec4Array16* arg);

extern "C" void __fastcall fn_004995d0(Target* self, int unusedEdx, Vec4Array16* arg)
{
    char local[0x20]; // INFERRED: uninitialised 32-byte out buffer passed by pointer
    arg->flagA = 1;
    fn_00499430(*arg, local, fn_004974f0, 0, self, g_byte_00970298);
    fn_004984d0(self, 0);
}
