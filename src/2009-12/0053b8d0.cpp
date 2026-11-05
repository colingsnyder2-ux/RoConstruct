// from server: 69% by atomic.potato
struct S
{
    int value;
};

extern "C" void __cdecl sub_532d00(int *, int);
extern "C" void __cdecl sub_53a120(int *);

void f(S *, int, int);

void f(S *p, int a, int b)
{
    int local;
    sub_532d00(&local, a);
    if (p->value != 0)
        sub_53a120(&local);
}
