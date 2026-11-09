// from server: 100% by auto
// roc 2010-06 0096a5a0  unit: Ogre::RbxSceneUpdater  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0096a5a0
//
// 0096a5a0  51                   push ecx
// 0096a5a1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0096a5a5  8b542410             mov edx, dword ptr [esp + 0x10]
// 0096a5a9  c6042400             mov byte ptr [esp], 0
// 0096a5ad  8b0424               mov eax, dword ptr [esp]
// 0096a5b0  50                   push eax
// 0096a5b1  8b442414             mov eax, dword ptr [esp + 0x14]
// 0096a5b5  51                   push ecx
// 0096a5b6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0096a5ba  52                   push edx
// 0096a5bb  8b542414             mov edx, dword ptr [esp + 0x14]
// 0096a5bf  50                   push eax
// 0096a5c0  51                   push ecx
// 0096a5c1  52                   push edx
// 0096a5c2  e879feffff           call 0x96a440
// 0096a5c7  83c41c               add esp, 0x1c
// 0096a5ca  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
