// from server: 100% by auto
// roc 2007-08 004a2040  unit: RBX::Network::VServer::?$BoundFuncDesc  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a2040
//
// 004a2040  51                   push ecx
// 004a2041  8b542410             mov edx, dword ptr [esp + 0x10]
// 004a2045  c6042400             mov byte ptr [esp], 0
// 004a2049  8b0424               mov eax, dword ptr [esp]
// 004a204c  50                   push eax
// 004a204d  8b442414             mov eax, dword ptr [esp + 0x14]
// 004a2051  52                   push edx
// 004a2052  8b542410             mov edx, dword ptr [esp + 0x10]
// 004a2056  51                   push ecx
// 004a2057  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004a205b  50                   push eax
// 004a205c  51                   push ecx
// 004a205d  52                   push edx
// 004a205e  e88df7ffff           call 0x4a17f0
// 004a2063  83c41c               add esp, 0x1c
// 004a2066  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
