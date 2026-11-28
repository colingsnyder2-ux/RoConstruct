// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_00846ff4[];
extern "C" char g_00847000[];
extern "C" char g_0084701c[];
extern "C" char g_0084702c[];
extern "C" char g_0084703c[];
extern "C" char g_0084704c[];
extern "C" char g_0084705c[];
extern "C" char g_0084706c[];
extern "C" char g_0084707c[];
extern "C" char g_00847084[];
extern "C" char g_0084708c[];
extern "C" char g_0084709c[];

// INFERRED: the real class is a BodyMover subclass that isn't in the headers, so a unique file-local type with the same vtable-slot offsets stands in for it.
struct Local_0062f780 {
    unsigned int words[79];
};

// BodyMover::BodyMover(const char*), the protected base constructor (thiscall).
extern "C" void __fastcall fn_0062e320(Local_0062f780* self, int unusedEdx, const char* name);

extern "C" Local_0062f780* __fastcall fn_0062f780(Local_0062f780* self, int unusedEdx, const char* name)
{
    // Pass edx through unchanged so the compiler doesn't emit an extra xor edx,edx.
    fn_0062e320(self, unusedEdx, name);
    self->words[0] = (unsigned)g_0084709c;
    self->words[4] = (unsigned)g_0084708c;
    self->words[5] = (unsigned)g_00847084;
    self->words[8] = (unsigned)g_0084707c;
    self->words[9] = (unsigned)g_0084706c;
    self->words[17] = (unsigned)g_0084705c;
    self->words[25] = (unsigned)g_0084704c;
    self->words[33] = (unsigned)g_0084703c;
    self->words[41] = (unsigned)g_0084702c;
    self->words[49] = (unsigned)g_0084701c;
    self->words[76] = (unsigned)g_00847000;
    self->words[78] = (unsigned)g_00846ff4;
    return self;
}
