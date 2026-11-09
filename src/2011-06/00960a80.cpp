// from server: 100% by auto
// roc 2011-06 00960a80  unit: Ogre::RbxSceneUpdater  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00960a80
//
// 00960a80  51                   push ecx
// 00960a81  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00960a85  8b542410             mov edx, dword ptr [esp + 0x10]
// 00960a89  c6042400             mov byte ptr [esp], 0
// 00960a8d  8b0424               mov eax, dword ptr [esp]
// 00960a90  50                   push eax
// 00960a91  8b442414             mov eax, dword ptr [esp + 0x14]
// 00960a95  51                   push ecx
// 00960a96  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00960a9a  52                   push edx
// 00960a9b  8b542414             mov edx, dword ptr [esp + 0x14]
// 00960a9f  50                   push eax
// 00960aa0  51                   push ecx
// 00960aa1  52                   push edx
// 00960aa2  e829fdffff           call 0x9607d0
// 00960aa7  83c41c               add esp, 0x1c
// 00960aaa  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
