// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: constructor of std::string imported via IAT slot, called thiscall
typedef void (__thiscall *StrCtor)(void*, const char*);
extern StrCtor g_basic_string_ctor_802458;

// INFERRED: atexit thunk for the global string
extern "C" void fn_008014a0(void);
extern "C" int fn_006a17af(void (*)(void));

// INFERRED: global std::string storage at 0x97daf0, literal at 0x84d750
extern char g_0097daf0[];
extern const char g_0084d750[];

extern "C" void fn_007f9050(void)
{
    g_basic_string_ctor_802458(g_0097daf0, g_0084d750);
    fn_006a17af(fn_008014a0);
}
