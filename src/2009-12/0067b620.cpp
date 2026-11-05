// from server: 62% by atomic.potato
struct S
{
    int f();
};

extern "C" int __fastcall sub_415290(int);

int S::f()
{
    int p = *(int *)((char *)this + 0x20);
    if (!p)
        return 0;

    int q = sub_415290(p);
    if (!q)
        return 0;

    int r = *(int *)((char *)q + 0x98);
    int n = *(int *)((char *)r + 0x10) - *(int *)((char *)r + 0x0c);
    n >>= 3;

    if (n <= 0)
        return 0;
    return 1;
}
