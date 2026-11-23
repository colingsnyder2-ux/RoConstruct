// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

struct Obj4490c0 {
    char pad[0x14c];
    float lo;   // INFERRED: lower bound at +0x14c
    float val;  // INFERRED: stored value at +0x150
};

extern "C" float g_fn_004490c0_max; // INFERRED: float global at 0x008163a4, upper bound
extern "C" void __fastcall fn_0040db00(Obj4490c0* self, int unusedEdx, int desc);

extern "C" void __fastcall fn_004490c0(Obj4490c0* self, int unusedEdx, float arg)
{
    const float* p = &arg;
    if (!(self->lo < arg)) p = &self->lo;
    float hi = g_fn_004490c0_max;
    if (!(hi < *p)) {} else p = &hi;
    float v = *p;
    if (self->val != v) {
        self->val = v;
        fn_0040db00(self, 0, 0x96d49c); // INFERRED: property descriptor address
    }
}
