// from server: 100% by tester
struct CXTPPopupBar {
    char pad[0xcc];
    int m_nFieldC8;
    int m_nFieldCC;
    void SetSomething();
};

void CXTPPopupBar::SetSomething()
{
    m_nFieldC8 = -1;
    m_nFieldCC = -1;
    typedef void (CXTPPopupBar::*PMF)();
    PMF pmf = *(PMF*)(*(int*)this + 0x184);
    (this->*pmf)();
}
