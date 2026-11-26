// from server: 100% by Xemicl
// roc 2012-06 00473d90  unit: CRbxDocTemplate  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00473d90
//
// 00473d90  56                   push esi
// 00473d91  8bf1                 mov esi, ecx
// 00473d93  6a01                 push 1
// 00473d95  b9d0a0e100           mov ecx, 0xe1a0d0
// 00473d9a  e8e1fbffff           call 0x473980
// 00473d9f  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00473da3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00473da7  50                   push eax
// 00473da8  51                   push ecx
// 00473da9  8bce                 mov ecx, esi
// 00473dab  e848f05000           call 0x982df8
// 00473db0  5e                   pop esi
// 00473db1  c20800               ret 8
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