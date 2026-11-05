// from server: 100% by king_originala
struct Stream;

extern void (__thiscall *imbue)(Stream*, void*, const void*);
extern void (__thiscall *destroyLocale)(void*);

struct S {
    char padding[160];
    Stream* stream;
    char reserved[12];
    unsigned char flags;

    void f(const void* locale);
};

void S::f(const void* locale)
{
    if ((flags & 1) && stream) {
        imbue(stream, &locale, locale);
        destroyLocale(&locale);
    }
}
