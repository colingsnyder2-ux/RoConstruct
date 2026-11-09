// from server: 100% by auto
// roc 2010-06 008dd260  unit: Ogre::RbxMaterialAdapter  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008dd260
//
// 008dd260  51                   push ecx
// 008dd261  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008dd265  8b542410             mov edx, dword ptr [esp + 0x10]
// 008dd269  c6042400             mov byte ptr [esp], 0
// 008dd26d  8b0424               mov eax, dword ptr [esp]
// 008dd270  50                   push eax
// 008dd271  8b442414             mov eax, dword ptr [esp + 0x14]
// 008dd275  51                   push ecx
// 008dd276  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008dd27a  52                   push edx
// 008dd27b  8b542414             mov edx, dword ptr [esp + 0x14]
// 008dd27f  50                   push eax
// 008dd280  51                   push ecx
// 008dd281  52                   push edx
// 008dd282  e8a9efffff           call 0x8dc230
// 008dd287  83c41c               add esp, 0x1c
// 008dd28a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
