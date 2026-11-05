// from server: 90% by atomic.potato
struct RBX_VirtualHardwareDevice
{
    void f();
};

void RBX_VirtualHardwareDevice::f()
{
    *(int*)((char*)this + 0) = 0x00be6564;
    *(int*)((char*)this + 4) = 0x00be655c;
    *(int*)((char*)this + 0x18) = 0x00be6550;
    *(int*)((char*)this + 0x1c) = 0x00be6544;
}
