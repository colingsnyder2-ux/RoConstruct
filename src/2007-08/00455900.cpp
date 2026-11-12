// from server: 100% by EspClaude
// from server: 60% by Intel
// roc 2007-08 00455900  unit: CRobloxReportView  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00455900
//
// 00455900  51                   push ecx
// 00455901  56                   push esi
// 00455902  8bf1                 mov esi, ecx
// 00455904  e88fa91d00           call 0x630298
// 00455909  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 0045590c  83ec08               sub esp, 8
// 0045590f  85c9                 test ecx, ecx
// 00455911  8bc4                 mov eax, esp
// 00455913  8964240c             mov dword ptr [esp + 0xc], esp
// 00455917  7410                 je 0x455929
// 00455919  50                   push eax
// 0045591a  e811dffaff           call 0x403830
// 0045591f  8bce                 mov ecx, esi
// 00455921  e88afcffff           call 0x4555b0
// 00455926  5e                   pop esi
// 00455927  59                   pop ecx
// 00455928  c3                   ret 
// 00455929  c70000000000         mov dword ptr [eax], 0
// 0045592f  8bce                 mov ecx, esi
// 00455931  c7400400000000       mov dword ptr [eax + 4], 0
// 00455938  e873fcffff           call 0x4555b0
// 0045593d  5e                   pop esi
// 0045593e  59                   pop ecx
// 0045593f  c3                   ret 

// 8-byte smart pointer: built in the outgoing argument slot (sub esp,8),
// returned through a hidden pointer by 0x403830 (ret 4), zeroed at +0/+4.
struct SharedCount
{
    void *pi;
    SharedCount() : pi(0) {}
    SharedCount(const SharedCount &o);
    ~SharedCount();
};

struct SharedPtr
{
    void *px;
    SharedCount pn;
    SharedPtr() : px(0), pn() {}
    SharedPtr(const SharedPtr &o);
    ~SharedPtr();
};

struct Source
{
    SharedPtr get();                  // 0x403830, thiscall
};

struct BaseView
{
    void OnInitialUpdate();           // 0x630298, thiscall on this
};

struct CRobloxReportView : BaseView
{
    unsigned char padding[0x54];
    Source *source;                   // +0x54
    void setSource(SharedPtr p);      // 0x4555b0, thiscall, by-value 8 bytes
    void OnInitialUpdate();
};

void CRobloxReportView::OnInitialUpdate()
{
    BaseView::OnInitialUpdate();
    if (source)
    {
        setSource(source->get());
    }
    else
    {
        setSource(SharedPtr());
    }
}
