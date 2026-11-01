// from server: 100% by EspClaude
// roc 2009-06 006b7bb0  unit: RBX::NullTool  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b7bb0
//
// 006b7bb0  6aff                 push -1
// 006b7bb2  68780e8700           push 0x870e78
// 006b7bb7  64a100000000         mov eax, dword ptr fs:[0]
// 006b7bbd  50                   push eax
// 006b7bbe  64892500000000       mov dword ptr fs:[0], esp
// 006b7bc5  51                   push ecx
// 006b7bc6  56                   push esi
// 006b7bc7  8bf1                 mov esi, ecx
// 006b7bc9  89742404             mov dword ptr [esp + 4], esi
// 006b7bcd  c706dcad8e00         mov dword ptr [esi], 0x8eaddc
// 006b7bd3  c74604c4ad8e00       mov dword ptr [esi + 4], 0x8eadc4
// 006b7bda  8d4e1c               lea ecx, [esi + 0x1c]
// 006b7bdd  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006b7be5  ff15c4e48900         call dword ptr [0x89e4c4]
// 006b7beb  8bce                 mov ecx, esi
// 006b7bed  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 006b7bf5  e886dfffff           call 0x6b5b80
// 006b7bfa  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006b7bfe  5e                   pop esi
// 006b7bff  64890d00000000       mov dword ptr fs:[0], ecx
// 006b7c06  83c410               add esp, 0x10
// 006b7c09  c3                   ret 
// copied from an identical function in another client (function ??1S@ns_ROCX000007@@UAE@XZ)

namespace ns_ROCX000007 {
extern void (__thiscall *destroy_string)(void *);

struct Primary {
    virtual ~Primary();
};

struct Secondary {
    virtual ~Secondary();
};

struct Base : Primary, Secondary {
    char data[20];
    virtual ~Base();
};

struct S : Base {
    char string_data[28];
    virtual ~S();
};

S::~S()
{
    destroy_string(string_data);
}
}
