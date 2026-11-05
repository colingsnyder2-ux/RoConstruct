// from server: 100% by colin
struct CXTSplitterWnd {
    char m_pad[0x20];
    void* m_hWnd;
    void SetRowInfo(int, int, int);
};

extern "C" int (__stdcall *g_pfnInvalidateRect)(void*, const void*, int);

void CXTSplitterWnd::SetRowInfo(int a, int b, int c)
{
    SetRowInfo(a, b, c);
    g_pfnInvalidateRect(m_hWnd, 0, 1);
}
