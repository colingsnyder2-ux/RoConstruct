// from server: 83% by atomic.potato
extern "C" void __stdcall sub_00622f70(int);

struct PrismBuilder
{
    PrismBuilder *f(int);
};

PrismBuilder *PrismBuilder::f(int a1)
{
    sub_00622f70(a1);
    *(int *)((char *)this + 0x28) = 0xc2;
    *(volatile float *)((char *)this + 0x2c) = 0.0f;
    return this;
}
