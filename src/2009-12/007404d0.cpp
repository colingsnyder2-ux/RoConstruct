// from server: 80% by atomic.potato
struct VirtualHardwareDevice
{
    char pad0[60];
    void f(unsigned int index, unsigned char value);
};

void VirtualHardwareDevice::f(unsigned int index, unsigned char value)
{
    if (index < 512)
        pad0[index] = value;
}
