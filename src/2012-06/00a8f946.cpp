// from server: 40% by atomic.potato
extern "C" void __cdecl sub_00a8f610(int, int, int);

struct S {
    int f(int, int, int);
};

int S::f(int a, int b, int c)
{
    sub_00a8f610(a, b, c);
    return a;
}
