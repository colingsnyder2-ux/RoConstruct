// from server: 31% by atomic.potato
struct VehicleSeat
{
    char pad0[868];
    float m_value;
    void f(float value);
};

void VehicleSeat::f(float value)
{
    if (m_value == value)
    {
        m_value = value;
        *(int*)0x40c080 = 0xb97424;
    }
}
