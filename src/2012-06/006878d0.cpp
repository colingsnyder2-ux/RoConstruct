// from server: 85% by atomic.potato
struct S
{
    void f(float);
};

extern "C" void __stdcall sub_686f70(S *, void *, void *, float);

void S::f(float value)
{
    sub_686f70(this, (char *)this + 0x88, (char *)this + 0xb8, value);
}
