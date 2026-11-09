// from server: 33% by atomic.potato
extern "C" void __stdcall sub_4E1650(void *, void *, void *);

struct S
{
    void f(void *);
};

void S::f(void *p)
{
    sub_4E1650(p, (char *)p + 0x0c, (char *)p + 0x24);
}
