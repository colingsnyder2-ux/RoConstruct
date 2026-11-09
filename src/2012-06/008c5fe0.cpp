// from server: 100% by Intel
struct RBX_VirtualHardwareDevice {
    char pad0[0x3c];
    unsigned char f(int a1);
};
unsigned char RBX_VirtualHardwareDevice::f(int a1)
{
    return *(unsigned char*)((char*)this + a1 + 0x3c);
}
