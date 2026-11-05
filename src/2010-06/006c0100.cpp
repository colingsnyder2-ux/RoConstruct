// from server: 62% by atomic.potato
struct VirtualHardwareDevice
{
    unsigned char m_data[0x240];
    void f();
};

extern float g_0xa394b0;
extern float g_0xa43788;

void VirtualHardwareDevice::f()
{
    *(float *)(m_data + 0x23c) = g_0xa394b0;
    *(float *)(m_data + 0x240) = g_0xa43788;
}
