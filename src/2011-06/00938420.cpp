// from server: 100% by auto
// roc 2011-06 00938420  unit: Ogre::VRbxTextureCompositorSceneManager::?$sp_counted_impl_p  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00938420
//
// 00938420  51                   push ecx
// 00938421  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00938425  8b542410             mov edx, dword ptr [esp + 0x10]
// 00938429  c6042400             mov byte ptr [esp], 0
// 0093842d  8b0424               mov eax, dword ptr [esp]
// 00938430  50                   push eax
// 00938431  8b442414             mov eax, dword ptr [esp + 0x14]
// 00938435  51                   push ecx
// 00938436  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0093843a  52                   push edx
// 0093843b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0093843f  50                   push eax
// 00938440  51                   push ecx
// 00938441  52                   push edx
// 00938442  e8a9f7ffff           call 0x937bf0
// 00938447  83c41c               add esp, 0x1c
// 0093844a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
