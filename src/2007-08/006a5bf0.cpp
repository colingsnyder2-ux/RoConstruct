// from server: 100% by tajop
// roc 2007-08 006a5bf0  unit: CXTPMenuBar::CControlMDIButton  size: 90 bytes

extern "C" __declspec(dllimport) int __stdcall PostMessageA(void*, unsigned int, unsigned int, int);

struct CXTPMenuBar_006a5bf0
{
    void* sub_6A59A0(int);
};

struct CXTPMenuBar__CControlMDIButton
{
    char pad[0x84];
    int m_nId;
    char pad2[0x74];
    CXTPMenuBar_006a5bf0* m_pParent;

    void Method();
};

void CXTPMenuBar__CControlMDIButton::Method()
{
    void* hWnd = m_pParent->sub_6A59A0(0);
    unsigned int cmd = m_nId == 0x23bf ? 0xf060 : m_nId == 0x23c0 ? 0xf120 : 0xf020;
    PostMessageA(hWnd, 0x112, cmd, 0);
}