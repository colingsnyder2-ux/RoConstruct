// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_0040db00[];
extern "C" char g_00975f4c[];

struct Local_00598750 {
    char padding[0x170]; // INFERRED: class header not available, only the 0x170 offset is known
    float value;
    void changed(const void*); // INFERRED: (unsigned)g_0040db00 is a __thiscall member (tail call, no edx setup)
};

extern "C" void __fastcall fn_00598750(Local_00598750* self, int unusedEdx, float v)
{
    if (v != self->value && v > 0.0f) {
        self->value = v;
        self->changed(reinterpret_cast<const void*>(g_00975f4c));
    }
}
