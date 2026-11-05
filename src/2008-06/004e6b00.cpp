// from server: 100% by king_originala
struct S {
    void f(const void* p);
    void a(const void* p);
    bool b();
    void c();
    void d();
};

void S::f(const void* p)
{
    a(p);
    if (p == (const void*)0x97610C) {
        if (b())
            c();
        d();
    } else if (p == (const void*)0x976128 ||
               p == (const void*)0x97601C) {
        d();
    }
}
