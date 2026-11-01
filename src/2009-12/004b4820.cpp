// from server: 100% by auto
// roc 2009-12 004b4820  unit: Ogre::RbxMaterialAdapter  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004b4820
//
// 004b4820  51                   push ecx
// 004b4821  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004b4825  8b542410             mov edx, dword ptr [esp + 0x10]
// 004b4829  c6042400             mov byte ptr [esp], 0
// 004b482d  8b0424               mov eax, dword ptr [esp]
// 004b4830  50                   push eax
// 004b4831  8b442414             mov eax, dword ptr [esp + 0x14]
// 004b4835  51                   push ecx
// 004b4836  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004b483a  52                   push edx
// 004b483b  8b542414             mov edx, dword ptr [esp + 0x14]
// 004b483f  50                   push eax
// 004b4840  51                   push ecx
// 004b4841  52                   push edx
// 004b4842  e8f9efffff           call 0x4b3840
// 004b4847  83c41c               add esp, 0x1c
// 004b484a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
