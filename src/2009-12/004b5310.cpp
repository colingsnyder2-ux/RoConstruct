// from server: 100% by auto
// roc 2009-12 004b5310  unit: Ogre::RbxMaterialAdapter  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004b5310
//
// 004b5310  51                   push ecx
// 004b5311  8b542410             mov edx, dword ptr [esp + 0x10]
// 004b5315  c6042400             mov byte ptr [esp], 0
// 004b5319  8b0424               mov eax, dword ptr [esp]
// 004b531c  50                   push eax
// 004b531d  8b442414             mov eax, dword ptr [esp + 0x14]
// 004b5321  52                   push edx
// 004b5322  8b542410             mov edx, dword ptr [esp + 0x10]
// 004b5326  83c108               add ecx, 8
// 004b5329  51                   push ecx
// 004b532a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004b532e  50                   push eax
// 004b532f  51                   push ecx
// 004b5330  52                   push edx
// 004b5331  e80a9affff           call 0x4aed40
// 004b5336  83c41c               add esp, 0x1c
// 004b5339  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
