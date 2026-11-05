// from server: 100% by auto
// roc 2010-06 008ce560  unit: Ogre::RbxMeshLoader  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008ce560
//
// 008ce560  51                   push ecx
// 008ce561  8b542410             mov edx, dword ptr [esp + 0x10]
// 008ce565  c6042400             mov byte ptr [esp], 0
// 008ce569  8b0424               mov eax, dword ptr [esp]
// 008ce56c  50                   push eax
// 008ce56d  8b442414             mov eax, dword ptr [esp + 0x14]
// 008ce571  52                   push edx
// 008ce572  8b542410             mov edx, dword ptr [esp + 0x10]
// 008ce576  83c108               add ecx, 8
// 008ce579  51                   push ecx
// 008ce57a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008ce57e  50                   push eax
// 008ce57f  51                   push ecx
// 008ce580  52                   push edx
// 008ce581  e8baebffff           call 0x8cd140
// 008ce586  83c41c               add esp, 0x1c
// 008ce589  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
