// from server: 45% by atomic.potato
extern "C" void __cdecl free(void *);

struct S
{
    int f(int);
};

int S::f(int a)
{
    int v = *(int *)((char *)this + 0);
    if (a & 1)
        free((char *)this - 4);
    return v;
}
