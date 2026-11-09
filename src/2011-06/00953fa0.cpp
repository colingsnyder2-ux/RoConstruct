// from server: 100% by auto
// roc 2011-06 00953fa0  unit: Ogre::UTVertexSurfaceTexTangent::?$SpecializedMeshGen  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00953fa0
//
// 00953fa0  51                   push ecx
// 00953fa1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00953fa5  8b542410             mov edx, dword ptr [esp + 0x10]
// 00953fa9  c6042400             mov byte ptr [esp], 0
// 00953fad  8b0424               mov eax, dword ptr [esp]
// 00953fb0  50                   push eax
// 00953fb1  8b442414             mov eax, dword ptr [esp + 0x14]
// 00953fb5  51                   push ecx
// 00953fb6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00953fba  52                   push edx
// 00953fbb  8b542414             mov edx, dword ptr [esp + 0x14]
// 00953fbf  50                   push eax
// 00953fc0  51                   push ecx
// 00953fc1  52                   push edx
// 00953fc2  e859feffff           call 0x953e20
// 00953fc7  83c41c               add esp, 0x1c
// 00953fca  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
