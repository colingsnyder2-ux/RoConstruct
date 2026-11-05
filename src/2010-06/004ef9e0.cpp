// from server: 67% by atomic.potato
extern "C" double *__cdecl sub_415d70(int);
extern "C" void __cdecl sub_4e12e0(double, int);

void f(int a, int b)
{
    double *p = sub_415d70(a);
    sub_4e12e0(*p, b);
}
