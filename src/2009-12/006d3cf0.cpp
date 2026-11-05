// from server: 100% by nuck16
// roc 2009-12 006d3cf0  unit: RBX::VVisit::?$BoundFuncDesc  size: 99 bytes
//
// 006d3cf0  64a100000000         mov eax, dword ptr fs:[0]
// 006d3cf6  6aff                 push -1
// 006d3cf8  686ea29400           push 0x94a26e
// 006d3cfd  50                   push eax
// 006d3cfe  b801000000           mov eax, 1
// 006d3d03  64892500000000       mov dword ptr fs:[0], esp
// 006d3d0a  84053c2cb900         test byte ptr [0xb92c3c], al
// 006d3d10  752e                 jne 0x6d3d40
// 006d3d12  09053c2cb900         or dword ptr [0xb92c3c], eax
// 006d3d18  6804a7b300           push 0xb3a704
// 006d3d1d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006d3d25  e8b6e5f5ff           call 0x6322e0
// 006d3d2a  83c404               add esp, 4
// 006d3d2d  a3382cb900           mov dword ptr [0xb92c38], eax
// 006d3d32  8b0c24               mov ecx, dword ptr [esp]
// 006d3d35  64890d00000000       mov dword ptr fs:[0], ecx
// 006d3d3c  83c40c               add esp, 0xc
// 006d3d3f  c3                   ret 
// 006d3d40  8b0c24               mov ecx, dword ptr [esp]
// 006d3d43  a1382cb900           mov eax, dword ptr [0xb92c38]
// 006d3d48  64890d00000000       mov dword ptr fs:[0], ecx
// 006d3d4f  83c40c               add esp, 0xc
// 006d3d52  c3                   ret 

extern char string_00b3a704[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b3a704);
    return *name;
}
