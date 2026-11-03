// from server: 100% by EspClaude
// roc 2007-08 0044d440  ExitCommand::execute: close the main frame, or the document's first view (MFC stand-ins)
extern "C" __declspec(dllimport) int __stdcall PostMessageA(void* hWnd, unsigned int msg, unsigned int wParam, long lParam);
typedef struct __POSITION { } *POSITION;

class CWnd { public: void* vtbl; char pad[0x1c]; void* m_hWnd;
    int PostMessage(unsigned int msg, unsigned int wParam = 0, long lParam = 0) { return ::PostMessageA(m_hWnd, msg, wParam, lParam); } };
class CView : public CWnd {};
class CMainFrame : public CWnd { public: char pad2[0xc8]; bool m_bExeFlag; };
class CWinApp { public: void* vtbl; char pad[0x1c]; CWnd* m_pMainWnd; };
struct AFX_MODULE_STATE { void* vtbl; CWinApp* m_pCurrentWinApp; };
AFX_MODULE_STATE* __stdcall AfxGetModuleState();
inline CWinApp* AfxGetApp() { return AfxGetModuleState()->m_pCurrentWinApp; }

class CDocument {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25();
    virtual POSITION GetFirstViewPosition() const;
    virtual CView* GetNextView(POSITION& rPosition) const;
};

class ExitCommand {
    void* vtbl;
    void* a;
    void* b;
    CDocument* document;
public:
    void doIt(int);
};

void ExitCommand::doIt(int)
{
    CMainFrame* frame = static_cast<CMainFrame*>(AfxGetApp()->m_pMainWnd);
    if (frame->m_bExeFlag) {
        frame->PostMessage(0x10);
        return;
    }
    POSITION pos = document->GetFirstViewPosition();
    if (pos)
        document->GetNextView(pos)->PostMessage(0x111, 0xe102);
}
