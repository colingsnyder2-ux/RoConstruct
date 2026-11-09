// from server: 100% by colin
struct S {
    void f(double);
};

void S::f(double value)
{
    *(double*)0x00e02410 = value;
}
