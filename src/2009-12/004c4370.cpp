// from server: 100% by auto
// roc 2009-12 004c4370  unit: Ogre::RbxCluster::VRbxPartBinding::?$sp_counted_impl_p  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004c4370
//
// 004c4370  51                   push ecx
// 004c4371  8b542410             mov edx, dword ptr [esp + 0x10]
// 004c4375  c6042400             mov byte ptr [esp], 0
// 004c4379  8b0424               mov eax, dword ptr [esp]
// 004c437c  50                   push eax
// 004c437d  8b442414             mov eax, dword ptr [esp + 0x14]
// 004c4381  52                   push edx
// 004c4382  8b542410             mov edx, dword ptr [esp + 0x10]
// 004c4386  83c108               add ecx, 8
// 004c4389  51                   push ecx
// 004c438a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004c438e  50                   push eax
// 004c438f  51                   push ecx
// 004c4390  52                   push edx
// 004c4391  e8eaba2800           call 0x74fe80
// 004c4396  83c41c               add esp, 0x1c
// 004c4399  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
