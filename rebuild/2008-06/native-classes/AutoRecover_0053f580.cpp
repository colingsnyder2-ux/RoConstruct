// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: layout and helper signatures taken from the disassembly only; not compiled or diffed.
extern "C" int __fastcall fn_00540fb0(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_00540ce0(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_00402410(void* self, int unusedEdx);
extern "C" int __fastcall fn_005410d0(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_005400f0(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_0053f470(void* self, int unusedEdx, int a1);
extern "C" void __fastcall fn_00541030(void* self);
extern "C" int __fastcall fn_0071f210(int self, int unusedEdx, void* out);
extern "C" void __fastcall fn_004e6c00(int self);
extern "C" void __fastcall fn_004d8320(void* self, int unusedEdx, int a1);
extern "C" void __fastcall fn_00502a70(void* self);

struct Tmp8 { int a, b; };

extern "C" void __fastcall fn_0053f580(char* self, int unusedEdx, int arg)
{
    {
        Tmp8 t;
        fn_00540fb0(&t, 0, arg);
        fn_00540ce0(self + 0x28, 0, (int)&t);
        fn_00541030(&t);
    }
    {
        Tmp8 t;
        fn_00540fb0(&t, 0, arg);
        fn_00540ce0(self + 0x48, 0, (int)&t);
        fn_00541030(&t);
    }
    int ptr[4];
    int r = fn_0071f210(arg, 0, ptr);
    fn_004e6c00(r + 0x20);
    if ((unsigned char)fn_00402410(ptr, 0)) {
        int tmp;
        int copy = fn_005410d0(&tmp, 0, (int)ptr);
        fn_005400f0(self, 0, copy);
        fn_004d8320(self, 0, arg);
    } else {
        fn_004d8320(self, 0, arg);
    }
    fn_0053f470(self, 0, arg);
    fn_00502a70(ptr);
}
