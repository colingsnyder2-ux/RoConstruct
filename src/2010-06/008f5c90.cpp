// from server: 100% by auto
// roc 2010-06 008f5c90  unit: Ogre::UTVertexPositionNormalStudsTex::?$SpecializedMeshGen  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008f5c90
//
// 008f5c90  51                   push ecx
// 008f5c91  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008f5c95  8b542410             mov edx, dword ptr [esp + 0x10]
// 008f5c99  c6042400             mov byte ptr [esp], 0
// 008f5c9d  8b0424               mov eax, dword ptr [esp]
// 008f5ca0  50                   push eax
// 008f5ca1  8b442414             mov eax, dword ptr [esp + 0x14]
// 008f5ca5  51                   push ecx
// 008f5ca6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008f5caa  52                   push edx
// 008f5cab  8b542414             mov edx, dword ptr [esp + 0x14]
// 008f5caf  50                   push eax
// 008f5cb0  51                   push ecx
// 008f5cb1  52                   push edx
// 008f5cb2  e8a9f7ffff           call 0x8f5460
// 008f5cb7  83c41c               add esp, 0x1c
// 008f5cba  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
