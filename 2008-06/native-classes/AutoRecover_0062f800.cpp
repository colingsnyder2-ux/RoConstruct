// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_008470e4[];
extern "C" char g_008470f0[];
extern "C" char g_0084710c[];
extern "C" char g_0084711c[];
extern "C" char g_0084712c[];
extern "C" char g_0084713c[];
extern "C" char g_0084714c[];
extern "C" char g_0084715c[];
extern "C" char g_0084716c[];
extern "C" char g_00847174[];
extern "C" char g_0084717c[];
extern "C" char g_0084718c[];

// INFERRED: no class header was available, so a file-local layout type stands in for the derived BodyMover object.
struct Local_0062f800 {
    volatile unsigned int data[82];
};

// RBX::BodyMover::BodyMover(const char*) at 0x0062e320 (thiscall)
extern "C" void __fastcall fn_0062e320(Local_0062f800* self, int unusedEdx, const char* name);

extern "C" Local_0062f800* __fastcall fn_0062f800(Local_0062f800* self, int unusedEdx, const char* name)
{
    // Forward the incoming edx so the compiler emits no extra register setup before the call.
    fn_0062e320(self, unusedEdx, name);
    self->data[0x000 / 4] = (unsigned)g_0084718c;
    self->data[0x010 / 4] = (unsigned)g_0084717c;
    self->data[0x014 / 4] = (unsigned)g_00847174;
    self->data[0x020 / 4] = (unsigned)g_0084716c;
    self->data[0x024 / 4] = (unsigned)g_0084715c;
    self->data[0x044 / 4] = (unsigned)g_0084714c;
    self->data[0x064 / 4] = (unsigned)g_0084713c;
    self->data[0x084 / 4] = (unsigned)g_0084712c;
    self->data[0x0a4 / 4] = (unsigned)g_0084711c;
    self->data[0x0c4 / 4] = (unsigned)g_0084710c;
    self->data[0x130 / 4] = (unsigned)g_008470f0;
    self->data[0x138 / 4] = (unsigned)g_008470e4;
    return self;
}
