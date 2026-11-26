// from server: 100% by Xemicl
// roc 2012-06 0049c910  unit: Scintilla::CScintillaCtrl  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0049c910
//
// 0049c910  6aff                 push -1
// 0049c912  68383aaa00           push 0xaa3a38
// 0049c917  64a100000000         mov eax, dword ptr fs:[0]
// 0049c91d  50                   push eax
// 0049c91e  64892500000000       mov dword ptr fs:[0], esp
// 0049c925  51                   push ecx
// 0049c926  56                   push esi
// 0049c927  8bf1                 mov esi, ecx
// 0049c929  89742404             mov dword ptr [esp + 4], esi
// 0049c92d  c70684fcb500         mov dword ptr [esi], 0xb5fc84
// 0049c933  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0049c93b  e858584e00           call 0x982198
// 0049c940  8bce                 mov ecx, esi
// 0049c942  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0049c94a  e851624e00           call 0x982ba0
// 0049c94f  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0049c953  5e                   pop esi
// 0049c954  64890d00000000       mov dword ptr fs:[0], ecx
// 0049c95b  83c410               add esp, 0x10
// 0049c95e  c3                   ret 
// copied from an identical function in another client (function ??1S@ns_ROCX00005e@@UAE@XZ)

namespace ns_ROCX00005e {
struct Base {
    virtual ~Base();
    void cleanup();
};

struct S : Base {
    virtual ~S();
};

S::~S()
{
    cleanup();
}
}