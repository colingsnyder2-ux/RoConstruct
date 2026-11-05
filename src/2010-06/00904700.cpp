// from server: 100% by auto
// roc 2010-06 00904700  unit: Ogre::RbxSpatialHashedSceneNode::?3??_findVisibleObjects::NodeVisiter  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00904700
//
// 00904700  51                   push ecx
// 00904701  8b542410             mov edx, dword ptr [esp + 0x10]
// 00904705  56                   push esi
// 00904706  8b742410             mov esi, dword ptr [esp + 0x10]
// 0090470a  57                   push edi
// 0090470b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0090470f  c644240800           mov byte ptr [esp + 8], 0
// 00904714  8b442408             mov eax, dword ptr [esp + 8]
// 00904718  50                   push eax
// 00904719  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0090471d  52                   push edx
// 0090471e  83c108               add ecx, 8
// 00904721  51                   push ecx
// 00904722  50                   push eax
// 00904723  56                   push esi
// 00904724  57                   push edi
// 00904725  e876feffff           call 0x9045a0
// 0090472a  8bc6                 mov eax, esi
// 0090472c  83c418               add esp, 0x18
// 0090472f  c1e004               shl eax, 4
// 00904732  03c7                 add eax, edi
// 00904734  5f                   pop edi
// 00904735  5e                   pop esi
// 00904736  59                   pop ecx
// 00904737  c20c00               ret 0xc
// standard library vector<pod16> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
