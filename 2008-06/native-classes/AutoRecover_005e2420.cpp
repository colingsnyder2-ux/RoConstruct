// native-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_0097a88c[];
extern "C" char g_0097a980[];
// INFERRED: no native class header available; file-local layout mirrors the verified analog.
struct Local_005e2420_Instance {
    char padding[0x288];
    float value;
};

extern "C" int fn_004651c0(int a1);
extern "C" void __fastcall fn_0040db00(Local_005e2420_Instance* self, int unusedEdx, void* descriptor);
extern "C" void* __fastcall fn_0056b620(void* self, int unusedEdx, void* source);
extern "C" void __fastcall fn_005e1f00(void* self, int unusedEdx, const float* value, int flags);
extern "C" void __fastcall fn_00555350(int self);

extern "C" void __fastcall fn_005e2420(Local_005e2420_Instance* self, int unusedEdx, float v)
{
    if (v != self->value) {
        self->value = v;
        fn_0040db00(self, 0, (void*)(unsigned)g_0097a980);
        void* entry = fn_0056b620((void*)(unsigned)g_0097a88c, 0, self->padding + 0x14);
        if (entry)
            fn_005e1f00((char*)entry + 0x10, 0, &v, 0);
        int provider = fn_004651c0((int)self);
        if (provider)
            fn_00555350(provider);
    }
}
