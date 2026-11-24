// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: this looks like an IID comparison against a global GUID, where the first stack arg is the this-like pointer and the second is the GUID pointer.
extern "C" int g_008164c8;
extern "C" int g_008164cc;
extern "C" int g_008164d0;
extern "C" int g_008164d4;

extern "C" int __stdcall fn_00407d40(void* self, const int* other)
{
    int result;
    if (other[0] == g_008164c8 &&
        other[1] == g_008164cc &&
        other[2] == g_008164d0 &&
        other[3] == g_008164d4)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result == 0;
}
