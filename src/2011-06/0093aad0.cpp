// from server: 100% by auto
// roc 2011-06 0093aad0  unit: Ogre::RbxTextureCompositorSceneManager  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0093aad0
//
// 0093aad0  51                   push ecx
// 0093aad1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0093aad5  8b542410             mov edx, dword ptr [esp + 0x10]
// 0093aad9  c6042400             mov byte ptr [esp], 0
// 0093aadd  8b0424               mov eax, dword ptr [esp]
// 0093aae0  50                   push eax
// 0093aae1  8b442414             mov eax, dword ptr [esp + 0x14]
// 0093aae5  51                   push ecx
// 0093aae6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0093aaea  52                   push edx
// 0093aaeb  8b542414             mov edx, dword ptr [esp + 0x14]
// 0093aaef  50                   push eax
// 0093aaf0  51                   push ecx
// 0093aaf1  52                   push edx
// 0093aaf2  e8b9eeffff           call 0x9399b0
// 0093aaf7  83c41c               add esp, 0x1c
// 0093aafa  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
