// from server: 100% by EspClaude
// roc 2009-06 006cc100  unit: RBX::GrabTool  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006cc100
//
// 006cc100  6aff                 push -1
// 006cc102  68780e8700           push 0x870e78
// 006cc107  64a100000000         mov eax, dword ptr fs:[0]
// 006cc10d  50                   push eax
// 006cc10e  64892500000000       mov dword ptr fs:[0], esp
// 006cc115  51                   push ecx
// 006cc116  56                   push esi
// 006cc117  8bf1                 mov esi, ecx
// 006cc119  89742404             mov dword ptr [esp + 4], esi
// 006cc11d  c706c4c68e00         mov dword ptr [esi], 0x8ec6c4
// 006cc123  c74604acc68e00       mov dword ptr [esi + 4], 0x8ec6ac
// 006cc12a  8d4e1c               lea ecx, [esi + 0x1c]
// 006cc12d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006cc135  ff15c4e48900         call dword ptr [0x89e4c4]
// 006cc13b  8bce                 mov ecx, esi
// 006cc13d  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 006cc145  e8369afeff           call 0x6b5b80
// 006cc14a  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006cc14e  5e                   pop esi
// 006cc14f  64890d00000000       mov dword ptr fs:[0], ecx
// 006cc156  83c410               add esp, 0x10
// 006cc159  c3                   ret 
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
