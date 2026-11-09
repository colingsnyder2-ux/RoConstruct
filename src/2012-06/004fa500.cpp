// from server: 100% by auto
// roc 2012-06 004fa500  unit: Ogre::UTVertexTangent3DTex::?$SpecializedMeshGen  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004fa500
//
// 004fa500  51                   push ecx
// 004fa501  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004fa505  8b542410             mov edx, dword ptr [esp + 0x10]
// 004fa509  c6042400             mov byte ptr [esp], 0
// 004fa50d  8b0424               mov eax, dword ptr [esp]
// 004fa510  50                   push eax
// 004fa511  8b442414             mov eax, dword ptr [esp + 0x14]
// 004fa515  51                   push ecx
// 004fa516  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004fa51a  52                   push edx
// 004fa51b  8b542414             mov edx, dword ptr [esp + 0x14]
// 004fa51f  50                   push eax
// 004fa520  51                   push ecx
// 004fa521  52                   push edx
// 004fa522  e859feffff           call 0x4fa380
// 004fa527  83c41c               add esp, 0x1c
// 004fa52a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
