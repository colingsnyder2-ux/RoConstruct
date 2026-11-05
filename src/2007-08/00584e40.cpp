// from server: 100% by auto
// roc 2007-08 00584e40  unit: RBX::VHat::?$FactoryProduct  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00584e40
//
// 00584e40  83ec08               sub esp, 8
// 00584e43  56                   push esi
// 00584e44  8bf1                 mov esi, ecx
// 00584e46  8b4604               mov eax, dword ptr [esi + 4]
// 00584e49  8b08                 mov ecx, dword ptr [eax]
// 00584e4b  50                   push eax
// 00584e4c  56                   push esi
// 00584e4d  51                   push ecx
// 00584e4e  56                   push esi
// 00584e4f  8d442414             lea eax, [esp + 0x14]
// 00584e53  50                   push eax
// 00584e54  8bce                 mov ecx, esi
// 00584e56  e8c5fbffff           call 0x584a20
// 00584e5b  8b4e04               mov ecx, dword ptr [esi + 4]
// 00584e5e  51                   push ecx
// 00584e5f  e8fead0a00           call 0x62fc62
// 00584e64  83c404               add esp, 4
// 00584e67  33c0                 xor eax, eax
// 00584e69  894604               mov dword ptr [esi + 4], eax
// 00584e6c  894608               mov dword ptr [esi + 8], eax
// 00584e6f  5e                   pop esi
// 00584e70  83c408               add esp, 8
// 00584e73  c3                   ret 
// standard library set<ptr> (function ?_Tidy@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
