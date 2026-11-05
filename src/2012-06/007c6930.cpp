// from server: 57% by Intel
extern "C" int __cdecl sub_7c6080(int, int *, int);

struct S
{
    int *field28;
    int f(int, int);
};

int S::f(int a, int b)
{
    int local;
    int *p = field28 + 3;
    int x = sub_7c6080(a, &local, b);
    typedef int (__thiscall *Fn)(void *, int, int);
    Fn fn = (Fn)(*p);
    return fn(field28, b, x);
}
