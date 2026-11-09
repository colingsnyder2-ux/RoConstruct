// from server: 100% by auto
// roc 2010-06 008d6140  unit: Ogre::VRbxTextureCompositorSceneManager::?$sp_counted_impl_p  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d6140
//
// 008d6140  51                   push ecx
// 008d6141  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008d6145  8b542410             mov edx, dword ptr [esp + 0x10]
// 008d6149  c6042400             mov byte ptr [esp], 0
// 008d614d  8b0424               mov eax, dword ptr [esp]
// 008d6150  50                   push eax
// 008d6151  8b442414             mov eax, dword ptr [esp + 0x14]
// 008d6155  51                   push ecx
// 008d6156  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008d615a  52                   push edx
// 008d615b  8b542414             mov edx, dword ptr [esp + 0x14]
// 008d615f  50                   push eax
// 008d6160  51                   push ecx
// 008d6161  52                   push edx
// 008d6162  e879f5ffff           call 0x8d56e0
// 008d6167  83c41c               add esp, 0x1c
// 008d616a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
