// from server: 100% by EspClaude
// roc 2009-06 0040cfd0  unit: CDeclarationView  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0040cfd0
//
// 0040cfd0  6aff                 push -1
// 0040cfd2  6848d38400           push 0x84d348
// 0040cfd7  64a100000000         mov eax, dword ptr fs:[0]
// 0040cfdd  50                   push eax
// 0040cfde  64892500000000       mov dword ptr fs:[0], esp
// 0040cfe5  51                   push ecx
// 0040cfe6  56                   push esi
// 0040cfe7  8bf1                 mov esi, ecx
// 0040cfe9  89742404             mov dword ptr [esp + 4], esi
// 0040cfed  c7069cdd8a00         mov dword ptr [esi], 0x8add9c
// 0040cff3  8b8ef8000000         mov ecx, dword ptr [esi + 0xf8]
// 0040cff9  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0040d001  85c9                 test ecx, ecx
// 0040d003  7405                 je 0x40d00a
// 0040d005  e89ebf3000           call 0x718fa8
// 0040d00a  8bce                 mov ecx, esi
// 0040d00c  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0040d014  e8a7980500           call 0x4668c0
// 0040d019  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0040d01d  5e                   pop esi
// 0040d01e  64890d00000000       mov dword ptr fs:[0], ecx
// 0040d025  83c410               add esp, 0x10
// 0040d028  c3                   ret 
// copied from an identical function in another client (function ??1CBrowserView@ns_ROCX00007c@@UAE@XZ)

namespace ns_ROCX00007c {
struct B {
    virtual ~B();
};

struct S : B {
    ~S();
};

struct P {
    void release();
};

struct CBrowserView : S {
    char padding[244];
    P* p;
    ~CBrowserView();
};

CBrowserView::~CBrowserView()
{
    if (p)
        p->release();
}
}
