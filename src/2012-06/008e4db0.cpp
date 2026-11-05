// from server: 32% by atomic.potato
extern "C" void __cdecl SetVehicleSeatValue(unsigned int);

struct S
{
    void f(float);
};

void S::f(float value)
{
    if (!(*(float *)((char *)this + 0x398) == value))
    {
        *(float *)((char *)this + 0x398) = value;
        SetVehicleSeatValue(0x00e55a44);
    }
}
