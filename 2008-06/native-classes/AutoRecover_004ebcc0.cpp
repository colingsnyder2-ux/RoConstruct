// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no class header available; layout reconstructed from raw offsets.
extern "C" ViewChunk* __fastcall fn_004eaae0(ViewChunk* self, int unusedEdx, float arg1, SharedInstance* arg2, void* arg3);
extern "C" int __fastcall fn_004ea490(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_004e9020(void* self, int unusedEdx, int a1, int a2, int a3, int a4);

extern "C" int __fastcall fn_004ebcc0(char* self, int unusedEdx, int* arg1, int* arg2)
{
    fn_004eaae0((int)self, 0, 0); // INFERRED: base ctor, float 0.0f first arg, args (arg1, arg2)
    return (int)self;
}
