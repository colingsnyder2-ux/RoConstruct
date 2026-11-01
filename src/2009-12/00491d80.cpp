// from server: 100% by auto
// roc 2009-12 00491d80  unit: Ogre::RbxEntity  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00491d80
//
// 00491d80  51                   push ecx
// 00491d81  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00491d85  8b542410             mov edx, dword ptr [esp + 0x10]
// 00491d89  c6042400             mov byte ptr [esp], 0
// 00491d8d  8b0424               mov eax, dword ptr [esp]
// 00491d90  50                   push eax
// 00491d91  8b442414             mov eax, dword ptr [esp + 0x14]
// 00491d95  51                   push ecx
// 00491d96  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00491d9a  52                   push edx
// 00491d9b  8b542414             mov edx, dword ptr [esp + 0x14]
// 00491d9f  50                   push eax
// 00491da0  51                   push ecx
// 00491da1  52                   push edx
// 00491da2  e889bb1100           call 0x5ad930
// 00491da7  83c41c               add esp, 0x1c
// 00491daa  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
