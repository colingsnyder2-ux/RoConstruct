// from server: 100% by auto
// roc 2008-06 006924f0  unit: Ogre::RbxSceneManager  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006924f0
//
// 006924f0  51                   push ecx
// 006924f1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006924f5  8b542410             mov edx, dword ptr [esp + 0x10]
// 006924f9  c6042400             mov byte ptr [esp], 0
// 006924fd  8b0424               mov eax, dword ptr [esp]
// 00692500  50                   push eax
// 00692501  8b442414             mov eax, dword ptr [esp + 0x14]
// 00692505  51                   push ecx
// 00692506  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0069250a  52                   push edx
// 0069250b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0069250f  50                   push eax
// 00692510  51                   push ecx
// 00692511  52                   push edx
// 00692512  e8e9bcffff           call 0x68e200
// 00692517  83c41c               add esp, 0x1c
// 0069251a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
