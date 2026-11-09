// from server: 100% by king_originala
struct Object {
    virtual void destroy(unsigned int);
};

struct S {
    unsigned char padding[16];
    Object object;
};

extern unsigned int __cdecl cleanup(const S&);

void __stdcall f(S* p)
{
    cleanup(*p);
    if (p)
        p->object.destroy(1);
}
