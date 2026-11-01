// from server: 100% by tester
struct S {
    void f(double);
};

void S::f(double value)
{
    *(double*)0xc58998 = value;
}