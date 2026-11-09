// from server: 40% by atomic.potato
struct S
{
    int f(int);
    int *p;
};

extern "C" void __cdecl sub_6b07b0(int *);

int S::f(int x)
{
    if (x)
        sub_6b07b0((int *)((char *)p + x - 0x1c));
    else
        sub_6b07b0(p);
    return 0;
}
