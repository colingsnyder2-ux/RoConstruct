// from server: 59% by atomic.potato
struct CXTPToolBar {
    char pad[0x188];
    float m_f0;
    float m_f1;
    float m_f2;

    void CControlButtonExpand(void* p);
};

extern "C" void __stdcall sub_6b1430(float* p, void* p2);

void CXTPToolBar::CControlButtonExpand(void* p)
{
    float tmp[3];
    tmp[0] = m_f0;
    tmp[1] = m_f1;
    tmp[2] = m_f2;
    sub_6b1430(tmp, p);
}
