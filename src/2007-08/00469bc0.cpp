// from server: 100% by auto
// roc 2007-08 00469bc0  unit: RBX::LDraw2Lua::LDraw2RobloxColorMap  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00469bc0
//
// 00469bc0  83ec08               sub esp, 8
// 00469bc3  56                   push esi
// 00469bc4  8bf1                 mov esi, ecx
// 00469bc6  8b4604               mov eax, dword ptr [esi + 4]
// 00469bc9  8b08                 mov ecx, dword ptr [eax]
// 00469bcb  50                   push eax
// 00469bcc  56                   push esi
// 00469bcd  51                   push ecx
// 00469bce  56                   push esi
// 00469bcf  8d442414             lea eax, [esp + 0x14]
// 00469bd3  50                   push eax
// 00469bd4  8bce                 mov ecx, esi
// 00469bd6  e8c5d7ffff           call 0x4673a0
// 00469bdb  8b4e04               mov ecx, dword ptr [esi + 4]
// 00469bde  51                   push ecx
// 00469bdf  e87e601c00           call 0x62fc62
// 00469be4  83c404               add esp, 4
// 00469be7  33c0                 xor eax, eax
// 00469be9  894604               mov dword ptr [esi + 4], eax
// 00469bec  894608               mov dword ptr [esi + 8], eax
// 00469bef  5e                   pop esi
// 00469bf0  83c408               add esp, 8
// 00469bf3  c3                   ret 
// standard library set<ptr> (function ?_Tidy@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
