// from server: 100% by EspClaude
// MFC DECLARE_DYNCREATE CreateObject: return new CBrowserFrameWnd (0xd8 bytes from the
// target's new argument); base constructor 0066aaf0 is called, then the derived vtable stored.
class CObject;

class CFrameWndBase {
public:
    CFrameWndBase();
    virtual ~CFrameWndBase();
private:
    int m_data[0x35];  // object is 0xd8 bytes: vptr + 0xd4
};

class CBrowserFrameWnd : public CFrameWndBase {
public:
    CBrowserFrameWnd() {}
    virtual ~CBrowserFrameWnd();
    static CObject* __stdcall CreateObject();
};

CObject* __stdcall CBrowserFrameWnd::CreateObject()
{
    return (CObject*)new CBrowserFrameWnd;
}
