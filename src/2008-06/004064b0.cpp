// from server: 100% by king_originala
extern "C" {
    extern unsigned int (__cdecl *strnlen)(const char *, unsigned int);
    extern int (__cdecl *_mbsnbcpy_s)(unsigned char *, unsigned int,
                                     const unsigned char *, unsigned int);
    void __cdecl check_result(int);
}

struct S {
    unsigned char reserved1[0x122];
    unsigned char text[0x81];
    unsigned char reserved2[0x1091];
    unsigned int length;

    int setText(const char *);
};

int S::setText(const char *source)
{
    unsigned int n = strnlen(source, 0x81);
    if (n > 0x80)
        return 0;

    check_result(_mbsnbcpy_s(text, 0x81,
                            reinterpret_cast<const unsigned char *>(source), n));
    length = n;
    return 1;
}
