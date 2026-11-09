// from server: 100% by auto
// roc 2011-06 0092cb90  unit: Ogre::GfxClustererPart  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0092cb90
//
// 0092cb90  51                   push ecx
// 0092cb91  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0092cb95  8b542410             mov edx, dword ptr [esp + 0x10]
// 0092cb99  c6042400             mov byte ptr [esp], 0
// 0092cb9d  8b0424               mov eax, dword ptr [esp]
// 0092cba0  50                   push eax
// 0092cba1  8b442414             mov eax, dword ptr [esp + 0x14]
// 0092cba5  51                   push ecx
// 0092cba6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0092cbaa  52                   push edx
// 0092cbab  8b542414             mov edx, dword ptr [esp + 0x14]
// 0092cbaf  50                   push eax
// 0092cbb0  51                   push ecx
// 0092cbb1  52                   push edx
// 0092cbb2  e809eeffff           call 0x92b9c0
// 0092cbb7  83c41c               add esp, 0x1c
// 0092cbba  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
