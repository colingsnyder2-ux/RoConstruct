// from server: 100% by Yeetserama
// hypothesis: 0054dd20 is the same stream-buffer imbue twin as exact 0054d050,
// with the buffer at 0x4c and the flags byte at 0x5c.
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
extern void (__thiscall *pubimbue)(void*, void*, const void*);
extern void (__thiscall *locale_destructor)(void*);

struct S {
    char padding0[0x4c];
    void* buffer;
    char padding1[0x0C];
    unsigned char flags;

    void imbue(const void* locale);
};

void S::imbue(const void* locale)
{
    if ((flags & 1) && buffer) {
        pubimbue(buffer, &locale, locale);
        locale_destructor(&locale);
    }
}
