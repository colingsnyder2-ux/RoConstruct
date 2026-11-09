// from server: 56% by atomic.potato
struct EventDesc
{
    void f(void *);
};

extern "C" void __cdecl helper(void *);

void EventDesc::f(void *p)
{
    void *base = *(void **)((char *)this + 0x2c);
    if (p != 0)
        helper((char *)base + *(int *)((char *)p) - 0x1c);
    else
        helper(base);
}
