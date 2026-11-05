// from server: 100% by atomic.potato
struct VirtualHardwareDevice
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;

    void Initialize();
};

void f();

void VirtualHardwareDevice::Initialize()
{
    m_00 = 0x00a43734;
    m_04 = 0x00a43728;
    m_18 = 0x00a4371c;
    m_1c = 0x00a43710;
    f();
}
