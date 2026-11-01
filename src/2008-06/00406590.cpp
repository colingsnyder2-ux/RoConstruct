// from server: 100% by colin
extern "C" {
    extern unsigned int (__cdecl *strnlen)(const char *, unsigned int);
    extern int (__cdecl *_mbsnbcpy_s)(
        unsigned char *, unsigned int, const unsigned char *, unsigned int);
    void __cdecl check_error(int);
}

struct S {
    unsigned char padding1[0x224];
    unsigned char buffer[0x801];
    unsigned char padding2[0x817];
    unsigned int length;

    int set(const char *text);
};

int S::set(const char *text)
{
    unsigned int n = strnlen(text, 0x801);
    if (n > 0x800)
        return 0;

    check_error(_mbsnbcpy_s(
        buffer, 0x801, reinterpret_cast<const unsigned char *>(text), n));
    length = n;
    return 1;
}
