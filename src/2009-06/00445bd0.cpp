// from server: 100% by EspClaude
// roc 2009-06 00445bd0  unit: CRbxDocTemplate  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00445bd0
//
// 00445bd0  56                   push esi
// 00445bd1  8bf1                 mov esi, ecx
// 00445bd3  6a01                 push 1
// 00445bd5  b928b0a300           mov ecx, 0xa3b028
// 00445bda  e891f9ffff           call 0x445570
// 00445bdf  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00445be3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00445be7  50                   push eax
// 00445be8  51                   push ecx
// 00445be9  8bce                 mov ecx, esi
// 00445beb  e8c63a2d00           call 0x7196b6
// 00445bf0  5e                   pop esi
// 00445bf1  c20800               ret 8
// copied from an identical function in another client (function ?f@S@ns_ROCX000001@@QAEPAXPBDH@Z)

namespace ns_ROCX000001 {
struct State {
    void set(int);
};

extern State state;

struct S {
    void* f(const char*, int);
    void* base(const char*, int);
};

void* S::f(const char* name, int flag)
{
    state.set(1);
    return base(name, flag);
}
}
