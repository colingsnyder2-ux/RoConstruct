// from server: 100% by auto
// roc 2008-06 0067d580  unit: Ogre::RbxEntity  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0067d580
//
// 0067d580  51                   push ecx
// 0067d581  8b542410             mov edx, dword ptr [esp + 0x10]
// 0067d585  c6042400             mov byte ptr [esp], 0
// 0067d589  8b0424               mov eax, dword ptr [esp]
// 0067d58c  50                   push eax
// 0067d58d  8b442414             mov eax, dword ptr [esp + 0x14]
// 0067d591  52                   push edx
// 0067d592  8b542410             mov edx, dword ptr [esp + 0x10]
// 0067d596  83c108               add ecx, 8
// 0067d599  51                   push ecx
// 0067d59a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0067d59e  50                   push eax
// 0067d59f  51                   push ecx
// 0067d5a0  52                   push edx
// 0067d5a1  e8eaf2ffff           call 0x67c890
// 0067d5a6  83c41c               add esp, 0x1c
// 0067d5a9  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
