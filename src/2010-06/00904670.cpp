// from server: 100% by auto
// roc 2010-06 00904670  unit: Ogre::RbxSpatialHashedSceneNode::?3??_findVisibleObjects::NodeVisiter  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00904670
//
// 00904670  51                   push ecx
// 00904671  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00904675  8b542410             mov edx, dword ptr [esp + 0x10]
// 00904679  c6042400             mov byte ptr [esp], 0
// 0090467d  8b0424               mov eax, dword ptr [esp]
// 00904680  50                   push eax
// 00904681  8b442414             mov eax, dword ptr [esp + 0x14]
// 00904685  51                   push ecx
// 00904686  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0090468a  52                   push edx
// 0090468b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0090468f  50                   push eax
// 00904690  51                   push ecx
// 00904691  52                   push edx
// 00904692  e859fdffff           call 0x9043f0
// 00904697  83c41c               add esp, 0x1c
// 0090469a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
