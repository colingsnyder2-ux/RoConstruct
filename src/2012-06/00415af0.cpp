// from server: 100% by Xemicl
// roc 2012-06 00415af0  unit: CDeclarationView  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00415af0
//
// 00415af0  6aff                 push -1
// 00415af2  68584aaa00           push 0xaa4a58
// 00415af7  64a100000000         mov eax, dword ptr fs:[0]
// 00415afd  50                   push eax
// 00415afe  64892500000000       mov dword ptr fs:[0], esp
// 00415b05  51                   push ecx
// 00415b06  56                   push esi
// 00415b07  8bf1                 mov esi, ecx
// 00415b09  89742404             mov dword ptr [esp + 4], esi
// 00415b0d  c706cc51b400         mov dword ptr [esi], 0xb451cc
// 00415b13  8b8ef8000000         mov ecx, dword ptr [esi + 0xf8]
// 00415b19  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00415b21  85c9                 test ecx, ecx
// 00415b23  7405                 je 0x415b2a
// 00415b25  e860cb5600           call 0x98268a
// 00415b2a  8bce                 mov ecx, esi
// 00415b2c  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00415b34  e837f50800           call 0x4a5070
// 00415b39  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00415b3d  5e                   pop esi
// 00415b3e  64890d00000000       mov dword ptr fs:[0], ecx
// 00415b45  83c410               add esp, 0x10
// 00415b48  c3                   ret 
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