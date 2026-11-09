// from server: 100% by auto
// roc 2010-06 008f5bd0  unit: Ogre::UTVertexPositionNormalStudsTex::?$SpecializedMeshGen  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008f5bd0
//
// 008f5bd0  51                   push ecx
// 008f5bd1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008f5bd5  8b542410             mov edx, dword ptr [esp + 0x10]
// 008f5bd9  c6042400             mov byte ptr [esp], 0
// 008f5bdd  8b0424               mov eax, dword ptr [esp]
// 008f5be0  50                   push eax
// 008f5be1  8b442414             mov eax, dword ptr [esp + 0x14]
// 008f5be5  51                   push ecx
// 008f5be6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008f5bea  52                   push edx
// 008f5beb  8b542414             mov edx, dword ptr [esp + 0x14]
// 008f5bef  50                   push eax
// 008f5bf0  51                   push ecx
// 008f5bf1  52                   push edx
// 008f5bf2  e8d9d9ffff           call 0x8f35d0
// 008f5bf7  83c41c               add esp, 0x1c
// 008f5bfa  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
