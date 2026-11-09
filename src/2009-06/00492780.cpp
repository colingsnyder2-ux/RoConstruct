// from server: 100% by auto
// roc 2009-06 00492780  unit: Ogre::RbxMaterialAdapter  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00492780
//
// 00492780  51                   push ecx
// 00492781  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00492785  8b542410             mov edx, dword ptr [esp + 0x10]
// 00492789  c6042400             mov byte ptr [esp], 0
// 0049278d  8b0424               mov eax, dword ptr [esp]
// 00492790  50                   push eax
// 00492791  8b442414             mov eax, dword ptr [esp + 0x14]
// 00492795  51                   push ecx
// 00492796  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0049279a  52                   push edx
// 0049279b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0049279f  50                   push eax
// 004927a0  51                   push ecx
// 004927a1  52                   push edx
// 004927a2  e899e6ffff           call 0x490e40
// 004927a7  83c41c               add esp, 0x1c
// 004927aa  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
