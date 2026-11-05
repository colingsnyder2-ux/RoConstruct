// from server: 100% by colin
typedef void* NULLPTR;
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
typedef unsigned long DWORD;
typedef int BOOL;
typedef unsigned int UINT;
typedef long LPARAM;
typedef unsigned long WPARAM;
typedef void* LPVOID;
typedef long LRESULT;
typedef const char* LPCTSTR;

struct RECT { long left; long top; long right; long bottom; };

__declspec(dllimport) LRESULT __stdcall SendMessageW(void* hWnd, UINT msg, WPARAM wp, LPARAM lp);

struct CWnd
{
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual BOOL CreateEx(DWORD dwExStyle, LPCTSTR lpszClassName, LPCTSTR lpszWindowName,
                          DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, LPVOID lpParam);
    void* m_pad0[7];
    void* m_hWnd;
    void* m_pad1[12];
    LRESULT SendMessage(UINT message, WPARAM wParam, LPARAM lParam)
    {
        return SendMessageW(m_hWnd, message, wParam, lParam);
    }
};

struct CScintillaCtrl : CWnd
{
    LRESULT m_DirectFunction;
    LRESULT m_DirectPointer;
    BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, DWORD dwExStyle, LPVOID lpParam);
    inline void SetupDirectAccess()
    {
        m_DirectFunction = SendMessage(0x888, 0, 0);
        m_DirectPointer = SendMessage(0x889, 0, 0);
    }
};

BOOL CScintillaCtrl::Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, DWORD dwExStyle, LPVOID lpParam)
{
    BOOL bSuccess = CreateEx(dwExStyle, "scintilla", 0, dwStyle, rect, pParentWnd, nID, lpParam);
    if (bSuccess)
        SetupDirectAccess();
    return bSuccess;
}

