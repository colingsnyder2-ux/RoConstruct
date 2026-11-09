// from server: 43% by atomic.potato
struct S
{
    void __cdecl f(void *);
};

extern "C" void helper(void *, unsigned long, unsigned long);

void S::f(void *p)
{
    unsigned long a = *(unsigned long *)p;
    char z = 0;
    helper((void *)(a + 8), (unsigned long)z, (unsigned long)&z);
}
