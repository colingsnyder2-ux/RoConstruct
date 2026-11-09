// from server: 100% by EspClaude
// roc 2007-08 00456110  view OnCreate: CWnd::OnCreate, then create the child window "Roblox" over the client rect (MFC stand-ins)
struct RECT { long left, top, right, bottom; };
struct CREATESTRUCTA;
extern "C" __declspec(dllimport) int __stdcall GetClientRect(void* hWnd, RECT* lpRect);
struct CCreateContext;

class CRect : public RECT { public: CRect() {} };

class CWnd {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22();
    virtual int Create(const char* lpszClassName, const char* lpszWindowName, unsigned long dwStyle,
                       const RECT& rect, CWnd* pParentWnd, unsigned int nID, CCreateContext* pContext = 0);
    char pad[0x1c];
    void* m_hWnd;
    void GetClientRect(RECT* lpRect) const { ::GetClientRect(m_hWnd, lpRect); }
    int OnCreate(CREATESTRUCTA* lpCreateStruct);
};

class CHelpView : public CWnd {
public:
    char pad2[0x64];
    CWnd m_wndChild;
    int OnCreate(CREATESTRUCTA* lpCreateStruct);
};

int CHelpView::OnCreate(CREATESTRUCTA* lpCreateStruct)
{
    if (CWnd::OnCreate(lpCreateStruct) == -1)
        return -1;
    CRect rect;
    GetClientRect(&rect);
    return m_wndChild.Create(0, "Roblox", 0x50000000, rect, this, 1) ? 0 : -1;
}
