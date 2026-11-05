// from server: 100% by auto
// roc 2008-06 0067d160  unit: Ogre::RbxEntity  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0067d160
//
// 0067d160  51                   push ecx
// 0067d161  8b542410             mov edx, dword ptr [esp + 0x10]
// 0067d165  56                   push esi
// 0067d166  8b742410             mov esi, dword ptr [esp + 0x10]
// 0067d16a  57                   push edi
// 0067d16b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0067d16f  c644240800           mov byte ptr [esp + 8], 0
// 0067d174  8b442408             mov eax, dword ptr [esp + 8]
// 0067d178  50                   push eax
// 0067d179  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0067d17d  52                   push edx
// 0067d17e  83c108               add ecx, 8
// 0067d181  51                   push ecx
// 0067d182  50                   push eax
// 0067d183  56                   push esi
// 0067d184  57                   push edi
// 0067d185  e816f8ffff           call 0x67c9a0
// 0067d18a  8bc6                 mov eax, esi
// 0067d18c  83c418               add esp, 0x18
// 0067d18f  c1e004               shl eax, 4
// 0067d192  03c7                 add eax, edi
// 0067d194  5f                   pop edi
// 0067d195  5e                   pop esi
// 0067d196  59                   pop ecx
// 0067d197  c20c00               ret 0xc
// standard library vector<pod16> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
