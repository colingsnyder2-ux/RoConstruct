// from server: 100% by king_originala
extern "C" unsigned int (__cdecl *strnlen)(const char*, unsigned int);
extern "C" int (__cdecl *_mbsnbcpy_s)(unsigned char*, unsigned int,
                                     const unsigned char*, unsigned int);
extern void __cdecl check_result(int);

struct S
{
    int set_text(const char*);
};

int S::set_text(const char* text)
{
    unsigned int length = strnlen(text, 0x101);
    if (length > 0x100)
        return 0;

    check_result(_mbsnbcpy_s((unsigned char*)this + 0x21, 0x101,
                            (const unsigned char*)text, length));
    *(unsigned int*)((char*)this + 0x1230) = length;
    return 1;
}
