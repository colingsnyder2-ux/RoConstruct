// from server: 100% by auto
// roc 2011-06 0093e740  unit: Ogre::RbxMaterialAdapter  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0093e740
//
// 0093e740  51                   push ecx
// 0093e741  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0093e745  8b542410             mov edx, dword ptr [esp + 0x10]
// 0093e749  c6042400             mov byte ptr [esp], 0
// 0093e74d  8b0424               mov eax, dword ptr [esp]
// 0093e750  50                   push eax
// 0093e751  8b442414             mov eax, dword ptr [esp + 0x14]
// 0093e755  51                   push ecx
// 0093e756  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0093e75a  52                   push edx
// 0093e75b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0093e75f  50                   push eax
// 0093e760  51                   push ecx
// 0093e761  52                   push edx
// 0093e762  e849f2ffff           call 0x93d9b0
// 0093e767  83c41c               add esp, 0x1c
// 0093e76a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
