// from server: 100% by tester
struct CXTPPopupBarInner {
    char pad[0xfc];
    int m_value;
};

struct CXTPPopupBar {
    char pad[0x180];
    CXTPPopupBarInner* m_ptr;
    int GetValue();
};

int CXTPPopupBar::GetValue()
{
    CXTPPopupBarInner* p = m_ptr;
    if (p)
        return p->m_value;
    return 0;
}
