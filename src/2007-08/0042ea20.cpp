// from server: 100% by Yeetserama
// roc 2007-08 0042ea20  unit: MyXTPCommandBars  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0042ea20
//
// 0042ea20  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0042ea24  8b542404             mov edx, dword ptr [esp + 4]
// 0042ea28  56                   push esi
// 0042ea29  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0042ea2d  57                   push edi
// 0042ea2e  50                   push eax
// 0042ea2f  56                   push esi
// 0042ea30  52                   push edx
// 0042ea31  e89a472000           call 0x6331d0
// 0042ea36  81feed030000         cmp esi, 0x3ed
// 0042ea3c  8bf8                 mov edi, eax
// 0042ea3e  750b                 jne 0x42ea4b
// 0042ea40  6a10                 push 0x10
// 0042ea42  8bcf                 mov ecx, edi
// 0042ea44  e8b7032200           call 0x64ee00
// 0042ea49  8bc7                 mov eax, edi
// 0042ea4b  5f                   pop edi
// 0042ea4c  5e                   pop esi
// 0042ea4d  c20c00               ret 0xc
// copied from an identical function in another client (function ?f@S@ns_ROCX00000e@@QAEPAUControl@2@HHH@Z)

namespace ns_ROCX00000e {
// from server: 100% by king_originala
struct Control {
    void f(int value);
};

struct Base {
    Control* f(int a1, int a2, int a3);
};

struct S : Base {
    Control* f(int a1, int a2, int a3);
};

Control* S::f(int a1, int a2, int a3)
{
    Control* result = Base::f(a1, a2, a3);
    if (a2 == 1005)
        result->f(16);
    return result;
}
}
