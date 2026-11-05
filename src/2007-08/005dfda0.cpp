// from server: 100% by auto
// roc 2007-08 005dfda0  unit: RBX::VMotorFeature::?$FactoryProduct  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005dfda0
//
// 005dfda0  83ec08               sub esp, 8
// 005dfda3  56                   push esi
// 005dfda4  8bf1                 mov esi, ecx
// 005dfda6  8b4604               mov eax, dword ptr [esi + 4]
// 005dfda9  8b08                 mov ecx, dword ptr [eax]
// 005dfdab  50                   push eax
// 005dfdac  56                   push esi
// 005dfdad  51                   push ecx
// 005dfdae  56                   push esi
// 005dfdaf  8d442414             lea eax, [esp + 0x14]
// 005dfdb3  50                   push eax
// 005dfdb4  8bce                 mov ecx, esi
// 005dfdb6  e8e5fbffff           call 0x5df9a0
// 005dfdbb  8b4e04               mov ecx, dword ptr [esi + 4]
// 005dfdbe  51                   push ecx
// 005dfdbf  e89efe0400           call 0x62fc62
// 005dfdc4  83c404               add esp, 4
// 005dfdc7  33c0                 xor eax, eax
// 005dfdc9  894604               mov dword ptr [esi + 4], eax
// 005dfdcc  894608               mov dword ptr [esi + 8], eax
// 005dfdcf  5e                   pop esi
// 005dfdd0  83c408               add esp, 8
// 005dfdd3  c3                   ret 
// standard library set<ptr> (function ?_Tidy@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
