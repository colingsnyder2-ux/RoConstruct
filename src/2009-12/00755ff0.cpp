// from server: 75% by atomic.potato
extern "C" void __cdecl sub_0040c080(int);

struct RBX_VehicleSeat
{
    char pad0[872];
    unsigned char field368;
    void f(unsigned char value);
};

void RBX_VehicleSeat::f(unsigned char value)
{
    if (field368 == value)
        return;
    field368 = value;
    sub_0040c080(0x00b973c4);
}
