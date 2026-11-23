// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: global at 0x96d358 caches a value read from this+0x130 on first call
extern "C" void* g_fn_00449440_cache;
void* g_fn_00449440_cache;

struct Fn00449440Self {
    char pad[0x130];
    void* cached;
};

extern "C" void __fastcall fn_00449440(Fn00449440Self* self, int unusedEdx)
{
    if (!g_fn_00449440_cache)
        g_fn_00449440_cache = self->cached;
}
