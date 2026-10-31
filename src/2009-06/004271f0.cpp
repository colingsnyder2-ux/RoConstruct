// from server: 100% by EspClaude
// roc 2009-06 004271f0  unit: MyXTPCommandBars  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004271f0
//
// 004271f0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004271f4  8b542404             mov edx, dword ptr [esp + 4]
// 004271f8  56                   push esi
// 004271f9  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004271fd  57                   push edi
// 004271fe  50                   push eax
// 004271ff  56                   push esi
// 00427200  52                   push edx
// 00427201  e8ba353000           call 0x72a7c0
// 00427206  8bf8                 mov edi, eax
// 00427208  81feed030000         cmp esi, 0x3ed
// 0042720e  750b                 jne 0x42721b
// 00427210  6a10                 push 0x10
// 00427212  8bcf                 mov ecx, edi
// 00427214  e8b7313100           call 0x73a3d0
// 00427219  8bc7                 mov eax, edi
// 0042721b  5f                   pop edi
// 0042721c  5e                   pop esi
// 0042721d  c20c00               ret 0xc
// copied from an identical function in another client (function ?f@S@ns_ROCX0000d6@@QAEPAUControl@2@HHH@Z)

namespace ns_ROCX0000d6 {
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
