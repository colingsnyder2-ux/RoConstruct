// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005a0220  unit: RBX::Workspace  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005a0220
//
// 005a0220  8b442404             mov eax, dword ptr [esp + 4]
// 005a0224  8b9188020000         mov edx, dword ptr [ecx + 0x118]
// 005a022a  81c188020000         add ecx, 0x118
// 005a0230  50                   push eax
// 005a0231  8b4204               mov eax, dword ptr [edx + 4]
// 005a0234  ffd0                 call eax
// 005a0236  8bc8                 mov ecx, eax
// 005a0238  e803cc0200           call 0x5cce40
// 005a023d  c20400               ret 4

#include <intrin.h>
// roc 2008-06 005a0220  unit: RBX::Workspace  size: 32 bytes

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Target { void run(); };
struct Inner {
    virtual void slot0();
    virtual Target* slot1(int);
};
struct S {
    char padding[0x118];
    Inner inner;
    void f(volatile int);
};
void S::f(volatile int a)
{
    int argument = a;
    _ReadWriteBarrier();
    inner.slot1(argument)->run();
}
