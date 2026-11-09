// from server: 100% by auto
// roc 2009-12 004be150  unit: Ogre::RbxSpatialHashedSceneNode::?1??_findVisibleObjects::NodeVisiter  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004be150
//
// 004be150  51                   push ecx
// 004be151  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004be155  8b542410             mov edx, dword ptr [esp + 0x10]
// 004be159  c6042400             mov byte ptr [esp], 0
// 004be15d  8b0424               mov eax, dword ptr [esp]
// 004be160  50                   push eax
// 004be161  8b442414             mov eax, dword ptr [esp + 0x14]
// 004be165  51                   push ecx
// 004be166  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004be16a  52                   push edx
// 004be16b  8b542414             mov edx, dword ptr [esp + 0x14]
// 004be16f  50                   push eax
// 004be170  51                   push ecx
// 004be171  52                   push edx
// 004be172  e8f9faffff           call 0x4bdc70
// 004be177  83c41c               add esp, 0x1c
// 004be17a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
