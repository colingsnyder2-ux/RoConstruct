// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: compares a 16-byte GUID-like value against a global; the function returns true when they differ.
extern "C" int g_008164a8;
extern "C" int g_008164ac;
extern "C" int g_008164b0;
extern "C" int g_008164b4;

extern "C" int __stdcall fn_00417e20(void* self, const int* other)
{
    int result;
    if (other[0] == g_008164a8 &&
        other[1] == g_008164ac &&
        other[2] == g_008164b0 &&
        other[3] == g_008164b4)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result == 0;
}
