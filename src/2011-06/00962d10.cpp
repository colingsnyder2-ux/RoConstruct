// from server: 100% by auto
// roc 2011-06 00962d10  unit: Ogre::RbxArchive  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00962d10
//
// 00962d10  51                   push ecx
// 00962d11  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00962d15  8b542410             mov edx, dword ptr [esp + 0x10]
// 00962d19  c6042400             mov byte ptr [esp], 0
// 00962d1d  8b0424               mov eax, dword ptr [esp]
// 00962d20  50                   push eax
// 00962d21  8b442414             mov eax, dword ptr [esp + 0x14]
// 00962d25  51                   push ecx
// 00962d26  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00962d2a  52                   push edx
// 00962d2b  8b542414             mov edx, dword ptr [esp + 0x14]
// 00962d2f  50                   push eax
// 00962d30  51                   push ecx
// 00962d31  52                   push edx
// 00962d32  e869f9ffff           call 0x9626a0
// 00962d37  83c41c               add esp, 0x1c
// 00962d3a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
