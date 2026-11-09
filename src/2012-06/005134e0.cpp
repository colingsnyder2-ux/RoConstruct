// from server: 100% by auto
// roc 2012-06 005134e0  unit: Ogre::RbxSpatialHashedSceneNode  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005134e0
//
// 005134e0  51                   push ecx
// 005134e1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005134e5  8b542410             mov edx, dword ptr [esp + 0x10]
// 005134e9  c6042400             mov byte ptr [esp], 0
// 005134ed  8b0424               mov eax, dword ptr [esp]
// 005134f0  50                   push eax
// 005134f1  8b442414             mov eax, dword ptr [esp + 0x14]
// 005134f5  51                   push ecx
// 005134f6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005134fa  52                   push edx
// 005134fb  8b542414             mov edx, dword ptr [esp + 0x14]
// 005134ff  50                   push eax
// 00513500  51                   push ecx
// 00513501  52                   push edx
// 00513502  e879ddffff           call 0x511280
// 00513507  83c41c               add esp, 0x1c
// 0051350a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
