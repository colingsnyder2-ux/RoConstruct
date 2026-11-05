// from server: 100% by Yeetserama
// hypothesis: 00456800 tests a pointer field against NULL; the helper takes
// bool arguments, so the compiler only sets AL before pushing.
struct S_func_00456800 {
    char pad0[0x198];
    void* ptr;
};

extern "C" void __stdcall sub_004566c0(bool, bool);

void __fastcall f(S_func_00456800* self)
{
    sub_004566c0(self->ptr == 0, true);
}
