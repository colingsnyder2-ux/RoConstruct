// from server: 100% by auto
// roc 2009-06 00482f50  unit: Ogre::RbxSpatialHashedSceneNode::?1??_findVisibleObjects::NodeVisiter  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00482f50
//
// 00482f50  51                   push ecx
// 00482f51  8b542410             mov edx, dword ptr [esp + 0x10]
// 00482f55  56                   push esi
// 00482f56  8b742410             mov esi, dword ptr [esp + 0x10]
// 00482f5a  57                   push edi
// 00482f5b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00482f5f  c644240800           mov byte ptr [esp + 8], 0
// 00482f64  8b442408             mov eax, dword ptr [esp + 8]
// 00482f68  50                   push eax
// 00482f69  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00482f6d  52                   push edx
// 00482f6e  83c108               add ecx, 8
// 00482f71  51                   push ecx
// 00482f72  50                   push eax
// 00482f73  56                   push esi
// 00482f74  57                   push edi
// 00482f75  e8c6250000           call 0x485540
// 00482f7a  8bc6                 mov eax, esi
// 00482f7c  83c418               add esp, 0x18
// 00482f7f  c1e004               shl eax, 4
// 00482f82  03c7                 add eax, edi
// 00482f84  5f                   pop edi
// 00482f85  5e                   pop esi
// 00482f86  59                   pop ecx
// 00482f87  c20c00               ret 0xc
// standard library vector<pod16> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
