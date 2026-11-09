// from server: 100% by EspClaude
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
typedef void* HWND; typedef void* HMONITOR; typedef unsigned long DWORD; typedef int BOOL; typedef long LONG; typedef unsigned int UINT;
#define NULL 0
struct RECT { LONG left, top, right, bottom; };
struct MONITORINFOEXA { DWORD cbSize; RECT rcMonitor; RECT rcWork; DWORD dwFlags; char szDevice[32]; };
struct DEVMODEA { char data[156]; };
extern "C" __declspec(dllimport) BOOL __stdcall GetMonitorInfoA(HMONITOR, MONITORINFOEXA*);
extern "C" __declspec(dllimport) LONG __stdcall ChangeDisplaySettingsExA(const char*, DEVMODEA*, HWND, DWORD, void*);
extern "C" __declspec(dllimport) int __stdcall GetSystemMetrics(int);
#define WS_CAPTION 0x00C00000L
#define WS_THICKFRAME 0x00040000L
#define SM_CXBORDER 5
#define SM_CYBORDER 6
#define SWP_NOZORDER 4
#define CDS_FULLSCREEN 4
#define DISP_CHANGE_SUCCESSFUL 0
#include <intrin.h>

namespace boost {
namespace detail {
struct sp_counted_base {
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
};
struct shared_count {
    sp_counted_base* pi_;
    shared_count() : pi_(0) {}
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    T* operator->() const { return px; }
};
}

namespace RBX {
enum MessageType { MESSAGE_OUTPUT, MESSAGE_INFO, MESSAGE_WARNING, MESSAGE_ERROR };
class StandardOut {
public:
    static boost::shared_ptr<StandardOut> singleton();
    void __cdecl print(MessageType type, const char* format, ...);
};
struct Vector2int16 {
    short x, y;
    Vector2int16() {}
};
}

struct Settings { RBX::Vector2int16 getResolution(); };
Settings* __cdecl settings();
DEVMODEA findDisplayMode(const char* device, int pixels);
struct RectSource { RECT getRect(void* wnd); };
RectSource* rectSource();

template<class T> class ScopedAssign {
public:
    ScopedAssign(T& t, T v) : target(t), oldValue(t) { t = v; }
    ~ScopedAssign() { target = oldValue; }
private:
    T& target;
    T oldValue;
};

class CMainFrame {
public:
    virtual ~CMainFrame();
    char pad0[0x1c];
    HWND m_hWnd;
    char pad1[0xfa - 0x24];
    bool m_changingResolution;
    HMONITOR m_hMonitor;
    BOOL ModifyStyle(DWORD dwRemove, DWORD dwAdd, UINT nFlags = 0);
    BOOL SetWindowPos(const CMainFrame* pWndInsertAfter, int x, int y, int cx, int cy, UINT nFlags);
    void ChangeResolution();
};

void CMainFrame::ChangeResolution()
{
    if (m_hMonitor == NULL) {
        RBX::StandardOut::singleton()->print(RBX::MESSAGE_ERROR, "CMainFrame::ChangeResolution hm is NULL");
        return;
    }
    ScopedAssign<bool> assign(m_changingResolution, true);
    MONITORINFOEXA mi;
    mi.cbSize = sizeof(mi);
    if (!GetMonitorInfoA(m_hMonitor, &mi)) {
        RBX::StandardOut::singleton()->print(RBX::MESSAGE_ERROR, "GetMonitorInfo failed");
        return;
    }
    RBX::Vector2int16 res = settings()->getResolution();
    DEVMODEA dm;
    dm = findDisplayMode(mi.szDevice, res.x * res.y);
    LONG result = ChangeDisplaySettingsExA(mi.szDevice, &dm, NULL, CDS_FULLSCREEN, NULL);
    if (result == DISP_CHANGE_SUCCESSFUL) {
        ModifyStyle(WS_CAPTION | WS_THICKFRAME, 0, 0);
        RECT r = rectSource()->getRect(this);
        int cxBorder = GetSystemMetrics(SM_CXBORDER);
        int cyBorder = GetSystemMetrics(SM_CYBORDER);
        SetWindowPos(NULL, r.left - cxBorder, r.top - cyBorder,
                     r.right - r.left + 2 * cxBorder, r.bottom - r.top + 2 * cyBorder, SWP_NOZORDER);
    } else {
        RBX::StandardOut::singleton()->print(RBX::MESSAGE_ERROR, "ChangeDisplaySettings == %d", result);
    }
}
