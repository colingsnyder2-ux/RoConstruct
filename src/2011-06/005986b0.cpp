// from server: 92% by atomic.potato
struct Inner {
    int f(int);
};

struct Outer {
    char pad[0x24];
    int base;
    int g(int, int);
};

extern "C" int __cdecl sub_595cd0(int);

int Outer::g(int a, int b)
{
    int *p = (int *)a;
    if (p)
        p = (int *)((char *)p - 0x1c);
    else
        p = 0;
    int *q = (int *)((char *)p + base);
    int v = sub_595cd0(*(int *)(b + 4));
    return ((Inner *)q)->f(*(int *)v);
}
