// from server: 100% by auto
// roc 2012-06 004f9c30  unit: Ogre::UTVertex3DTex::?$SpecializedMeshGen  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004f9c30
//
// 004f9c30  51                   push ecx
// 004f9c31  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004f9c35  8b542410             mov edx, dword ptr [esp + 0x10]
// 004f9c39  c6042400             mov byte ptr [esp], 0
// 004f9c3d  8b0424               mov eax, dword ptr [esp]
// 004f9c40  50                   push eax
// 004f9c41  8b442414             mov eax, dword ptr [esp + 0x14]
// 004f9c45  51                   push ecx
// 004f9c46  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004f9c4a  52                   push edx
// 004f9c4b  8b542414             mov edx, dword ptr [esp + 0x14]
// 004f9c4f  50                   push eax
// 004f9c50  51                   push ecx
// 004f9c51  52                   push edx
// 004f9c52  e879feffff           call 0x4f9ad0
// 004f9c57  83c41c               add esp, 0x1c
// 004f9c5a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
