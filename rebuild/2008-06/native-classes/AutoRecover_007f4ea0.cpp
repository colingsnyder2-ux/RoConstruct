// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: Each three-word argument is a member-function pointer.
struct MemberPointer {
    void (*function)();
    int adjustment;
    int virtualOffset;
};

extern "C" void fn_005a05c0();
extern "C" void fn_005a5200();
extern "C" void __cdecl fn_007fe0b0();
extern "C" int __cdecl atexit(void (__cdecl*)());
extern "C" char g_009769d8;

extern "C" int __fastcall fn_005a3be0(
    void* self, int unusedEdx, const char* name, const char* category,
    MemberPointer getter, MemberPointer setter, int flags);

extern "C" void __cdecl fn_007f4ea0()
{
    MemberPointer setter = {fn_005a5200, 0, 0};
    MemberPointer getter = {fn_005a05c0, 0, 0};
    fn_005a3be0(&g_009769d8, 0, "CurrentCamera", "Data", getter, setter, 5);
    atexit(fn_007fe0b0);
}
