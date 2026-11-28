// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

typedef void (__thiscall *StrCtor)(void*, const char*);

// INFERRED: imported std::string(const char*) constructor, called through the IAT
extern StrCtor g_strCtorImport;

// INFERRED: global string object at 0x97dc3c
extern char g_0097dc3c[];

// INFERRED: destructor thunk registered with atexit
extern "C" void fn_008015a0(void);

extern "C" int __cdecl atexit(void (__cdecl *)(void));

extern "C" void fn_007f9100(void)
{
    g_strCtorImport(g_0097dc3c, "RbxSceneManager");
    atexit(fn_008015a0);
}
