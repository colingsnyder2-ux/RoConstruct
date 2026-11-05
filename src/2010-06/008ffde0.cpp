// from server: 100% by auto
// roc 2010-06 008ffde0  unit: Ogre::RbxSceneUpdater  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008ffde0
//
// 008ffde0  51                   push ecx
// 008ffde1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008ffde5  8b542410             mov edx, dword ptr [esp + 0x10]
// 008ffde9  c6042400             mov byte ptr [esp], 0
// 008ffded  8b0424               mov eax, dword ptr [esp]
// 008ffdf0  50                   push eax
// 008ffdf1  8b442414             mov eax, dword ptr [esp + 0x14]
// 008ffdf5  51                   push ecx
// 008ffdf6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008ffdfa  52                   push edx
// 008ffdfb  8b542414             mov edx, dword ptr [esp + 0x14]
// 008ffdff  50                   push eax
// 008ffe00  51                   push ecx
// 008ffe01  52                   push edx
// 008ffe02  e869feffff           call 0x8ffc70
// 008ffe07  83c41c               add esp, 0x1c
// 008ffe0a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
