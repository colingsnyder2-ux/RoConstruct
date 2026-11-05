// from server: 100% by auto
// roc 2009-12 004a3040  unit: Ogre::RbxMeshPartAdapter  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004a3040
//
// 004a3040  51                   push ecx
// 004a3041  8b542410             mov edx, dword ptr [esp + 0x10]
// 004a3045  c6042400             mov byte ptr [esp], 0
// 004a3049  8b0424               mov eax, dword ptr [esp]
// 004a304c  50                   push eax
// 004a304d  8b442414             mov eax, dword ptr [esp + 0x14]
// 004a3051  52                   push edx
// 004a3052  8b542410             mov edx, dword ptr [esp + 0x10]
// 004a3056  83c108               add ecx, 8
// 004a3059  51                   push ecx
// 004a305a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004a305e  50                   push eax
// 004a305f  51                   push ecx
// 004a3060  52                   push edx
// 004a3061  e89acfffff           call 0x4a0000
// 004a3066  83c41c               add esp, 0x1c
// 004a3069  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
