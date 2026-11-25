// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the target is __stdcall with 1 argument (ret 4). It never sets ecx, so ecx
// reaches the callees unchanged; the callees are declared with no arguments so the
// compiler leaves ecx alone.
extern "C" void __cdecl fn_004e68b0(); // PartChunk::invalidateMaterial
extern "C" void __cdecl fn_004e6740(); // PartChunk::invalidateMesh

// INFERRED: the compared values are addresses of unknown globals (likely property descriptors).
extern "C" char g_0097b57c;
extern "C" char g_00975f14;
extern "C" char g_00975ef8;
extern "C" char g_00975f30;
extern "C" char g_00975f68;
extern "C" char g_00975f4c;

extern "C" void __stdcall fn_004e6bc0(const void* type)
{
    if (type == &g_0097b57c)
        goto call_6740;
    if (type == &g_00975f14)
        goto call_68b0;
    if (type == &g_00975ef8)
        goto call_68b0;
    if (type == &g_00975f30)
        goto call_68b0;
    if (type == &g_00975f68)
        goto call_6740;
    if (type == &g_00975f4c)
        goto call_6740;
    return;

call_68b0:
    fn_004e68b0();
    return;

call_6740:
    fn_004e6740();
    return;
}
