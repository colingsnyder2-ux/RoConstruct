// from server: 100% by atomic.potato
extern "C" unsigned int (__cdecl * const strnlen)(const char* str, unsigned int maxlen);
extern "C" int (__cdecl * const _mbsnbcpy_s)(unsigned char* dst, unsigned int sizeInBytes, const unsigned char* src, unsigned int count);
extern "C" int __cdecl sub_4029F0(int code);

struct FactoryProduct {
    int func(char* src);
};

int FactoryProduct::func(char* src) {
    unsigned int n = strnlen(src, 0x81);
    if (n > 0x80) {
        return 0;
    }
    sub_4029F0(_mbsnbcpy_s((unsigned char*)this + 0x122, 0x81, (const unsigned char*)src, n));
    *(unsigned int*)((char*)this + 0x1234) = n;
    return 1;
}
