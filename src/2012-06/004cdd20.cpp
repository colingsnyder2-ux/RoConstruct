// from server: 100% by auto
// roc 2012-06 004cdd20  unit: Ogre::GfxClustererPart  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004cdd20
//
// 004cdd20  51                   push ecx
// 004cdd21  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004cdd25  8b542410             mov edx, dword ptr [esp + 0x10]
// 004cdd29  c6042400             mov byte ptr [esp], 0
// 004cdd2d  8b0424               mov eax, dword ptr [esp]
// 004cdd30  50                   push eax
// 004cdd31  8b442414             mov eax, dword ptr [esp + 0x14]
// 004cdd35  51                   push ecx
// 004cdd36  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004cdd3a  52                   push edx
// 004cdd3b  8b542414             mov edx, dword ptr [esp + 0x14]
// 004cdd3f  50                   push eax
// 004cdd40  51                   push ecx
// 004cdd41  52                   push edx
// 004cdd42  e809ecffff           call 0x4cc950
// 004cdd47  83c41c               add esp, 0x1c
// 004cdd4a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
