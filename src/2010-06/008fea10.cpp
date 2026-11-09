// from server: 100% by auto
// roc 2010-06 008fea10  unit: Ogre::RbxSceneUpdater  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008fea10
//
// 008fea10  51                   push ecx
// 008fea11  8b542410             mov edx, dword ptr [esp + 0x10]
// 008fea15  c6042400             mov byte ptr [esp], 0
// 008fea19  8b0424               mov eax, dword ptr [esp]
// 008fea1c  50                   push eax
// 008fea1d  8b442414             mov eax, dword ptr [esp + 0x14]
// 008fea21  52                   push edx
// 008fea22  8b542410             mov edx, dword ptr [esp + 0x10]
// 008fea26  83c108               add ecx, 8
// 008fea29  51                   push ecx
// 008fea2a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008fea2e  50                   push eax
// 008fea2f  51                   push ecx
// 008fea30  52                   push edx
// 008fea31  e8bafcffff           call 0x8fe6f0
// 008fea36  83c41c               add esp, 0x1c
// 008fea39  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
