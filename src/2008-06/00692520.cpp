// from server: 100% by auto
// roc 2008-06 00692520  unit: Ogre::RbxSceneManager  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00692520
//
// 00692520  51                   push ecx
// 00692521  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00692525  8b542410             mov edx, dword ptr [esp + 0x10]
// 00692529  c6042400             mov byte ptr [esp], 0
// 0069252d  8b0424               mov eax, dword ptr [esp]
// 00692530  50                   push eax
// 00692531  8b442414             mov eax, dword ptr [esp + 0x14]
// 00692535  51                   push ecx
// 00692536  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0069253a  52                   push edx
// 0069253b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0069253f  50                   push eax
// 00692540  51                   push ecx
// 00692541  52                   push edx
// 00692542  e809bdffff           call 0x68e250
// 00692547  83c41c               add esp, 0x1c
// 0069254a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
