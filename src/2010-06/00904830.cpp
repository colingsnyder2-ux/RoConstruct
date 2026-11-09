// from server: 100% by auto
// roc 2010-06 00904830  unit: Ogre::RbxSpatialHashedSceneNode::?3??_findVisibleObjects::NodeVisiter  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00904830
//
// 00904830  51                   push ecx
// 00904831  8b542410             mov edx, dword ptr [esp + 0x10]
// 00904835  c6042400             mov byte ptr [esp], 0
// 00904839  8b0424               mov eax, dword ptr [esp]
// 0090483c  50                   push eax
// 0090483d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00904841  52                   push edx
// 00904842  8b542410             mov edx, dword ptr [esp + 0x10]
// 00904846  83c108               add ecx, 8
// 00904849  51                   push ecx
// 0090484a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0090484e  50                   push eax
// 0090484f  51                   push ecx
// 00904850  52                   push edx
// 00904851  e8aafcffff           call 0x904500
// 00904856  83c41c               add esp, 0x1c
// 00904859  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
