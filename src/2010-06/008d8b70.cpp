// from server: 100% by auto
// roc 2010-06 008d8b70  unit: Ogre::RbxTextureCompositorSceneManager  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d8b70
//
// 008d8b70  51                   push ecx
// 008d8b71  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008d8b75  8b542410             mov edx, dword ptr [esp + 0x10]
// 008d8b79  c6042400             mov byte ptr [esp], 0
// 008d8b7d  8b0424               mov eax, dword ptr [esp]
// 008d8b80  50                   push eax
// 008d8b81  8b442414             mov eax, dword ptr [esp + 0x14]
// 008d8b85  51                   push ecx
// 008d8b86  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008d8b8a  52                   push edx
// 008d8b8b  8b542414             mov edx, dword ptr [esp + 0x14]
// 008d8b8f  50                   push eax
// 008d8b90  51                   push ecx
// 008d8b91  52                   push edx
// 008d8b92  e869f7ffff           call 0x8d8300
// 008d8b97  83c41c               add esp, 0x1c
// 008d8b9a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
