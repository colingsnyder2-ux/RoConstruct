// from server: 81% by atomic.potato
extern "C" void __stdcall sub_7B6970(void *, void *);

struct S
{
    void f(void *);
};

void S::f(void *value)
{
    *(void **)((char *)this + 0x50) = value;
    void *p = *(void **)((char *)this + 4);
    if (p)
        sub_7B6970(p, (void *)0x71AAD0);
    *(void **)((char *)this + 0x50) = 0;
}
