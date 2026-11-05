// from server: 100% by atomic.potato
typedef void (__thiscall *Destructor)(void *);

extern "C" Destructor g_destructor;

struct S
{
    void f(void *, void *);
};

void S::f(void *first, void *last)
{
    unsigned char *p = (unsigned char *)first;
    unsigned char *end = (unsigned char *)last;
    while (p != end)
    {
        g_destructor(p);
        p += 0x20;
    }
}
