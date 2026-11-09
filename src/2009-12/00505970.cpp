// from server: 76% by atomic.potato
struct S
{
    void f(double);
};

struct T
{
    int a;
    int b;
    S *c;
    void __cdecl invoke(double);
};

void T::invoke(double value)
{
    (c->*reinterpret_cast<void (S::*)(double)>((void (S::*)())0))(value);
}
