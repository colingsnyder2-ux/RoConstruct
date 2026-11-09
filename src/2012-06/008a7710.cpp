// from server: 75% by atomic.potato
struct S
{
    int f();
};

extern "C" int __cdecl sub_495f40(int);
extern "C" int __cdecl sub_983b6a(int);
extern "C" int (__cdecl *g_call)(void *, int);

int g_deca80;

int S::f()
{
    int a;
    int b;

    a = *(int *)((char *)this + 12);
    b = *(int *)((char *)a + 2756);
    a = sub_495f40(b);
    if (!a)
        return 0;
    b = sub_983b6a(a);
    return g_call((void *)&g_deca80, b);
}
