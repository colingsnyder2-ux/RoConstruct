// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_00975f68[];
// INFERRED: class layout unknown; value at +0x16c, tail-calls fn_0040db00 with property ptr 0x975f68.
struct Local_00598710 {
    char padding[0x16c];
    float value;
};

extern "C" void __fastcall fn_0040db00(Local_00598710* self, int unusedEdx, const void* property);

extern "C" void __fastcall fn_00598710(Local_00598710* self, int unusedEdx, float v)
{
    if (v != self->value && v > 0.0f) {
        self->value = v;
        fn_0040db00(self, unusedEdx, (const void*)(unsigned)g_00975f68);
    }
}
