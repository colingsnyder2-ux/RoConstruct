// from server: 62% by atomic.potato
struct VirtualHardwareDevice {
    char pad0[572];
    float m_value23c;
    float m_value240;
    void f();
};

float g_value_a9bd40;
float g_value_a888bc;

void VirtualHardwareDevice::f()
{
    m_value23c = g_value_a9bd40;
    m_value240 = g_value_a888bc;
}
