// from server: 100% by auto
// roc 2010-06 004e3970  unit: RBX::Network::IdSerializer  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004e3970
//
// 004e3970  51                   push ecx
// 004e3971  8b542410             mov edx, dword ptr [esp + 0x10]
// 004e3975  c6042400             mov byte ptr [esp], 0
// 004e3979  8b0424               mov eax, dword ptr [esp]
// 004e397c  50                   push eax
// 004e397d  8b442414             mov eax, dword ptr [esp + 0x14]
// 004e3981  52                   push edx
// 004e3982  8b542410             mov edx, dword ptr [esp + 0x10]
// 004e3986  83c108               add ecx, 8
// 004e3989  51                   push ecx
// 004e398a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004e398e  50                   push eax
// 004e398f  51                   push ecx
// 004e3990  52                   push edx
// 004e3991  e87af2ffff           call 0x4e2c10
// 004e3996  83c41c               add esp, 0x1c
// 004e3999  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
