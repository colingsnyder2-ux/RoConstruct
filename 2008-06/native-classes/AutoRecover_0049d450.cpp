// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
struct Fn0049d450Self {
    char padding[0x1ac];
    int value; // INFERRED: field at +0x1ac compared and stored by target
};

extern "C" void __fastcall fn_0040db00(Fn0049d450Self* self, int unusedEdx, void* arg);

extern "C" void __fastcall fn_0049d450(Fn0049d450Self* self, int unusedEdx, int v)
{
    if (v != self->value) {
        self->value = v;
        // edx is passed through unchanged, so the tail call emits no "xor edx, edx"
        fn_0040db00(self, unusedEdx, reinterpret_cast<void*>(0x97029c));
    }
}
