// from server: 100% by auto
// roc 2007-08 0062a840  unit: RBX::AssemblyStage  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0062a840
//
// 0062a840  83ec08               sub esp, 8
// 0062a843  56                   push esi
// 0062a844  8bf1                 mov esi, ecx
// 0062a846  8b4604               mov eax, dword ptr [esi + 4]
// 0062a849  8b08                 mov ecx, dword ptr [eax]
// 0062a84b  50                   push eax
// 0062a84c  56                   push esi
// 0062a84d  51                   push ecx
// 0062a84e  56                   push esi
// 0062a84f  8d442414             lea eax, [esp + 0x14]
// 0062a853  50                   push eax
// 0062a854  8bce                 mov ecx, esi
// 0062a856  e815ffffff           call 0x62a770
// 0062a85b  8b4e04               mov ecx, dword ptr [esi + 4]
// 0062a85e  51                   push ecx
// 0062a85f  e8fe530000           call 0x62fc62
// 0062a864  83c404               add esp, 4
// 0062a867  33c0                 xor eax, eax
// 0062a869  894604               mov dword ptr [esi + 4], eax
// 0062a86c  894608               mov dword ptr [esi + 8], eax
// 0062a86f  5e                   pop esi
// 0062a870  83c408               add esp, 8
// 0062a873  c3                   ret 
// standard library set<ptr> (function ?_Tidy@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
