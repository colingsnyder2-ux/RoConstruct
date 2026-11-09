// from server: 100% by atomic.potato
struct S
{
    int f();
};

extern "C" int __cdecl sub_006e3250();

int S::f()
{
    int *p = (int *)sub_006e3250();
    if (p)
        return p[0x168 / sizeof(int)];
    return 0;
}
