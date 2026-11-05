// from server: 100% by auto
// roc 2010-06 00904800  unit: Ogre::RbxSpatialHashedSceneNode::?3??_findVisibleObjects::NodeVisiter  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00904800
//
// 00904800  51                   push ecx
// 00904801  8b542410             mov edx, dword ptr [esp + 0x10]
// 00904805  c6042400             mov byte ptr [esp], 0
// 00904809  8b0424               mov eax, dword ptr [esp]
// 0090480c  50                   push eax
// 0090480d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00904811  52                   push edx
// 00904812  8b542410             mov edx, dword ptr [esp + 0x10]
// 00904816  83c108               add ecx, 8
// 00904819  51                   push ecx
// 0090481a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0090481e  50                   push eax
// 0090481f  51                   push ecx
// 00904820  52                   push edx
// 00904821  e87ac60500           call 0x960ea0
// 00904826  83c41c               add esp, 0x1c
// 00904829  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
