// from server: 91% by atomic.potato
struct VirtualHardwareDevice {
    char pad0[60];
    char m_data[512];
    void f(unsigned int index, unsigned char value);
};

void VirtualHardwareDevice::f(unsigned int index, unsigned char value)
{
    if (index < 512)
        m_data[index] = value;
}
