// from server: 100% by auto
// roc 2009-06 00486820  unit: Ogre::RbxMeshPartAdapter  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00486820
//
// 00486820  51                   push ecx
// 00486821  8b542410             mov edx, dword ptr [esp + 0x10]
// 00486825  c6042400             mov byte ptr [esp], 0
// 00486829  8b0424               mov eax, dword ptr [esp]
// 0048682c  50                   push eax
// 0048682d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00486831  52                   push edx
// 00486832  8b542410             mov edx, dword ptr [esp + 0x10]
// 00486836  83c108               add ecx, 8
// 00486839  51                   push ecx
// 0048683a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0048683e  50                   push eax
// 0048683f  51                   push ecx
// 00486840  52                   push edx
// 00486841  e85af6ffff           call 0x485ea0
// 00486846  83c41c               add esp, 0x1c
// 00486849  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
