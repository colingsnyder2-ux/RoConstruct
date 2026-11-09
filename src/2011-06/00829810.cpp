// from server: 100% by tester
struct CXTPToolBar {
    void SetSite(void* p);
    void OnSetSite(void* p);
    char pad[0xd4];
    int m_nSite;
    char pad2[0x184 - 0xd4 - 4];
    int m_nFlag;
};

void CXTPToolBar::OnSetSite(void* p)
{
    if (m_nSite == 0 && p != 0)
        m_nSite = *(int*)((char*)p + 0x20);
    SetSite(p);
    if (m_nFlag == 0)
    {
        void (CXTPToolBar::*fn)(int, int, int) = *(void (CXTPToolBar::**)(int, int, int))((*(char**)this) + 0x148);
        (this->*fn)(1, 1, 0);
    }
}
