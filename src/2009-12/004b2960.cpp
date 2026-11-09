// from server: 65% by atomic.potato
extern "C" void __stdcall basic_string_copy(void *, const void *);

struct S
{
    int f(const void *, const void *);
};

int S::f(const void *a, const void *b)
{
    char *p = (char *)this + 0xa8;
    basic_string_copy((void *)b, p);
    *(int *)((char *)b + 0x1c) = *(int *)(p + 0x1c);
    return (int)b;
}
