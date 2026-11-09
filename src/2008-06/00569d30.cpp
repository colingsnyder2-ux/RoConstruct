// from server: 100% by king_originala
namespace ATL {
    __declspec(noreturn) void __stdcall AtlThrowImpl(long hr);
}

extern "C" int (__cdecl *mbscmp_import)(
    const unsigned char *, const unsigned char *);

int __cdecl compareStrings(
    const unsigned char *const volatile *left,
    const unsigned char *right)
{
    if (!right)
        ATL::AtlThrowImpl((long)0x80004005UL);

    const unsigned char *value = *left;
    return mbscmp_import(value, right) == 0;
}
