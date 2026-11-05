// from server: 100% by auto
// roc 2009-06 00486740  unit: Ogre::RbxMeshPartAdapter  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00486740
//
// 00486740  51                   push ecx
// 00486741  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00486745  8b542410             mov edx, dword ptr [esp + 0x10]
// 00486749  c6042400             mov byte ptr [esp], 0
// 0048674d  8b0424               mov eax, dword ptr [esp]
// 00486750  50                   push eax
// 00486751  8b442414             mov eax, dword ptr [esp + 0x14]
// 00486755  51                   push ecx
// 00486756  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0048675a  52                   push edx
// 0048675b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0048675f  50                   push eax
// 00486760  51                   push ecx
// 00486761  52                   push edx
// 00486762  e8d9f6ffff           call 0x485e40
// 00486767  83c41c               add esp, 0x1c
// 0048676a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
