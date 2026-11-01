// from server: 100% by auto
// roc 2009-12 004ac760  unit: Ogre::RbxSceneUpdater  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004ac760
//
// 004ac760  51                   push ecx
// 004ac761  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004ac765  8b542410             mov edx, dword ptr [esp + 0x10]
// 004ac769  c6042400             mov byte ptr [esp], 0
// 004ac76d  8b0424               mov eax, dword ptr [esp]
// 004ac770  50                   push eax
// 004ac771  8b442414             mov eax, dword ptr [esp + 0x14]
// 004ac775  51                   push ecx
// 004ac776  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004ac77a  52                   push edx
// 004ac77b  8b542414             mov edx, dword ptr [esp + 0x14]
// 004ac77f  50                   push eax
// 004ac780  51                   push ecx
// 004ac781  52                   push edx
// 004ac782  e869feffff           call 0x4ac5f0
// 004ac787  83c41c               add esp, 0x1c
// 004ac78a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
