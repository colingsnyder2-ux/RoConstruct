// from server: 100% by Yeetserama
// roc 2010-06 00410d70  unit: CChildFrame  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00410d70
//
// 00410d70  56                   push esi
// 00410d71  8bf1                 mov esi, ecx
// 00410d73  8b4620               mov eax, dword ptr [esi + 0x20]
// 00410d76  50                   push eax
// 00410d77  ff154cba9e00         call dword ptr [0x9eba4c]
// 00410d7d  50                   push eax
// 00410d7e  e8e76e3900           call 0x7a7c6a
// 00410d83  8b4820               mov ecx, dword ptr [eax + 0x20]
// 00410d86  6a05                 push 5
// 00410d88  51                   push ecx
// 00410d89  ff1590ba9e00         call dword ptr [0x9eba90]
// 00410d8f  50                   push eax
// 00410d90  e8d56e3900           call 0x7a7c6a
// 00410d95  3bc6                 cmp eax, esi
// 00410d97  b803000000           mov eax, 3
// 00410d9c  7404                 je 0x410da2
// 00410d9e  8b442408             mov eax, dword ptr [esp + 8]
// 00410da2  50                   push eax
// 00410da3  8bce                 mov ecx, esi
// 00410da5  e86a733900           call 0x7a8114
// 00410daa  5e                   pop esi
// 00410dab  c20400               ret 4
// copied from an identical function in another client (function ?SetChild@CChildFrame@ns_ROCX000007@@QAEXH@Z)

namespace ns_ROCX000007 {
// from server: 100% by atomic.potato
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
