// from server: 100% by auto
// roc 2010-06 008f5b70  unit: Ogre::UTVertexPositionNormalStudsTex::?$SpecializedMeshGen  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008f5b70
//
// 008f5b70  51                   push ecx
// 008f5b71  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008f5b75  8b542410             mov edx, dword ptr [esp + 0x10]
// 008f5b79  c6042400             mov byte ptr [esp], 0
// 008f5b7d  8b0424               mov eax, dword ptr [esp]
// 008f5b80  50                   push eax
// 008f5b81  8b442414             mov eax, dword ptr [esp + 0x14]
// 008f5b85  51                   push ecx
// 008f5b86  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008f5b8a  52                   push edx
// 008f5b8b  8b542414             mov edx, dword ptr [esp + 0x14]
// 008f5b8f  50                   push eax
// 008f5b90  51                   push ecx
// 008f5b91  52                   push edx
// 008f5b92  e8f9cbffff           call 0x8f2790
// 008f5b97  83c41c               add esp, 0x1c
// 008f5b9a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
