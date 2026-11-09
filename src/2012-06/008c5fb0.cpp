// from server: 62% by atomic.potato
struct VirtualHardwareDevice {
    char pad0[572];
    float m_23c;
    float m_240;
    void f();
};

extern float g_00b8f750;
extern float g_00b685d4;

void VirtualHardwareDevice::f()
{
    m_23c = g_00b8f750;
    m_240 = g_00b685d4;
}
