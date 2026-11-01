// from server: 100% by colin
extern "C" __declspec(dllimport) long __stdcall SendMessageA(void* hWnd, unsigned int Msg, unsigned int wParam, long lParam);

struct CXTPPropertyGridItem {
    char pad0[0x80];
    void* m_pWnd;
    char pad1[0x30];
    void* m_pGrid;
    long SetValue(void* pValue);
};

long CXTPPropertyGridItem::SetValue(void* pValue)
{
    void* wnd = *(void**)((char*)m_pGrid + 0x20);
    SendMessageA(wnd, 0x198, (unsigned int)m_pWnd, (long)pValue);
    return (long)pValue;
}
