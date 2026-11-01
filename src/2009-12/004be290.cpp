// from server: 100% by auto
// roc 2009-12 004be290  unit: Ogre::RbxSpatialHashedSceneNode::?1??_findVisibleObjects::NodeVisiter  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004be290
//
// 004be290  51                   push ecx
// 004be291  8b542410             mov edx, dword ptr [esp + 0x10]
// 004be295  c6042400             mov byte ptr [esp], 0
// 004be299  8b0424               mov eax, dword ptr [esp]
// 004be29c  50                   push eax
// 004be29d  8b442414             mov eax, dword ptr [esp + 0x14]
// 004be2a1  52                   push edx
// 004be2a2  8b542410             mov edx, dword ptr [esp + 0x10]
// 004be2a6  83c108               add ecx, 8
// 004be2a9  51                   push ecx
// 004be2aa  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004be2ae  50                   push eax
// 004be2af  51                   push ecx
// 004be2b0  52                   push edx
// 004be2b1  e8cafaffff           call 0x4bdd80
// 004be2b6  83c41c               add esp, 0x1c
// 004be2b9  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
