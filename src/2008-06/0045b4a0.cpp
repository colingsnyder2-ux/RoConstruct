// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) int __stdcall InvalidateRect(void *, const void *, int);
namespace G3D {
class GWindow {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
private:
    static const GWindow* m_current;
protected:
    virtual void reallyMakeCurrent() const {}
public:
    inline void makeCurrent() const {
        if (m_current != this) {
            reallyMakeCurrent();
            m_current = this;
        }
    }
};
}
struct UserInput { void processMessage(unsigned int, unsigned int, long); };
class CWnd {
public:
    virtual ~CWnd();
    char reserved0[0x1c];
    void *m_hWnd;
    virtual int OnWndMsg(unsigned int, unsigned int, long, long *);
    CWnd* SetFocus();
    void Invalidate(int bErase = 1) { ::InvalidateRect(m_hWnd, 0, bErase); }
};
class CRobloxWnd : public CWnd {
public:
    char reserved1[0x70 - 0x24];
    void* view;
    char reserved2[0x84 - 0x74];
    UserInput *userInput;
    char reserved3[0xa4 - 0x88];
    G3D::GWindow *window;
    virtual int OnWndMsg(unsigned int, unsigned int, long, long *);
};
int CRobloxWnd::OnWndMsg(unsigned int message, unsigned int wParam, long lParam, long *pResult)
{
    bool handled;
    switch (message) {
    case 7: case 8: case 0x21:
    case 0x100: case 0x101: case 0x102:
    case 0x104: case 0x105: case 0x106:
        handled = false;
        break;
    case 0x201: case 0x204:
        SetFocus();
        *pResult = 0;
        handled = true;
        break;
    case 0x202: case 0x205:
        *pResult = 0;
        handled = false;
        break;
    case 0x203: case 0x206:
        *pResult = 0;
        handled = false;
        break;
    case 0x200: case 0x20a:
        *pResult = 0;
        handled = true;
        break;
    default:
        return CWnd::OnWndMsg(message, wParam, lParam, pResult);
    }

    if (view) {
        window->makeCurrent();
        if (userInput)
            userInput->processMessage(message, wParam, lParam);
        Invalidate();
    }

    if (handled)
        return 1;
    return CWnd::OnWndMsg(message, wParam, lParam, pResult);

}
