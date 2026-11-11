// from server: 100% by EspClaude
// from server: 75% by colin
// roc 2007-08 006f57a0  unit: CXTPControlCustom  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006f57a0

// Evidence (target): this+0x170 HWND, this+0xfc parent pointer, this+0x184 flag,
// virtual thiscall slot 0x80 on this taking one int (push 0), parent slot 0x160 no args,
// parent+0x20 = CWnd::m_hWnd (GetSafeHwnd inline), SetWindowPos via IAT.
extern "C" __declspec(dllimport) int __stdcall SetWindowPos(void*, void*, int, int, int, int, unsigned int);

#define V4(n) virtual void v##n##a(); virtual void v##n##b(); virtual void v##n##c(); virtual void v##n##d();

struct CWndLike {
    V4(0) V4(1) V4(2) V4(3) V4(4) V4(5) V4(6) V4(7) V4(8) V4(9) V4(10)
    V4(11) V4(12) V4(13) V4(14) V4(15) V4(16) V4(17) V4(18) V4(19) V4(20) V4(21)
    virtual int IsVisible();             // slot 0x160
    char pad_4[0x1c];
    void* m_hWnd;                        // +0x20
    void* GetSafeHwnd() const { return this == 0 ? 0 : m_hWnd; }
};

struct CXTPControlCustom {
    V4(0) V4(1) V4(2) V4(3) V4(4) V4(5) V4(6) V4(7)
    virtual int IsVisible(unsigned long dwSkipFlags);   // slot 0x80
    char pad_4[0xf8];
    CWndLike* m_pParent;                 // +0xfc
    char pad_100[0x70];
    void* m_hwndClient;                  // +0x170
    char pad_174[0x10];
    int m_bVisible;                      // +0x184
    void Update();
};

void CXTPControlCustom::Update()
{
    if (m_hwndClient)
    {
        unsigned int flags = (m_pParent && m_bVisible && IsVisible(0) &&
            m_pParent->GetSafeHwnd() && m_pParent->IsVisible()) ? 0x40 : 0x80;
        SetWindowPos(m_hwndClient, 0, 0, 0, 0, 0, flags | 0x17);
    }
}
