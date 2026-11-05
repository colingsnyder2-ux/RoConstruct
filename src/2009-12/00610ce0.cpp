// from server: 63% by atomic.potato
extern "C" void __cdecl free(void *);

struct S
{
    void __cdecl f(void *, void *);
};

void S::f(void *a, void *b)
{
    if (this != 0 && a != 0)
    {
        void *p = *(void **)((char *)this + 0x24c);
        if (p != 0)
        {
            ((void (__cdecl *)(void *, void *))p)(this, a);
            return;
        }
    }

    if (a != 0)
        free(a);
}
