// from server: 100% by auto
// roc 2009-06 00486770  unit: Ogre::RbxMeshPartAdapter  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00486770
//
// 00486770  51                   push ecx
// 00486771  8b542410             mov edx, dword ptr [esp + 0x10]
// 00486775  56                   push esi
// 00486776  8b742410             mov esi, dword ptr [esp + 0x10]
// 0048677a  57                   push edi
// 0048677b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0048677f  c644240800           mov byte ptr [esp + 8], 0
// 00486784  8b442408             mov eax, dword ptr [esp + 8]
// 00486788  50                   push eax
// 00486789  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0048678d  52                   push edx
// 0048678e  83c108               add ecx, 8
// 00486791  51                   push ecx
// 00486792  50                   push eax
// 00486793  56                   push esi
// 00486794  57                   push edi
// 00486795  e896fcffff           call 0x486430
// 0048679a  83c418               add esp, 0x18
// 0048679d  8d04f7               lea eax, [edi + esi*8]
// 004867a0  5f                   pop edi
// 004867a1  5e                   pop esi
// 004867a2  59                   pop ecx
// 004867a3  c20c00               ret 0xc
// standard library vector<pod8> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
