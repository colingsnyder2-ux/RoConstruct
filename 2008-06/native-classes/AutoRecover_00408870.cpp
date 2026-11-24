// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the disassembly pushes four stack arguments (0, value, 0x6e, [0x96c268])
// and ecx is only used as a scratch register to hold the global before pushing it.
// So fn_004057f0 is declared as a plain __stdcall with 4 args, matching the
// byte-exact analog, rather than as the __fastcall thiscall form the brief suggested.
extern "C" int __stdcall fn_004057f0(int a1, int a2, int a3, int a4);

// INFERRED: unknown global dword at 0x96c268 (type guessed as int).
extern "C" int g_0096c268;

// INFERRED: return type is int, since eax from the callee is returned unchanged.
extern "C" int __stdcall fn_00408870(int value)
{
    return fn_004057f0(g_0096c268, 0x6E, value, 0);
}
