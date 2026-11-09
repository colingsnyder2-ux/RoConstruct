// from server: 100% by auto
// roc 2008-06 005b3fe0  unit: RBX::VHat::?$FactoryProduct  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b3fe0
//
// 005b3fe0  6aff                 push -1
// 005b3fe2  6828d97b00           push 0x7bd928
// 005b3fe7  64a100000000         mov eax, dword ptr fs:[0]
// 005b3fed  50                   push eax
// 005b3fee  64892500000000       mov dword ptr fs:[0], esp
// 005b3ff5  83ec0c               sub esp, 0xc
// 005b3ff8  56                   push esi
// 005b3ff9  8bf1                 mov esi, ecx
// 005b3ffb  89742404             mov dword ptr [esp + 4], esi
// 005b3fff  8b4618               mov eax, dword ptr [esi + 0x18]
// 005b4002  8b0e                 mov ecx, dword ptr [esi]
// 005b4004  8b10                 mov edx, dword ptr [eax]
// 005b4006  50                   push eax
// 005b4007  51                   push ecx
// 005b4008  52                   push edx
// 005b4009  51                   push ecx
// 005b400a  8d442418             lea eax, [esp + 0x18]
// 005b400e  50                   push eax
// 005b400f  8bce                 mov ecx, esi
// 005b4011  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 005b4019  e882f4ffff           call 0x5b34a0
// 005b401e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005b4021  51                   push ecx
// 005b4022  e853c60e00           call 0x6a067a
// 005b4027  8b16                 mov edx, dword ptr [esi]
// 005b4029  52                   push edx
// 005b402a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 005b4031  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 005b4038  e83dc60e00           call 0x6a067a
// 005b403d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005b4041  83c408               add esp, 8
// 005b4044  5e                   pop esi
// 005b4045  64890d00000000       mov dword ptr fs:[0], ecx
// 005b404c  83c418               add esp, 0x18
// 005b404f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
