// from server: 100% by auto
// roc 2007-08 0043a860  unit: IIHAAH::?$CMap  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0043a860
//
// 0043a860  83ec08               sub esp, 8
// 0043a863  56                   push esi
// 0043a864  8bf1                 mov esi, ecx
// 0043a866  8b4604               mov eax, dword ptr [esi + 4]
// 0043a869  8b08                 mov ecx, dword ptr [eax]
// 0043a86b  50                   push eax
// 0043a86c  56                   push esi
// 0043a86d  51                   push ecx
// 0043a86e  56                   push esi
// 0043a86f  8d442414             lea eax, [esp + 0x14]
// 0043a873  50                   push eax
// 0043a874  8bce                 mov ecx, esi
// 0043a876  e845f5ffff           call 0x439dc0
// 0043a87b  8b4e04               mov ecx, dword ptr [esi + 4]
// 0043a87e  51                   push ecx
// 0043a87f  e8de531f00           call 0x62fc62
// 0043a884  83c404               add esp, 4
// 0043a887  33c0                 xor eax, eax
// 0043a889  894604               mov dword ptr [esi + 4], eax
// 0043a88c  894608               mov dword ptr [esi + 8], eax
// 0043a88f  5e                   pop esi
// 0043a890  83c408               add esp, 8
// 0043a893  c3                   ret 
// standard library set<ptr> (function ?_Tidy@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
