// from server: 100% by auto
// roc 2009-12 004be1f0  unit: Ogre::RbxSpatialHashedSceneNode::?1??_findVisibleObjects::NodeVisiter  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004be1f0
//
// 004be1f0  51                   push ecx
// 004be1f1  8b542410             mov edx, dword ptr [esp + 0x10]
// 004be1f5  56                   push esi
// 004be1f6  8b742410             mov esi, dword ptr [esp + 0x10]
// 004be1fa  57                   push edi
// 004be1fb  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004be1ff  c644240800           mov byte ptr [esp + 8], 0
// 004be204  8b442408             mov eax, dword ptr [esp + 8]
// 004be208  50                   push eax
// 004be209  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004be20d  52                   push edx
// 004be20e  83c108               add ecx, 8
// 004be211  51                   push ecx
// 004be212  50                   push eax
// 004be213  56                   push esi
// 004be214  57                   push edi
// 004be215  e836fdffff           call 0x4bdf50
// 004be21a  8bc6                 mov eax, esi
// 004be21c  83c418               add esp, 0x18
// 004be21f  c1e004               shl eax, 4
// 004be222  03c7                 add eax, edi
// 004be224  5f                   pop edi
// 004be225  5e                   pop esi
// 004be226  59                   pop ecx
// 004be227  c20c00               ret 0xc
// standard library vector<pod16> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
