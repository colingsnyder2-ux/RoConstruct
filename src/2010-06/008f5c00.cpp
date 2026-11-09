// from server: 100% by auto
// roc 2010-06 008f5c00  unit: Ogre::UTVertexPositionNormalStudsTex::?$SpecializedMeshGen  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008f5c00
//
// 008f5c00  51                   push ecx
// 008f5c01  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008f5c05  8b542410             mov edx, dword ptr [esp + 0x10]
// 008f5c09  c6042400             mov byte ptr [esp], 0
// 008f5c0d  8b0424               mov eax, dword ptr [esp]
// 008f5c10  50                   push eax
// 008f5c11  8b442414             mov eax, dword ptr [esp + 0x14]
// 008f5c15  51                   push ecx
// 008f5c16  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008f5c1a  52                   push edx
// 008f5c1b  8b542414             mov edx, dword ptr [esp + 0x14]
// 008f5c1f  50                   push eax
// 008f5c20  51                   push ecx
// 008f5c21  52                   push edx
// 008f5c22  e899e0ffff           call 0x8f3cc0
// 008f5c27  83c41c               add esp, 0x1c
// 008f5c2a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
