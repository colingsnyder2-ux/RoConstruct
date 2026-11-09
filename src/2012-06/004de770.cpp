// from server: 100% by auto
// roc 2012-06 004de770  unit: Ogre::VRbxTextureCompositorSceneManager::?$sp_counted_impl_p  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004de770
//
// 004de770  51                   push ecx
// 004de771  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004de775  8b542410             mov edx, dword ptr [esp + 0x10]
// 004de779  c6042400             mov byte ptr [esp], 0
// 004de77d  8b0424               mov eax, dword ptr [esp]
// 004de780  50                   push eax
// 004de781  8b442414             mov eax, dword ptr [esp + 0x14]
// 004de785  51                   push ecx
// 004de786  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004de78a  52                   push edx
// 004de78b  8b542414             mov edx, dword ptr [esp + 0x14]
// 004de78f  50                   push eax
// 004de790  51                   push ecx
// 004de791  52                   push edx
// 004de792  e809f7ffff           call 0x4ddea0
// 004de797  83c41c               add esp, 0x1c
// 004de79a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
