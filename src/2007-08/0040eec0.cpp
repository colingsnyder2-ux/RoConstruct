// from server: 100% by EspClaude
// DECLARE_DYNCREATE-style CreateObject analog: new of 0xdc bytes (target push 0xdc),
// base ctor called thiscall (mov ecx,esi; call 0x6303ca), then derived vtable stored.

class CFrameBase
{
public:
    CFrameBase();
    virtual ~CFrameBase();
    char base_[0xdc - 4];
};

class CChildFrame : public CFrameBase
{
public:
    CChildFrame() {}
    virtual ~CChildFrame() {}
    static CFrameBase* __stdcall CreateObject();
};

CFrameBase* __stdcall CChildFrame::CreateObject()
{
    return new CChildFrame;
}
