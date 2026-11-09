// from server: 100% by nuck16
// roc 2009-12 006d3d60  unit: RBX::VVisit::?$BoundFuncDesc  size: 99 bytes
//
// 006d3d60  64a100000000         mov eax, dword ptr fs:[0]
// 006d3d66  6aff                 push -1
// 006d3d68  688ea29400           push 0x94a28e
// 006d3d6d  50                   push eax
// 006d3d6e  b801000000           mov eax, 1
// 006d3d73  64892500000000       mov dword ptr fs:[0], esp
// 006d3d7a  8405442cb900         test byte ptr [0xb92c44], al
// 006d3d80  752e                 jne 0x6d3db0
// 006d3d82  0905442cb900         or dword ptr [0xb92c44], eax
// 006d3d88  68f8a6b300           push 0xb3a6f8
// 006d3d8d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006d3d95  e846e5f5ff           call 0x6322e0
// 006d3d9a  83c404               add esp, 4
// 006d3d9d  a3402cb900           mov dword ptr [0xb92c40], eax
// 006d3da2  8b0c24               mov ecx, dword ptr [esp]
// 006d3da5  64890d00000000       mov dword ptr fs:[0], ecx
// 006d3dac  83c40c               add esp, 0xc
// 006d3daf  c3                   ret 
// 006d3db0  8b0c24               mov ecx, dword ptr [esp]
// 006d3db3  a1402cb900           mov eax, dword ptr [0xb92c40]
// 006d3db8  64890d00000000       mov dword ptr fs:[0], ecx
// 006d3dbf  83c40c               add esp, 0xc
// 006d3dc2  c3                   ret 

extern char string_00b3a6f8[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b3a6f8);
    return *name;
}
