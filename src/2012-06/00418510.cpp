// from server: 100% by Xemicl
// roc 2012-06 00418510  unit: CRbxChildFrame  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00418510
//
// 00418510  56                   push esi
// 00418511  8bf1                 mov esi, ecx
// 00418513  8b4620               mov eax, dword ptr [esi + 0x20]
// 00418516  50                   push eax
// 00418517  ff15503ab200         call dword ptr [0xb23a50]
// 0041851d  50                   push eax
// 0041851e  e843a15600           call 0x982666
// 00418523  8b4820               mov ecx, dword ptr [eax + 0x20]
// 00418526  6a05                 push 5
// 00418528  51                   push ecx
// 00418529  ff15403bb200         call dword ptr [0xb23b40]
// 0041852f  50                   push eax
// 00418530  e831a15600           call 0x982666
// 00418535  3bc6                 cmp eax, esi
// 00418537  b803000000           mov eax, 3
// 0041853c  7404                 je 0x418542
// 0041853e  8b442408             mov eax, dword ptr [esp + 8]
// 00418542  50                   push eax
// 00418543  8bce                 mov ecx, esi
// 00418545  e808a35600           call 0x982852
// 0041854a  5e                   pop esi
// 0041854b  c20400               ret 4
// copied from an identical function in another client (function ?SetChild@CChildFrame@ns_ROCX000009@@QAEXH@Z)

namespace ns_ROCX000009 {
struct CWnd
{
    char pad[0x20];
    void* m_hWnd;
};

struct CChildFrame
{
    char pad[0x20];
    void* m_hWnd;
    void SetChild(int nCmdShow);
    void sub_6A0E0C(int n);
};

extern "C" void* (__stdcall *GetParent)(void*);
extern "C" void* (__stdcall *GetWindow)(void*, unsigned int);

CWnd* __stdcall sub_6A0BDE(void*);

void CChildFrame::SetChild(int nCmdShow)
{
    CWnd* pParent = sub_6A0BDE(GetParent(m_hWnd));
    CWnd* pOwner = sub_6A0BDE(GetWindow(pParent->m_hWnd, 5));
    int n = (pOwner == (CWnd*)this) ? 3 : nCmdShow;
    sub_6A0E0C(n);
}
}