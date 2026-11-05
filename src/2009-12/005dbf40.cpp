// from server: 50% by atomic.potato
extern "C" void destroy_bad_cast(void *);

struct S
{
    void f();
};

void S::f()
{
    *(void **)this = (void *)0x9c1534;
    *(void **)((char *)this + 0x14) = (void *)0x9c152c;
    *(void **)((char *)this + 0x14) = (void *)0x99fdd8;

    void *p = *(void **)((char *)this + 0x18);
    if (p)
        destroy_bad_cast(p);

    *(void **)this = (void *)0x9c1364;
}
