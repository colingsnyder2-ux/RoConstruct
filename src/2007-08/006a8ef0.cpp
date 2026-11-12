// from server: 100% by EspClaude
// roc 2007-08 006a8ef0  unit: CXTPRibbonBar  size: 22 bytes
// CXTPRibbonBar::GetGroupsHeight: IsGroupsVisible() ? CalcGroupsHeight() : 0
// IsGroupsVisible (0x6a7bd0) and GetSelectedTab (0x6a7a50) are defined earlier in the same
// unit; offsets read from their target bytes: 0x23c, 0x264, 0x288, [tab+0x17c]; vtable 0x210.
//
// 006a8ef0  e8dbecffff           call 0x6a7bd0
// 006a8ef5  85c0                 test eax, eax
// 006a8ef7  740a                 je 0x6a8f03
// 006a8ef9  8b01                 mov eax, dword ptr [ecx]
// 006a8efb  8b9010020000         mov edx, dword ptr [eax + 0x210]
// 006a8f01  ffe2                 jmp edx
// 006a8f03  33c0                 xor eax, eax
// 006a8f05  c3                   ret 

struct CXTPRibbonTab;

struct CXTPRibbonTabControl {
    char pad0[0x17c];
    CXTPRibbonTab *m_pSelected;
    CXTPRibbonTab *GetSelectedItem() const { return m_pSelected; }
};

struct CXTPRibbonBar {
    void **vfptr;
    char pad4[0x23c - 4];
    int m_bGroupsVisible;            // 0x23c
    char pad240[0x264 - 0x240];
    CXTPRibbonTabControl *m_pControlTab; // 0x264
    char pad268[0x288 - 0x268];
    int m_bMinimized;                // 0x288

    __declspec(noinline) CXTPRibbonTab *GetSelectedTab() const;
    __declspec(noinline) int IsGroupsVisible() const;
    int CalcGroupsHeight() { return (*(int (__thiscall **)(CXTPRibbonBar *))((char *)vfptr + 0x210))(this); }
    int GetGroupsHeight();
};

CXTPRibbonTab *CXTPRibbonBar::GetSelectedTab() const
{
    if (m_pControlTab == 0)
        return 0;
    return m_pControlTab->GetSelectedItem();
}

int CXTPRibbonBar::IsGroupsVisible() const
{
    return m_bGroupsVisible && GetSelectedTab() != 0 && !m_bMinimized;
}

int CXTPRibbonBar::GetGroupsHeight()
{
    return IsGroupsVisible() ? CalcGroupsHeight() : 0;
}
