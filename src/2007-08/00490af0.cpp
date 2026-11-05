// from server: 42% by colin
extern "C" int __cdecl sub_489940(int);
extern "C" int __cdecl sub_48CAF0(int);
extern "C" int __cdecl sub_490800(int, int);
extern "C" int __cdecl sub_4893C0(int, int, int, int, int);
extern "C" void __cdecl sub_62FC62(int);

struct S {
    int f(int a, int b, int c, int d, int e);
};

int S::f(int a, int b, int c, int d, int e)
{
    int local = 0;
    sub_489940(local);
    sub_48CAF0(0);
    int r = sub_490800(c, d);
    int* p = (int*)e;
    int v = *p;
    int tmp = -1;
    sub_4893C0(v, (int)&tmp, (int)&tmp, (int)&tmp, (int)&tmp);
    sub_62FC62(tmp);
    return r;
}
