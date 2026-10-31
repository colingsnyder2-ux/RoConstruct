// from server: 100% by EspClaude
// roc 2009-06 00460c70  unit: Scintilla::CScintillaCtrl  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00460c70
//
// 00460c70  6aff                 push -1
// 00460c72  68682b8500           push 0x852b68
// 00460c77  64a100000000         mov eax, dword ptr fs:[0]
// 00460c7d  50                   push eax
// 00460c7e  64892500000000       mov dword ptr fs:[0], esp
// 00460c85  51                   push ecx
// 00460c86  56                   push esi
// 00460c87  8bf1                 mov esi, ecx
// 00460c89  89742404             mov dword ptr [esp + 4], esi
// 00460c8d  c70614b18b00         mov dword ptr [esi], 0x8bb114
// 00460c93  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00460c9b  e8167e2b00           call 0x718ab6
// 00460ca0  8bce                 mov ecx, esi
// 00460ca2  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00460caa  e839882b00           call 0x7194e8
// 00460caf  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00460cb3  5e                   pop esi
// 00460cb4  64890d00000000       mov dword ptr fs:[0], ecx
// 00460cbb  83c410               add esp, 0x10
// 00460cbe  c3                   ret 
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
