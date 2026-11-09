// from server: 92% by atomic.potato
extern "C" void (__cdecl *free)(void *);

struct S
{
    void __cdecl f(void *);
};

void S::f(void *p)
{
    free(p);
}
