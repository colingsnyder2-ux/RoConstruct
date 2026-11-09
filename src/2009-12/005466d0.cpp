// from server: 36% by atomic.potato
struct S
{
    unsigned char f();
    void __cdecl g(unsigned char *);
};

struct T
{
    unsigned char f();
};

unsigned char T::f()
{
    S *p = reinterpret_cast<S *>(this);
    return p->f();
}

void S::g(unsigned char *p)
{
    *p = static_cast<unsigned char>(reinterpret_cast<S *>(p)->f());
}
