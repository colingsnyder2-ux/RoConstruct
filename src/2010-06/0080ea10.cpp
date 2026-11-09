// from server: 100% by atomic.potato
struct CXTPStatusBar;

struct XTPStatusBarHelper {
    void Draw(CXTPStatusBar* pBar, int a1, int a2, int a3);
};

struct CXTPStatusBar {
    char pad[0xd0];
    XTPStatusBarHelper* m_pHelper;
    void BaseDraw(int a1, int a2, int a3, int a4);
    void Draw(int a1, int a2, int a3, int a4);
};

void CXTPStatusBar::Draw(int a1, int a2, int a3, int a4)
{
    if (m_pHelper != 0)
        m_pHelper->Draw(this, a1, a2, a3);
    BaseDraw(a1, a2, a3, a4);
}
