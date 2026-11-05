// from server: 55% by atomic.potato
struct S
{
    int f();
};

extern "C" int sub_416f90(int *);

int S::f()
{
    int *p = *(int **)((char *)this + 0x20);
    if (!p)
        return 0;

    int *q = (int *)sub_416f90(p);
    if (!q)
        return 0;

    int *a = *(int **)((char *)q + 0x94);
    if (((*(int *)((char *)a + 8) - *(int *)((char *)a + 4)) >> 3) <= 0)
        return 0;

    return 1;
}
