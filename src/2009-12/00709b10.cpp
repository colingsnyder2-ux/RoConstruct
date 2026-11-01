// from server: 100% by auto
// roc 2009-12 00709b10  unit: std::D::DU?$char_traits::$$A6AXV?$basic_string::?$signal::slot  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00709b10
//
// 00709b10  6aff                 push -1
// 00709b12  68888f9400           push 0x948f88
// 00709b17  64a100000000         mov eax, dword ptr fs:[0]
// 00709b1d  50                   push eax
// 00709b1e  64892500000000       mov dword ptr fs:[0], esp
// 00709b25  83ec0c               sub esp, 0xc
// 00709b28  56                   push esi
// 00709b29  8bf1                 mov esi, ecx
// 00709b2b  89742404             mov dword ptr [esp + 4], esi
// 00709b2f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00709b32  8b0e                 mov ecx, dword ptr [esi]
// 00709b34  8b10                 mov edx, dword ptr [eax]
// 00709b36  50                   push eax
// 00709b37  51                   push ecx
// 00709b38  52                   push edx
// 00709b39  51                   push ecx
// 00709b3a  8d442418             lea eax, [esp + 0x18]
// 00709b3e  50                   push eax
// 00709b3f  8bce                 mov ecx, esi
// 00709b41  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00709b49  e862ebffff           call 0x7086b0
// 00709b4e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00709b51  51                   push ecx
// 00709b52  e8039d0e00           call 0x7f385a
// 00709b57  8b16                 mov edx, dword ptr [esi]
// 00709b59  52                   push edx
// 00709b5a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00709b61  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00709b68  e8ed9c0e00           call 0x7f385a
// 00709b6d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00709b71  83c408               add esp, 8
// 00709b74  5e                   pop esi
// 00709b75  64890d00000000       mov dword ptr fs:[0], ecx
// 00709b7c  83c418               add esp, 0x18
// 00709b7f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
