// from server: 61% by atomic.potato
extern "C" void __cdecl sub_a814d5(int);

extern "C" void __cdecl imported_QQVW(int, float);

struct S
{
    void f(int, float);
};

void S::f(int a, float b)
{
    sub_a814d5(1);
    imported_QQVW(a, b);
}
