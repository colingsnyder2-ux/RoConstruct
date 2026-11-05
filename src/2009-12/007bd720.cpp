// from server: 83% by atomic.potato
struct S
{
    int f(int *p);
};

int * __cdecl f(int *p);

int S::f(int *p)
{
    int *q = (int *)f(p);
    return *((unsigned char *)q + 0x180) == 0;
}
