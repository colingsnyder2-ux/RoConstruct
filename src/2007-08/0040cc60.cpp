// from server: 100% by EspClaude
// roc 2007-08 0040cc60  unit: CChatPrompt
struct HWND__ { int unused; };
typedef HWND__* HWND;
struct HBRUSH__ { int unused; };
typedef HBRUSH__* HBRUSH;
typedef void* HGDIOBJ;
typedef unsigned long COLORREF;
extern "C" __declspec(dllimport) HWND __stdcall GetFocus();
class CObject {
public:
    virtual void* GetRuntimeClass() const;
    virtual ~CObject();
    virtual void Serialize(void* ar);
};
class CDC : public CObject {
public:
    virtual void SetAttribDC(void*); virtual void SetOutputDC(void*);
    virtual void ReleaseAttribDC(); virtual void ReleaseOutputDC();
    virtual int SaveDC(); virtual int RestoreDC(int);
    virtual void* SelectStockObject(int); virtual void* SelectObject(void*);
    virtual void* SelectObjectX(void*); virtual void* SelectObjectY(void*);
    virtual COLORREF SetBkColor(COLORREF crColor);
    virtual COLORREF SetTextColor(COLORREF crColor);
};
class CGdiObject : public CObject {
public:
    HGDIOBJ m_hObject;
    HGDIOBJ GetSafeHandle() const { return this == 0 ? 0 : m_hObject; }
};
class CBrush : public CGdiObject {
public:
    operator HBRUSH() const { return (HBRUSH)(this == 0 ? 0 : m_hObject); }
};
class CWnd {
public:
    static CWnd* __stdcall FromHandle(HWND hWnd);
};
class CChatPrompt : public CWnd {
    char pad[0x94];
    CBrush m_brush;
public:
    HBRUSH CtlColor(CDC* pDC, unsigned int nCtlColor);
};
HBRUSH CChatPrompt::CtlColor(CDC* pDC, unsigned int)
{
    if (CWnd::FromHandle(::GetFocus()) == this) {
        pDC->SetTextColor(0);
        pDC->SetBkColor(0xfae6e6);
    } else {
        pDC->SetTextColor(0xc8ffff);
        pDC->SetBkColor(0x404040);
    }
    return (HBRUSH)m_brush.GetSafeHandle();
}
