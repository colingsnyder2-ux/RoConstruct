// from server: 44% by atomic.potato
extern "C" void __cdecl sub_009672e0(double*, void*, int);

struct S
{
    void __cdecl f(double);
};

void __cdecl S::f(double value)
{
    double temp = value;
    sub_009672e0(&temp, this, 3);
}
