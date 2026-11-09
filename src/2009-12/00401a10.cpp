// from server: 88% by atomic.potato
extern "C" void __cdecl helper(void *);

struct S
{
    void f(void *);
};

void S::f(void *b)
{
    helper(b);
    if (b)
    {
        void **p = (void **)((char *)b + 0x18);
        ((void (__thiscall *)(void *, int))*p)(p, 1);
    }
}
