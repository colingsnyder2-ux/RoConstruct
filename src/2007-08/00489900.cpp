// from server: 100% by auto
// roc 2007-08 00489900  unit: RBX::Network::VPlayer::?$Notifier  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00489900
//
// 00489900  83ec08               sub esp, 8
// 00489903  56                   push esi
// 00489904  8bf1                 mov esi, ecx
// 00489906  8b4604               mov eax, dword ptr [esi + 4]
// 00489909  8b08                 mov ecx, dword ptr [eax]
// 0048990b  50                   push eax
// 0048990c  56                   push esi
// 0048990d  51                   push ecx
// 0048990e  56                   push esi
// 0048990f  8d442414             lea eax, [esp + 0x14]
// 00489913  50                   push eax
// 00489914  8bce                 mov ecx, esi
// 00489916  e8a5faffff           call 0x4893c0
// 0048991b  8b4e04               mov ecx, dword ptr [esi + 4]
// 0048991e  51                   push ecx
// 0048991f  e83e631a00           call 0x62fc62
// 00489924  83c404               add esp, 4
// 00489927  33c0                 xor eax, eax
// 00489929  894604               mov dword ptr [esi + 4], eax
// 0048992c  894608               mov dword ptr [esi + 8], eax
// 0048992f  5e                   pop esi
// 00489930  83c408               add esp, 8
// 00489933  c3                   ret 
// standard library set<ptr> (function ?_Tidy@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
