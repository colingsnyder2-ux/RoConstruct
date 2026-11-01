// from server: 100% by tester
struct S
{
    int f(int);
};

extern "C" int __stdcall g(int);

int S::f(int a)
{
    S *p = (S *)g(a);
    if (p)
        return *(int *)((char *)p + 8);
    return 1;
}
