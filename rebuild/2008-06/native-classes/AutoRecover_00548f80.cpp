// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" int __fastcall fn_0054aca0(void* self, int unusedEdx, double a1);
extern "C" int __fastcall fn_0054ae90(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_00540e80(void* self, int unusedEdx);
extern "C" void* __fastcall fn_004e6030(void* self, int unusedEdx, int tex);

// INFERRED: arg1 is the sret slot (ReferenceCountedPointer<Texture>*), arg2 is a float widened to double for the first callee.
extern "C" void* __fastcall fn_00548f80(void* self, int unusedEdx, void* ret, float f)
{
    int a = fn_0054aca0(self, 0, (double)f);
    int b = fn_0054ae90((char*)self + 0xc, 0, a);
    int q = fn_00540e80((void*)b, 0);
    fn_004e6030(ret, 0, q);
    return ret;
}
