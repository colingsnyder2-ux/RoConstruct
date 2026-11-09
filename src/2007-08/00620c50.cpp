// from server: 100% by auto
// roc 2007-08 00620c50  unit: RBX::ScoreHud  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00620c50
//
// 00620c50  83ec08               sub esp, 8
// 00620c53  56                   push esi
// 00620c54  8bf1                 mov esi, ecx
// 00620c56  8b4604               mov eax, dword ptr [esi + 4]
// 00620c59  8b08                 mov ecx, dword ptr [eax]
// 00620c5b  50                   push eax
// 00620c5c  56                   push esi
// 00620c5d  51                   push ecx
// 00620c5e  56                   push esi
// 00620c5f  8d442414             lea eax, [esp + 0x14]
// 00620c63  50                   push eax
// 00620c64  8bce                 mov ecx, esi
// 00620c66  e8b5ecffff           call 0x61f920
// 00620c6b  8b4e04               mov ecx, dword ptr [esi + 4]
// 00620c6e  51                   push ecx
// 00620c6f  e8eeef0000           call 0x62fc62
// 00620c74  83c404               add esp, 4
// 00620c77  33c0                 xor eax, eax
// 00620c79  894604               mov dword ptr [esi + 4], eax
// 00620c7c  894608               mov dword ptr [esi + 8], eax
// 00620c7f  5e                   pop esi
// 00620c80  83c408               add esp, 8
// 00620c83  c3                   ret 
// standard library set<ptr> (function ?_Tidy@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
