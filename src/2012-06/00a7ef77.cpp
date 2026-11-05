// from server: 28% by atomic.potato
extern "C" void __cdecl sub_a814d5(int);

extern "C" void __cdecl imported_QQVW(
    int, int, int, float, int);

struct S {
    void f(int, int, int, float);
};

void S::f(int a, int b, int c, float d)
{
    sub_a814d5(1);
    imported_QQVW(a, b, c, d, 0);
}
