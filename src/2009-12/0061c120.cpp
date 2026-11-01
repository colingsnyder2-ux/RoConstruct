// from server: 100% by atomic.potato
extern "C" void* (__cdecl *malloc)(unsigned int);

struct S
{
    void* __cdecl f(int, int);
};

void* __cdecl S::f(int a, int b)
{
    return malloc((unsigned int)(a * b));
}
