// from server: 100% by auto
// roc 2009-12 004a3070  unit: Ogre::RbxMeshPartAdapter  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004a3070
//
// 004a3070  51                   push ecx
// 004a3071  8b542410             mov edx, dword ptr [esp + 0x10]
// 004a3075  c6042400             mov byte ptr [esp], 0
// 004a3079  8b0424               mov eax, dword ptr [esp]
// 004a307c  50                   push eax
// 004a307d  8b442414             mov eax, dword ptr [esp + 0x14]
// 004a3081  52                   push edx
// 004a3082  8b542410             mov edx, dword ptr [esp + 0x10]
// 004a3086  83c108               add ecx, 8
// 004a3089  51                   push ecx
// 004a308a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004a308e  50                   push eax
// 004a308f  51                   push ecx
// 004a3090  52                   push edx
// 004a3091  e8fad6ffff           call 0x4a0790
// 004a3096  83c41c               add esp, 0x1c
// 004a3099  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
