// from server: 100% by atomic.potato
struct VirtualHardwareDevice {
    void f();
};

extern "C" void VirtualHardwareDeviceContinuation();

void VirtualHardwareDevice::f()
{
    *(int *)this = 0x00aa94ac;
    *(int *)((char *)this + 4) = 0x00aa94a0;
    *(int *)((char *)this + 24) = 0x00aa9494;
    *(int *)((char *)this + 28) = 0x00aa9488;
    VirtualHardwareDeviceContinuation();
}
