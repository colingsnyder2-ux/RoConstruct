// from server: 100% by auto
// roc 2010-06 008f5c60  unit: Ogre::UTVertexPositionNormalStudsTex::?$SpecializedMeshGen  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008f5c60
//
// 008f5c60  51                   push ecx
// 008f5c61  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008f5c65  8b542410             mov edx, dword ptr [esp + 0x10]
// 008f5c69  c6042400             mov byte ptr [esp], 0
// 008f5c6d  8b0424               mov eax, dword ptr [esp]
// 008f5c70  50                   push eax
// 008f5c71  8b442414             mov eax, dword ptr [esp + 0x14]
// 008f5c75  51                   push ecx
// 008f5c76  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008f5c7a  52                   push edx
// 008f5c7b  8b542414             mov edx, dword ptr [esp + 0x14]
// 008f5c7f  50                   push eax
// 008f5c80  51                   push ecx
// 008f5c81  52                   push edx
// 008f5c82  e8d9efffff           call 0x8f4c60
// 008f5c87  83c41c               add esp, 0x1c
// 008f5c8a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
