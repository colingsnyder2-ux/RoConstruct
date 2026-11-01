// from server: 100% by auto
// roc 2009-12 00488230  unit: Ogre::GfxClustererPart  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00488230
//
// 00488230  83ec08               sub esp, 8
// 00488233  56                   push esi
// 00488234  8bf1                 mov esi, ecx
// 00488236  8b4618               mov eax, dword ptr [esi + 0x18]
// 00488239  8b0e                 mov ecx, dword ptr [esi]
// 0048823b  8b10                 mov edx, dword ptr [eax]
// 0048823d  50                   push eax
// 0048823e  51                   push ecx
// 0048823f  52                   push edx
// 00488240  51                   push ecx
// 00488241  8d442414             lea eax, [esp + 0x14]
// 00488245  50                   push eax
// 00488246  8bce                 mov ecx, esi
// 00488248  e883feffff           call 0x4880d0
// 0048824d  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00488250  51                   push ecx
// 00488251  e804b63600           call 0x7f385a
// 00488256  83c404               add esp, 4
// 00488259  33c0                 xor eax, eax
// 0048825b  894618               mov dword ptr [esi + 0x18], eax
// 0048825e  89461c               mov dword ptr [esi + 0x1c], eax
// 00488261  5e                   pop esi
// 00488262  83c408               add esp, 8
// 00488265  c3                   ret 
// standard library set<ptr> (function ?_Tidy@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
