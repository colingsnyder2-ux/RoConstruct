// roc 2012-06 009e87c0  unit: CXTPStatusBarPane  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e87c0
//
// 009e87c0  56                   push esi
// 009e87c1  8bf1                 mov esi, ecx
// 009e87c3  e8169ff9ff           call 0x9826de
// 009e87c8  6a00                 push 0
// 009e87ca  6a01                 push 1
// 009e87cc  8bce                 mov ecx, esi
// 009e87ce  e8bdfcffff           call 0x9e8490
// 009e87d3  8b4620               mov eax, dword ptr [esi + 0x20]
// 009e87d6  6a00                 push 0
// 009e87d8  6a00                 push 0
// 009e87da  50                   push eax
// 009e87db  ff15ec3bb200         call dword ptr [0xb23bec]
// 009e87e1  5e                   pop esi
// 009e87e2  c20c00               ret 0xc
// copied from an identical function in another client (function ?OnSomething@CXTPStatusBar@ns_ROCX00000b@@QAEXHHH@Z)

namespace ns_ROCX00000b {
struct CXTPStatusBar {
    void sub_63023E();
    void sub_6933D0(int, int);
    void OnSomething(int, int, int);
};

extern "C" int (__stdcall *InvalidateRect)(void*, const void*, int);

void CXTPStatusBar::OnSomething(int a, int b, int c)
{
    sub_63023E();
    sub_6933D0(1, 0);
    InvalidateRect(*(void**)((char*)this + 0x20), 0, 0);
}
}
