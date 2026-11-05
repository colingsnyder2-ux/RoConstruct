// from server: 35% by atomic.potato
struct VehicleSeat
{
    float value;
    void update(float);
};

void VehicleSeat::update(float v)
{
    if (value != v)
    {
        value = v;
        typedef void (__cdecl *Callback)(int);
        Callback f = (Callback)0x411f60;
        f(0xcd3878);
    }
}
