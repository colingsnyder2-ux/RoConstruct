// from server: 100% by auto
// roc 2009-12 004a1fd0  unit: Ogre::UTVertexBasic::?$SpecializedMeshGen  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004a1fd0
//
// 004a1fd0  51                   push ecx
// 004a1fd1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004a1fd5  8b542410             mov edx, dword ptr [esp + 0x10]
// 004a1fd9  c6042400             mov byte ptr [esp], 0
// 004a1fdd  8b0424               mov eax, dword ptr [esp]
// 004a1fe0  50                   push eax
// 004a1fe1  8b442414             mov eax, dword ptr [esp + 0x14]
// 004a1fe5  51                   push ecx
// 004a1fe6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004a1fea  52                   push edx
// 004a1feb  8b542414             mov edx, dword ptr [esp + 0x14]
// 004a1fef  50                   push eax
// 004a1ff0  51                   push ecx
// 004a1ff1  52                   push edx
// 004a1ff2  e829e7ffff           call 0x4a0720
// 004a1ff7  83c41c               add esp, 0x1c
// 004a1ffa  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
