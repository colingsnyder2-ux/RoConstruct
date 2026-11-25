// native-flags: /O2 /GS /EHsc /MD
// INFERRED: odd cases pass BinaryOutput& both in EDX (thiscall-style register
// argument) and as the stack argument, which makes MSVC emit mov edx,[esp+8] /
// push edx exactly like the original.

extern "C" void __fastcall fn_0050eaf0(void* self, int unusedEdx, void* out);
extern "C" void __fastcall fn_0050ba30(void* self, void* outReg, void* outStack);
extern "C" void __fastcall fn_0050b700(void* self, int unusedEdx, void* out);
extern "C" void __fastcall fn_0050e8a0(void* self, void* outReg, void* outStack);
extern "C" void __fastcall fn_0050aef0(void* self, int unusedEdx, void* out);
extern "C" void __fastcall fn_0050b1a0(void* self, void* outReg, void* outStack);

extern "C" void __fastcall fn_0050f2e0(void* self, int unusedEdx, int format, void* out)
{
    switch (format) {
    case 6:
        fn_0050eaf0(self, unusedEdx, out);
        break;
    case 7:
        fn_0050ba30(self, out, out);
        break;
    case 5:
        fn_0050b700(self, unusedEdx, out);
        break;
    case 0:
        fn_0050e8a0(self, out, out);
        break;
    case 1:
        fn_0050aef0(self, unusedEdx, out);
        break;
    case 2:
        fn_0050b1a0(self, out, out);
        break;
    default:
        break;
    }
}
