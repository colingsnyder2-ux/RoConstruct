// from server: 31% by atomic.potato
extern "C" double __stdcall sub_005871c0(void*);

struct S
{
    double f();
};

double S::f()
{
    return sub_005871c0(this) * 1.0;
}
