// from server: 100% by auto
// roc 2010-06 00682d00  unit: std::D::DU?$char_traits::$$A6AXV?$basic_string::?$signal::slot  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00682d00
//
// 00682d00  6aff                 push -1
// 00682d02  68b8d19b00           push 0x9bd1b8
// 00682d07  64a100000000         mov eax, dword ptr fs:[0]
// 00682d0d  50                   push eax
// 00682d0e  64892500000000       mov dword ptr fs:[0], esp
// 00682d15  83ec0c               sub esp, 0xc
// 00682d18  56                   push esi
// 00682d19  8bf1                 mov esi, ecx
// 00682d1b  89742404             mov dword ptr [esp + 4], esi
// 00682d1f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00682d22  8b0e                 mov ecx, dword ptr [esi]
// 00682d24  8b10                 mov edx, dword ptr [eax]
// 00682d26  50                   push eax
// 00682d27  51                   push ecx
// 00682d28  52                   push edx
// 00682d29  51                   push ecx
// 00682d2a  8d442418             lea eax, [esp + 0x18]
// 00682d2e  50                   push eax
// 00682d2f  8bce                 mov ecx, esi
// 00682d31  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00682d39  e822e6ffff           call 0x681360
// 00682d3e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00682d41  51                   push ecx
// 00682d42  e8534c1200           call 0x7a799a
// 00682d47  8b16                 mov edx, dword ptr [esi]
// 00682d49  52                   push edx
// 00682d4a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00682d51  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00682d58  e83d4c1200           call 0x7a799a
// 00682d5d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00682d61  83c408               add esp, 8
// 00682d64  5e                   pop esi
// 00682d65  64890d00000000       mov dword ptr fs:[0], ecx
// 00682d6c  83c418               add esp, 0x18
// 00682d6f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
