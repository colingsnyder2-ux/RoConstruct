// from server: 100% by EspClaude
// MFC DECLARE_DYNCREATE CreateObject: return new CChildFrame (0xdc bytes from the target's
// new argument); base constructor 006303ca is called, then the derived vtable stored.
class CObject;

class CMDIChildWndBase {
public:
    CMDIChildWndBase();
    virtual ~CMDIChildWndBase();
private:
    int m_data[0x36];  // object is 0xdc bytes: vptr + 0xd8
};

class CChildFrame : public CMDIChildWndBase {
public:
    CChildFrame() {}
    virtual ~CChildFrame();
    static CObject* __stdcall CreateObject();
};

CObject* __stdcall CChildFrame::CreateObject()
{
    return (CObject*)new CChildFrame;
}
