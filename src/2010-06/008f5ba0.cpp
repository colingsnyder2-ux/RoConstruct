// from server: 100% by auto
// roc 2010-06 008f5ba0  unit: Ogre::UTVertexPositionNormalStudsTex::?$SpecializedMeshGen  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008f5ba0
//
// 008f5ba0  51                   push ecx
// 008f5ba1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008f5ba5  8b542410             mov edx, dword ptr [esp + 0x10]
// 008f5ba9  c6042400             mov byte ptr [esp], 0
// 008f5bad  8b0424               mov eax, dword ptr [esp]
// 008f5bb0  50                   push eax
// 008f5bb1  8b442414             mov eax, dword ptr [esp + 0x14]
// 008f5bb5  51                   push ecx
// 008f5bb6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008f5bba  52                   push edx
// 008f5bbb  8b542414             mov edx, dword ptr [esp + 0x14]
// 008f5bbf  50                   push eax
// 008f5bc0  51                   push ecx
// 008f5bc1  52                   push edx
// 008f5bc2  e879d2ffff           call 0x8f2e40
// 008f5bc7  83c41c               add esp, 0x1c
// 008f5bca  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
