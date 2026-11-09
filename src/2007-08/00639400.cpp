// from server: 100% by colin
// roc 2007-08 00639400  unit: seg_00630000  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00639400

extern "C" void* (__stdcall *GetFocus)();
extern "C" int (__stdcall *SendMessageA)(void* hWnd, unsigned int Msg, unsigned int wParam, int lParam);

struct CXTPControlComboBoxList {
    char pad[0x20];
    void* m_hWnd;
    char pad2[0x5c - 0x24];
    void* m_pCombo;
    void OnFocusChanged();
    void Tail();
};

void CXTPControlComboBoxList::OnFocusChanged()
{
    *(int*)((char*)m_pCombo + 0x1c0) = 1;
    if (GetFocus() == m_hWnd)
    {
        void** vtbl = *(void***)m_pCombo;
        void (__thiscall *fn)(void*) = *(void (__thiscall **)(void*))((char*)vtbl + 0x158);
        fn(m_pCombo);
    }
    SendMessageA(m_hWnd, 0xd3, 3, 0);
    Tail();
}
