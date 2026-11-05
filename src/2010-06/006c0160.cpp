// from server: 83% by atomic.potato
struct VirtualHardwareDevice {
    char pad0[572];
    float m_value0;
    float m_value1;
    void f(float* out);
};

void VirtualHardwareDevice::f(float* out)
{
    out[0] = m_value0;
    out[1] = m_value1;
}
