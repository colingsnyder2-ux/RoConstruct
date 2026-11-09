// from server: 100% by colin
struct CXTPStatusBar {
    char pad[0x20];
    unsigned int m_hWnd;
    char pad2[0xac - 0x24];
    int m_nText;
    int GetIndex(int);
    int SetPaneText(int, int);
    int OnSetText(int);
};

extern "C" int (__stdcall *SendMessageA)(unsigned int, unsigned int, unsigned int, int);

int CXTPStatusBar::OnSetText(int nID)
{
    int nIndex = GetIndex(nID);
    if (nIndex == -1)
        return nIndex;
    SetPaneText((int)(this->pad + 0xac), 0);
    SendMessageA(m_hWnd, 0x408, 0x14, 0);
    return 0;
}
