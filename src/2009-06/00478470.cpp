// from server: 100% by auto
// roc 2009-06 00478470  unit: Ogre::RbxMeshLoader  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00478470
//
// 00478470  83ec08               sub esp, 8
// 00478473  56                   push esi
// 00478474  8bf1                 mov esi, ecx
// 00478476  8b4618               mov eax, dword ptr [esi + 0x18]
// 00478479  8b0e                 mov ecx, dword ptr [esi]
// 0047847b  8b10                 mov edx, dword ptr [eax]
// 0047847d  50                   push eax
// 0047847e  51                   push ecx
// 0047847f  52                   push edx
// 00478480  51                   push ecx
// 00478481  8d442414             lea eax, [esp + 0x14]
// 00478485  50                   push eax
// 00478486  8bce                 mov ecx, esi
// 00478488  e843feffff           call 0x4782d0
// 0047848d  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00478490  51                   push ecx
// 00478491  e89c052a00           call 0x718a32
// 00478496  83c404               add esp, 4
// 00478499  33c0                 xor eax, eax
// 0047849b  894618               mov dword ptr [esi + 0x18], eax
// 0047849e  89461c               mov dword ptr [esi + 0x1c], eax
// 004784a1  5e                   pop esi
// 004784a2  83c408               add esp, 8
// 004784a5  c3                   ret 
// standard library set<ptr> (function ?_Tidy@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
