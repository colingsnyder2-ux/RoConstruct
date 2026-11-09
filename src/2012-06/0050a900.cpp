// from server: 100% by auto
// roc 2012-06 0050a900  unit: Ogre::RbxArchive  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0050a900
//
// 0050a900  51                   push ecx
// 0050a901  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0050a905  8b542410             mov edx, dword ptr [esp + 0x10]
// 0050a909  c6042400             mov byte ptr [esp], 0
// 0050a90d  8b0424               mov eax, dword ptr [esp]
// 0050a910  50                   push eax
// 0050a911  8b442414             mov eax, dword ptr [esp + 0x14]
// 0050a915  51                   push ecx
// 0050a916  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0050a91a  52                   push edx
// 0050a91b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0050a91f  50                   push eax
// 0050a920  51                   push ecx
// 0050a921  52                   push edx
// 0050a922  e829faffff           call 0x50a350
// 0050a927  83c41c               add esp, 0x1c
// 0050a92a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
