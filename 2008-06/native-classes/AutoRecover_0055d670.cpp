// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: callee is called with 4 pushed args and caller pops (add esp,0x10), so it is declared cdecl here, not fastcall.
extern "C" int fn_0055cfa0(int a1, int a2, int a3, int a4);
// INFERRED: 0x944328 is the address of an unknown global (stored as a pointer-sized value).
extern "C" char g_00944328[];

extern "C" int fn_0055d670(int a, int* out, int kind)
{
    if (kind == 3) {
        *out = (int)g_00944328;
        return kind;
    }
    return fn_0055cfa0(a, (int)out, kind, kind & ~0xff);
}
