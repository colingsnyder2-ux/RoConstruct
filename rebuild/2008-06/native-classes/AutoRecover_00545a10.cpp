// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

extern "C" int __fastcall fn_00545bd0(void* self, int unusedEdx, int a1);

// INFERRED: layout from the disassembly: three dwords, a sub-object at +0xc, two bytes at +0x14/+0x15.
struct Fn00545a10Obj {
    int f0;
    int f4;
    int f8;
    int sub;
    unsigned char b14;
    unsigned char b15;
};

extern "C" Fn00545a10Obj* __fastcall fn_00545a10(Fn00545a10Obj* self, int unusedEdx, int a1, int a2, int a3, int a4, unsigned char a5)
{
    self->f0 = a1;
    self->f4 = a2;
    self->f8 = a3;
    fn_00545bd0(&self->sub, 0, a4);
    self->b14 = a5;
    self->b15 = 0;
    return self;
}
