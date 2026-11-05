// from server: 46% by atomic.potato
extern "C" void __cdecl sub_801c70(int, int, int);

struct S
{
    int __cdecl f(int, int, int);
};

int __cdecl S::f(int a, int b, int c)
{
    sub_801c70(a, b, c);
    return a;
}
