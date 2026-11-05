// from server: 67% by atomic.potato
extern "C" int __cdecl memcpy_s(void *, unsigned int, const void *, unsigned int);

struct S
{
    void * __cdecl f(void *, void *, unsigned int);
};

void *S::f(void *a, void *b, unsigned int c)
{
    memcpy_s(b, c, a, c);
    return ((void *(__cdecl *)(unsigned int))0x4029f0)(c);
}
