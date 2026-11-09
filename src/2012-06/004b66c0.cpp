// from server: 66% by Intel
struct CEnumMediaTypes
{
    int f(int, int *, int);
};

extern "C" int __stdcall StrCmpIW(const wchar_t *, const wchar_t *);
extern "C" int __stdcall CreateEnumMediaTypes(int, int *);

int CEnumMediaTypes::f(int a1, int *a2, int a3)
{
    if (!a2)
        return 0x80004003;

    if (!StrCmpIW((const wchar_t *)0xB64320, (const wchar_t *)a3))
        return 0;

    if (!StrCmpIW((const wchar_t *)0xC0CD08, (const wchar_t *)a3))
        return 0;

    *a2 = 0;
    return 0x80004002;
}
