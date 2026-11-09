// from server: 100% by auto
// roc 2010-06 008f5c30  unit: Ogre::UTVertexPositionNormalStudsTex::?$SpecializedMeshGen  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008f5c30
//
// 008f5c30  51                   push ecx
// 008f5c31  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008f5c35  8b542410             mov edx, dword ptr [esp + 0x10]
// 008f5c39  c6042400             mov byte ptr [esp], 0
// 008f5c3d  8b0424               mov eax, dword ptr [esp]
// 008f5c40  50                   push eax
// 008f5c41  8b442414             mov eax, dword ptr [esp + 0x14]
// 008f5c45  51                   push ecx
// 008f5c46  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008f5c4a  52                   push edx
// 008f5c4b  8b542414             mov edx, dword ptr [esp + 0x14]
// 008f5c4f  50                   push eax
// 008f5c50  51                   push ecx
// 008f5c51  52                   push edx
// 008f5c52  e8e9e7ffff           call 0x8f4440
// 008f5c57  83c41c               add esp, 0x1c
// 008f5c5a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
