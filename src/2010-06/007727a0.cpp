// from server: 100% by auto
// roc 2010-06 007727a0  unit: RBX::ScoreHud  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007727a0
//
// 007727a0  6aff                 push -1
// 007727a2  68b8d19b00           push 0x9bd1b8
// 007727a7  64a100000000         mov eax, dword ptr fs:[0]
// 007727ad  50                   push eax
// 007727ae  64892500000000       mov dword ptr fs:[0], esp
// 007727b5  83ec0c               sub esp, 0xc
// 007727b8  56                   push esi
// 007727b9  8bf1                 mov esi, ecx
// 007727bb  89742404             mov dword ptr [esp + 4], esi
// 007727bf  8b4618               mov eax, dword ptr [esi + 0x18]
// 007727c2  8b0e                 mov ecx, dword ptr [esi]
// 007727c4  8b10                 mov edx, dword ptr [eax]
// 007727c6  50                   push eax
// 007727c7  51                   push ecx
// 007727c8  52                   push edx
// 007727c9  51                   push ecx
// 007727ca  8d442418             lea eax, [esp + 0x18]
// 007727ce  50                   push eax
// 007727cf  8bce                 mov ecx, esi
// 007727d1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 007727d9  e852efffff           call 0x771730
// 007727de  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007727e1  51                   push ecx
// 007727e2  e8b3510300           call 0x7a799a
// 007727e7  8b16                 mov edx, dword ptr [esi]
// 007727e9  52                   push edx
// 007727ea  c7461800000000       mov dword ptr [esi + 0x18], 0
// 007727f1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 007727f8  e89d510300           call 0x7a799a
// 007727fd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00772801  83c408               add esp, 8
// 00772804  5e                   pop esi
// 00772805  64890d00000000       mov dword ptr fs:[0], ecx
// 0077280c  83c418               add esp, 0x18
// 0077280f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
