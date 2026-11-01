// from server: 100% by king_originala
struct S {
    unsigned char padding[0x20];
    unsigned long flags;
};

extern "C" int __stdcall check(S* p);

int __stdcall f(S* p)
{
    if (!check(p))
        return 0;

    p->flags = (p->flags & 0xFFCFFF7FUL) | 0x08000000UL;
    return 1;
}
