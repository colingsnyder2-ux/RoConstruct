// from server: 67% by atomic.potato
struct S
{
    void __cdecl f(int, double);
};

extern "C" void __cdecl sub_4ea100(int);
extern "C" void __cdecl sub_4e12e0(int, double);

void S::f(int a, double b)
{
    sub_4ea100(a);
    sub_4e12e0(a, b);
}
