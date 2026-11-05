// from server: 100% by auto
// roc 2007-08 00584cb0  unit: RBX::VHat::?$FactoryProduct  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00584cb0
//
// 00584cb0  83ec08               sub esp, 8
// 00584cb3  56                   push esi
// 00584cb4  8bf1                 mov esi, ecx
// 00584cb6  8b4604               mov eax, dword ptr [esi + 4]
// 00584cb9  8b08                 mov ecx, dword ptr [eax]
// 00584cbb  50                   push eax
// 00584cbc  56                   push esi
// 00584cbd  51                   push ecx
// 00584cbe  56                   push esi
// 00584cbf  8d442414             lea eax, [esp + 0x14]
// 00584cc3  50                   push eax
// 00584cc4  8bce                 mov ecx, esi
// 00584cc6  e8d5f5ffff           call 0x5842a0
// 00584ccb  8b4e04               mov ecx, dword ptr [esi + 4]
// 00584cce  51                   push ecx
// 00584ccf  e88eaf0a00           call 0x62fc62
// 00584cd4  83c404               add esp, 4
// 00584cd7  33c0                 xor eax, eax
// 00584cd9  894604               mov dword ptr [esi + 4], eax
// 00584cdc  894608               mov dword ptr [esi + 8], eax
// 00584cdf  5e                   pop esi
// 00584ce0  83c408               add esp, 8
// 00584ce3  c3                   ret 
// standard library set<ptr> (function ?_Tidy@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
