// from server: 100% by auto
// roc 2007-08 004cf680  unit: 0RBX::View  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004cf680
//
// 004cf680  83ec08               sub esp, 8
// 004cf683  56                   push esi
// 004cf684  8bf1                 mov esi, ecx
// 004cf686  8b4604               mov eax, dword ptr [esi + 4]
// 004cf689  8b08                 mov ecx, dword ptr [eax]
// 004cf68b  50                   push eax
// 004cf68c  56                   push esi
// 004cf68d  51                   push ecx
// 004cf68e  56                   push esi
// 004cf68f  8d442414             lea eax, [esp + 0x14]
// 004cf693  50                   push eax
// 004cf694  8bce                 mov ecx, esi
// 004cf696  e875f9ffff           call 0x4cf010
// 004cf69b  8b4e04               mov ecx, dword ptr [esi + 4]
// 004cf69e  51                   push ecx
// 004cf69f  e8be051600           call 0x62fc62
// 004cf6a4  83c404               add esp, 4
// 004cf6a7  33c0                 xor eax, eax
// 004cf6a9  894604               mov dword ptr [esi + 4], eax
// 004cf6ac  894608               mov dword ptr [esi + 8], eax
// 004cf6af  5e                   pop esi
// 004cf6b0  83c408               add esp, 8
// 004cf6b3  c3                   ret 
// standard library set<ptr> (function ?_Tidy@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
