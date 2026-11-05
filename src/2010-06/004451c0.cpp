// from server: 65% by atomic.potato
extern "C" int __cdecl sub_444ec0(int);

struct S
{
    int m_1c;
    int f(int, int);
};

int S::f(int a, int b)
{
    int value = sub_444ec0(b);
    int *table = *(int **)((char *)this + 0x1c);
    typedef int (__thiscall *Fn)(int *, int *);
    Fn fn = *(Fn *)(*(int **)table + 0x10);
    return fn(table, &value);
}
