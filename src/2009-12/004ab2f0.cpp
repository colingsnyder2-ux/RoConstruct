// from server: 100% by auto
// roc 2009-12 004ab2f0  unit: Ogre::RbxSceneUpdater  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004ab2f0
//
// 004ab2f0  51                   push ecx
// 004ab2f1  8b542410             mov edx, dword ptr [esp + 0x10]
// 004ab2f5  c6042400             mov byte ptr [esp], 0
// 004ab2f9  8b0424               mov eax, dword ptr [esp]
// 004ab2fc  50                   push eax
// 004ab2fd  8b442414             mov eax, dword ptr [esp + 0x14]
// 004ab301  52                   push edx
// 004ab302  8b542410             mov edx, dword ptr [esp + 0x10]
// 004ab306  83c108               add ecx, 8
// 004ab309  51                   push ecx
// 004ab30a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004ab30e  50                   push eax
// 004ab30f  51                   push ecx
// 004ab310  52                   push edx
// 004ab311  e8bafaffff           call 0x4aadd0
// 004ab316  83c41c               add esp, 0x1c
// 004ab319  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
