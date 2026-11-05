// from server: 100% by tester
extern "C" __declspec(dllimport) long __stdcall SendMessageA(void*, unsigned int, unsigned int, long);

struct CXTPPropertyGridItem {
    char pad0[0x80];
    void* m_pWnd;
    char pad1[0x10];
    void* m_pInPlaceEdit;
    char pad2[0x1c];
    CXTPPropertyGridItem* m_pEdit;
    int sub_69C1E0();
    void sub_698490();
};

void CXTPPropertyGridItem::sub_698490()
{
    if (m_pEdit != 0 && m_pInPlaceEdit != 0) {
        SendMessageA(*(void**)((char*)m_pEdit + 0x20), 0x186, (unsigned int)m_pWnd, 0);
        m_pEdit->sub_69C1E0();
    }
}
