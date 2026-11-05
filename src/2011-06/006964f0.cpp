// from server: 29% by atomic.potato
extern "C" void __cdecl std_string_copy(void *, const void *);

struct S
{
    void f(void *, void *);
};

void S::f(void *a, void *b)
{
    void *p = *(void **)((char *)this + 8);
    void *q = a;
    if (q)
        q = (char *)q - 28;
    std_string_copy(b, (char *)p + (unsigned int)q);
}
