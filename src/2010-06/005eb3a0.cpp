// from server: 100% by auto
// roc 2010-06 005eb3a0  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005eb3a0
//
// 005eb3a0  83ec08               sub esp, 8
// 005eb3a3  56                   push esi
// 005eb3a4  8bf1                 mov esi, ecx
// 005eb3a6  8b4618               mov eax, dword ptr [esi + 0x18]
// 005eb3a9  8b0e                 mov ecx, dword ptr [esi]
// 005eb3ab  8b10                 mov edx, dword ptr [eax]
// 005eb3ad  50                   push eax
// 005eb3ae  51                   push ecx
// 005eb3af  52                   push edx
// 005eb3b0  51                   push ecx
// 005eb3b1  8d442414             lea eax, [esp + 0x14]
// 005eb3b5  50                   push eax
// 005eb3b6  8bce                 mov ecx, esi
// 005eb3b8  e883feffff           call 0x5eb240
// 005eb3bd  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005eb3c0  51                   push ecx
// 005eb3c1  e8d4c51b00           call 0x7a799a
// 005eb3c6  83c404               add esp, 4
// 005eb3c9  33c0                 xor eax, eax
// 005eb3cb  894618               mov dword ptr [esi + 0x18], eax
// 005eb3ce  89461c               mov dword ptr [esi + 0x1c], eax
// 005eb3d1  5e                   pop esi
// 005eb3d2  83c408               add esp, 8
// 005eb3d5  c3                   ret 
// standard library set<ptr> (function ?_Tidy@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
