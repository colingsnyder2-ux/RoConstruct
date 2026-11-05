// from server: 60% by atomic.potato
struct CXTIconHandle {
    char pad0[0x14];
    char sub[0x18];
    int m_2c;
    int m_30;
    int m_34;
    CXTIconHandle* Init();
};

extern "C" void __stdcall sub_4035F0(void*);

CXTIconHandle* CXTIconHandle::Init()
{
    sub_4035F0(&sub);
    m_2c = 0;
    m_30 = 0;
    m_34 = 0;
    return this;
}
