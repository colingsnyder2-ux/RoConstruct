// from server: 100% by EspClaude
// roc 2009-06 00410e20  unit: CChildFrame  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00410e20
//
// 00410e20  56                   push esi
// 00410e21  8bf1                 mov esi, ecx
// 00410e23  8b4620               mov eax, dword ptr [esi + 0x20]
// 00410e26  50                   push eax
// 00410e27  ff1598ee8900         call dword ptr [0x89ee98]
// 00410e2d  50                   push eax
// 00410e2e  e8cf7e3000           call 0x718d02
// 00410e33  8b4820               mov ecx, dword ptr [eax + 0x20]
// 00410e36  6a05                 push 5
// 00410e38  51                   push ecx
// 00410e39  ff1568ee8900         call dword ptr [0x89ee68]
// 00410e3f  50                   push eax
// 00410e40  e8bd7e3000           call 0x718d02
// 00410e45  3bc6                 cmp eax, esi
// 00410e47  b803000000           mov eax, 3
// 00410e4c  7404                 je 0x410e52
// 00410e4e  8b442408             mov eax, dword ptr [esp + 8]
// 00410e52  50                   push eax
// 00410e53  8bce                 mov ecx, esi
// 00410e55  e852833000           call 0x7191ac
// 00410e5a  5e                   pop esi
// 00410e5b  c20400               ret 4
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
