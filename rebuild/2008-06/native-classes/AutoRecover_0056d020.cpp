// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: type_info object at 0x946340 for the Tuple type.
extern "C" const char g_00946340[];

// INFERRED: file-local stand-in for RBX::Reflection::Type; ctor (0x56bd90) and dtor
// (reached through the atexit stub at 0x7fd2e0) are external.
struct Local_0056d020
{
    unsigned char data[16];
    Local_0056d020(const char* name, const void* typeInfo);
    ~Local_0056d020();
};

extern "C" const Local_0056d020* fn_0056d020()
{
    static Local_0056d020 instance("Tuple", g_00946340);
    return &instance;
}
