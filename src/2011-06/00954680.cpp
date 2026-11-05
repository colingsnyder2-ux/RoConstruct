// from server: 100% by auto
// roc 2011-06 00954680  unit: Ogre::UTVertex3DTex::?$SpecializedMeshGen  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00954680
//
// 00954680  51                   push ecx
// 00954681  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00954685  8b542410             mov edx, dword ptr [esp + 0x10]
// 00954689  c6042400             mov byte ptr [esp], 0
// 0095468d  8b0424               mov eax, dword ptr [esp]
// 00954690  50                   push eax
// 00954691  8b442414             mov eax, dword ptr [esp + 0x14]
// 00954695  51                   push ecx
// 00954696  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0095469a  52                   push edx
// 0095469b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0095469f  50                   push eax
// 009546a0  51                   push ecx
// 009546a1  52                   push edx
// 009546a2  e879feffff           call 0x954520
// 009546a7  83c41c               add esp, 0x1c
// 009546aa  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
