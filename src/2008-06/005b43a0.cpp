// from server: 100% by auto
// roc 2008-06 005b43a0  unit: RBX::VHat::?$FactoryProduct  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b43a0
//
// 005b43a0  6aff                 push -1
// 005b43a2  6828d97b00           push 0x7bd928
// 005b43a7  64a100000000         mov eax, dword ptr fs:[0]
// 005b43ad  50                   push eax
// 005b43ae  64892500000000       mov dword ptr fs:[0], esp
// 005b43b5  83ec0c               sub esp, 0xc
// 005b43b8  56                   push esi
// 005b43b9  8bf1                 mov esi, ecx
// 005b43bb  89742404             mov dword ptr [esp + 4], esi
// 005b43bf  8b4618               mov eax, dword ptr [esi + 0x18]
// 005b43c2  8b0e                 mov ecx, dword ptr [esi]
// 005b43c4  8b10                 mov edx, dword ptr [eax]
// 005b43c6  50                   push eax
// 005b43c7  51                   push ecx
// 005b43c8  52                   push edx
// 005b43c9  51                   push ecx
// 005b43ca  8d442418             lea eax, [esp + 0x18]
// 005b43ce  50                   push eax
// 005b43cf  8bce                 mov ecx, esi
// 005b43d1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 005b43d9  e872fcffff           call 0x5b4050
// 005b43de  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005b43e1  51                   push ecx
// 005b43e2  e893c20e00           call 0x6a067a
// 005b43e7  8b16                 mov edx, dword ptr [esi]
// 005b43e9  52                   push edx
// 005b43ea  c7461800000000       mov dword ptr [esi + 0x18], 0
// 005b43f1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 005b43f8  e87dc20e00           call 0x6a067a
// 005b43fd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005b4401  83c408               add esp, 8
// 005b4404  5e                   pop esi
// 005b4405  64890d00000000       mov dword ptr fs:[0], ecx
// 005b440c  83c418               add esp, 0x18
// 005b440f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
