// from server: 100% by auto
// roc 2011-06 009536f0  unit: Ogre::UTVertexSurfaceTex::?$SpecializedMeshGen  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 009536f0
//
// 009536f0  51                   push ecx
// 009536f1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 009536f5  8b542410             mov edx, dword ptr [esp + 0x10]
// 009536f9  c6042400             mov byte ptr [esp], 0
// 009536fd  8b0424               mov eax, dword ptr [esp]
// 00953700  50                   push eax
// 00953701  8b442414             mov eax, dword ptr [esp + 0x14]
// 00953705  51                   push ecx
// 00953706  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0095370a  52                   push edx
// 0095370b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0095370f  50                   push eax
// 00953710  51                   push ecx
// 00953711  52                   push edx
// 00953712  e879feffff           call 0x953590
// 00953717  83c41c               add esp, 0x1c
// 0095371a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
