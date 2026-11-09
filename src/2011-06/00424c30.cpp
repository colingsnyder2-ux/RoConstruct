// from server: 92% by atomic.potato
extern "C" void __cdecl free(void *);

struct S
{
    int f(int);
};

int S::f(int a)
{
    *(void **)this = (void *)0xA64854;
    if (a & 1)
        free((char *)this - 4);
    return (int)this;
}
