// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the callee is cdecl with six pushed arguments (the caller's
// `add esp, 0x1c` covers the six pushes plus the 4-byte local slot), so it is
// declared as plain cdecl. Its real signature is unknown.
extern "C" int fn_00659f60(int a1, int a2, int a3, void* p, int a5, int a6);

// INFERRED: the object type is unknown; the code only uses (this + 8).
extern "C" int __fastcall fn_0067d5b0(void* self, int unusedEdx, int arg1, int arg2, int arg3)
{
    // INFERRED: a byte is zeroed and then passed as a whole dword (upper bytes
    // uninitialised), matching `mov byte [esp],0` / `mov eax,[esp]`.
    int flag;
    *(char*)&flag = 0;
    // INFERRED: volatile forces arg3 to be loaded twice, as the original does.
    // This is a guess and has not been checked against the original bytes.
    volatile int& v = arg3;
    return fn_00659f60(arg1, arg2, v, (char*)self + 8, v, flag);
}
