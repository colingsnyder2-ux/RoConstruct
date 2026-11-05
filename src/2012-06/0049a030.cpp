// from server: 54% by atomic.potato
struct S
{
    double value;
    int f();
};

extern "C" double __cdecl sub_499fe0(double* value);
extern "C" void sub_759e60(S* object, const double* value);

int S::f()
{
    double value = sub_499fe0((double*)((char*)this + 0xa8));
    sub_759e60(this, &value);
    return 0;
}
