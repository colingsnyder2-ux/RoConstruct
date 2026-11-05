// from server: 35% by atomic.potato
extern "C" void __stdcall Function_0040c080(int);

struct VehicleSeat_00756020
{
    float m_value;
    int f(float value);
};

int VehicleSeat_00756020::f(float value)
{
    if (m_value == value || m_value < value)
        return 0;

    m_value = value;
    Function_0040c080(0x00b973e4);
    return 0;
}
