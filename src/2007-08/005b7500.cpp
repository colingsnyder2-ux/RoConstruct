// from server: 100% by auto
// roc 2007-08 005b7500  unit: RBX::$01MP8Surface::?$SurfaceGetSet  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005b7500
//
// 005b7500  83ec08               sub esp, 8
// 005b7503  56                   push esi
// 005b7504  8bf1                 mov esi, ecx
// 005b7506  8b4604               mov eax, dword ptr [esi + 4]
// 005b7509  8b08                 mov ecx, dword ptr [eax]
// 005b750b  50                   push eax
// 005b750c  56                   push esi
// 005b750d  51                   push ecx
// 005b750e  56                   push esi
// 005b750f  8d442414             lea eax, [esp + 0x14]
// 005b7513  50                   push eax
// 005b7514  8bce                 mov ecx, esi
// 005b7516  e815ffffff           call 0x5b7430
// 005b751b  8b4e04               mov ecx, dword ptr [esi + 4]
// 005b751e  51                   push ecx
// 005b751f  e83e870700           call 0x62fc62
// 005b7524  83c404               add esp, 4
// 005b7527  33c0                 xor eax, eax
// 005b7529  894604               mov dword ptr [esi + 4], eax
// 005b752c  894608               mov dword ptr [esi + 8], eax
// 005b752f  5e                   pop esi
// 005b7530  83c408               add esp, 8
// 005b7533  c3                   ret 
// standard library set<ptr> (function ?_Tidy@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
