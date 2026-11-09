// from server: 100% by atomic.potato
struct VirtualHardwareDevice {
    unsigned char m_data[1];

    unsigned char f(unsigned char *p);
};

unsigned char VirtualHardwareDevice::f(unsigned char *p)
{
    return p[(int)this + 0x3c];
}
