// from server: 100% by auto
// roc 2009-12 004a1f40  unit: Ogre::UTVertexBasic::?$SpecializedMeshGen  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004a1f40
//
// 004a1f40  51                   push ecx
// 004a1f41  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004a1f45  8b542410             mov edx, dword ptr [esp + 0x10]
// 004a1f49  c6042400             mov byte ptr [esp], 0
// 004a1f4d  8b0424               mov eax, dword ptr [esp]
// 004a1f50  50                   push eax
// 004a1f51  8b442414             mov eax, dword ptr [esp + 0x14]
// 004a1f55  51                   push ecx
// 004a1f56  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004a1f5a  52                   push edx
// 004a1f5b  8b542414             mov edx, dword ptr [esp + 0x14]
// 004a1f5f  50                   push eax
// 004a1f60  51                   push ecx
// 004a1f61  52                   push edx
// 004a1f62  e8b9d1ffff           call 0x49f120
// 004a1f67  83c41c               add esp, 0x1c
// 004a1f6a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
