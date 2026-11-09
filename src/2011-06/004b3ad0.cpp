// from server: 93% by atomic.potato
extern "C" void __stdcall sub_004b3a70(void *, double);

struct S
{
    void f(double);
};

void S::f(double value)
{
    sub_004b3a70((char *)this + 0x10, value);
}
