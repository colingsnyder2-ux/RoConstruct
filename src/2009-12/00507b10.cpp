// from server: 48% by atomic.potato
struct S
{
    int f(int);
};

extern "C" void __cdecl sub_505080(int, int);
extern "C" void sub_503cf0(S *);

int S::f(int a)
{
    sub_505080(a, 0);
    sub_503cf0((S *)0);
    return 0;
}
