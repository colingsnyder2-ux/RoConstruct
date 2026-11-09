// from server: 100% by auto
// roc 2007-08 004f2290  unit: RBX::Render::AggregatingSceneManager  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004f2290
//
// 004f2290  83ec08               sub esp, 8
// 004f2293  56                   push esi
// 004f2294  8bf1                 mov esi, ecx
// 004f2296  8b4604               mov eax, dword ptr [esi + 4]
// 004f2299  8b08                 mov ecx, dword ptr [eax]
// 004f229b  50                   push eax
// 004f229c  56                   push esi
// 004f229d  51                   push ecx
// 004f229e  56                   push esi
// 004f229f  8d442414             lea eax, [esp + 0x14]
// 004f22a3  50                   push eax
// 004f22a4  8bce                 mov ecx, esi
// 004f22a6  e8e5f9ffff           call 0x4f1c90
// 004f22ab  8b4e04               mov ecx, dword ptr [esi + 4]
// 004f22ae  51                   push ecx
// 004f22af  e8aed91300           call 0x62fc62
// 004f22b4  83c404               add esp, 4
// 004f22b7  33c0                 xor eax, eax
// 004f22b9  894604               mov dword ptr [esi + 4], eax
// 004f22bc  894608               mov dword ptr [esi + 8], eax
// 004f22bf  5e                   pop esi
// 004f22c0  83c408               add esp, 8
// 004f22c3  c3                   ret 
// standard library set<ptr> (function ?_Tidy@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
