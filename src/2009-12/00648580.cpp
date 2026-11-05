// from server: 100% by nuck16
// roc 2009-12 00648580  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 00648580  64a100000000         mov eax, dword ptr fs:[0]
// 00648586  6aff                 push -1
// 00648588  68de179400           push 0x9417de
// 0064858d  50                   push eax
// 0064858e  b801000000           mov eax, 1
// 00648593  64892500000000       mov dword ptr fs:[0], esp
// 0064859a  8405685eb800         test byte ptr [0xb85e68], al
// 006485a0  752e                 jne 0x6485d0
// 006485a2  0905685eb800         or dword ptr [0xb85e68], eax
// 006485a8  68585eb500           push 0xb55e58
// 006485ad  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006485b5  e8269dfeff           call 0x6322e0
// 006485ba  83c404               add esp, 4
// 006485bd  a3645eb800           mov dword ptr [0xb85e64], eax
// 006485c2  8b0c24               mov ecx, dword ptr [esp]
// 006485c5  64890d00000000       mov dword ptr fs:[0], ecx
// 006485cc  83c40c               add esp, 0xc
// 006485cf  c3                   ret 
// 006485d0  8b0c24               mov ecx, dword ptr [esp]
// 006485d3  a1645eb800           mov eax, dword ptr [0xb85e64]
// 006485d8  64890d00000000       mov dword ptr fs:[0], ecx
// 006485df  83c40c               add esp, 0xc
// 006485e2  c3                   ret 

extern char string_00b55e58[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b55e58);
    return *name;
}
