// from server: 77% by atomic.potato
extern "C" void __cdecl sub_0058e7a0(void*, double*);

struct S
{
    double f();
};

double S::f()
{
    double value;
    sub_0058e7a0((char*)this + 0x120, &value);
    if (value > 0.0)
        return 1.0 / value;
    return 0.0;
}
