// from server: 100% by auto
// roc 2008-06 004b16a0  unit: RBX::PAVMotor::?$sp_counted_impl_pd  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004b16a0
//
// 004b16a0  6aff                 push -1
// 004b16a2  6828d97b00           push 0x7bd928
// 004b16a7  64a100000000         mov eax, dword ptr fs:[0]
// 004b16ad  50                   push eax
// 004b16ae  64892500000000       mov dword ptr fs:[0], esp
// 004b16b5  83ec0c               sub esp, 0xc
// 004b16b8  56                   push esi
// 004b16b9  8bf1                 mov esi, ecx
// 004b16bb  89742404             mov dword ptr [esp + 4], esi
// 004b16bf  8b4618               mov eax, dword ptr [esi + 0x18]
// 004b16c2  8b0e                 mov ecx, dword ptr [esi]
// 004b16c4  8b10                 mov edx, dword ptr [eax]
// 004b16c6  50                   push eax
// 004b16c7  51                   push ecx
// 004b16c8  52                   push edx
// 004b16c9  51                   push ecx
// 004b16ca  8d442418             lea eax, [esp + 0x18]
// 004b16ce  50                   push eax
// 004b16cf  8bce                 mov ecx, esi
// 004b16d1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004b16d9  e882faffff           call 0x4b1160
// 004b16de  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004b16e1  51                   push ecx
// 004b16e2  e893ef1e00           call 0x6a067a
// 004b16e7  8b16                 mov edx, dword ptr [esi]
// 004b16e9  52                   push edx
// 004b16ea  c7461800000000       mov dword ptr [esi + 0x18], 0
// 004b16f1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004b16f8  e87def1e00           call 0x6a067a
// 004b16fd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004b1701  83c408               add esp, 8
// 004b1704  5e                   pop esi
// 004b1705  64890d00000000       mov dword ptr fs:[0], ecx
// 004b170c  83c418               add esp, 0x18
// 004b170f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
