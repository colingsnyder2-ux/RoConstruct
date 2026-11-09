// from server: 100% by EspClaude
// roc 2009-06 006cc7e0  unit: RBX::GameTool  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006cc7e0
//
// 006cc7e0  6aff                 push -1
// 006cc7e2  68780e8700           push 0x870e78
// 006cc7e7  64a100000000         mov eax, dword ptr fs:[0]
// 006cc7ed  50                   push eax
// 006cc7ee  64892500000000       mov dword ptr fs:[0], esp
// 006cc7f5  51                   push ecx
// 006cc7f6  56                   push esi
// 006cc7f7  8bf1                 mov esi, ecx
// 006cc7f9  89742404             mov dword ptr [esp + 4], esi
// 006cc7fd  c706b4c78e00         mov dword ptr [esi], 0x8ec7b4
// 006cc803  c746049cc78e00       mov dword ptr [esi + 4], 0x8ec79c
// 006cc80a  8d4e1c               lea ecx, [esi + 0x1c]
// 006cc80d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006cc815  ff15c4e48900         call dword ptr [0x89e4c4]
// 006cc81b  8bce                 mov ecx, esi
// 006cc81d  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 006cc825  e85693feff           call 0x6b5b80
// 006cc82a  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006cc82e  5e                   pop esi
// 006cc82f  64890d00000000       mov dword ptr fs:[0], ecx
// 006cc836  83c410               add esp, 0x10
// 006cc839  c3                   ret 
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
