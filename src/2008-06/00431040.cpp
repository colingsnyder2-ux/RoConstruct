// from server: 100% by EspClaude
// roc 2008-06 00431040  unit: VCMDIFrameWnd::?$CXTPFrameWndBase  size: 143 bytes

struct FrameA { virtual ~FrameA(); char pad[0x184]; };
struct FrameB { virtual void b(); char pad[0xac]; };
struct FrameC { virtual void c(); };

class VCMDIFrameWnd : public FrameA, public FrameB, public FrameC {
public:
    VCMDIFrameWnd();
    virtual ~VCMDIFrameWnd();
};

class CXTPCommandBars;

template<class TBase>
class CXTPCommandBarsSiteBase : public TBase {
public:
    CXTPCommandBarsSiteBase() {}
protected:
    virtual int PreTranslateMessage(void* pMsg);
};

template<class TBase>
class CXTPFrameWndBase : public CXTPCommandBarsSiteBase<TBase> {
public:
    CXTPFrameWndBase() : m_pCommandBars(0), m_nState(0) {}
    CXTPCommandBars* m_pCommandBars;
    int m_nState;
};

class Listener {
public:
    Listener();
    virtual ~Listener();
    char pad[0x20];
};

class CMainFrame : public CXTPFrameWndBase<VCMDIFrameWnd>, public Listener {
public:
    CMainFrame();
    virtual ~CMainFrame();
};

CMainFrame::CMainFrame()
{
}
