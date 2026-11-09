// from server: 100% by auto
// roc 2009-12 004b82f0  unit: Ogre::RbxArchiveFactory  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004b82f0
//
// 004b82f0  51                   push ecx
// 004b82f1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004b82f5  8b542410             mov edx, dword ptr [esp + 0x10]
// 004b82f9  c6042400             mov byte ptr [esp], 0
// 004b82fd  8b0424               mov eax, dword ptr [esp]
// 004b8300  50                   push eax
// 004b8301  8b442414             mov eax, dword ptr [esp + 0x14]
// 004b8305  51                   push ecx
// 004b8306  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004b830a  52                   push edx
// 004b830b  8b542414             mov edx, dword ptr [esp + 0x14]
// 004b830f  50                   push eax
// 004b8310  51                   push ecx
// 004b8311  52                   push edx
// 004b8312  e839f9ffff           call 0x4b7c50
// 004b8317  83c41c               add esp, 0x1c
// 004b831a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
