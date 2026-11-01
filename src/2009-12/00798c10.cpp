// from server: 100% by auto
// roc 2009-12 00798c10  unit: lua_exception  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00798c10
//
// 00798c10  51                   push ecx
// 00798c11  8b542410             mov edx, dword ptr [esp + 0x10]
// 00798c15  c6042400             mov byte ptr [esp], 0
// 00798c19  8b0424               mov eax, dword ptr [esp]
// 00798c1c  50                   push eax
// 00798c1d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00798c21  52                   push edx
// 00798c22  8b542410             mov edx, dword ptr [esp + 0x10]
// 00798c26  83c108               add ecx, 8
// 00798c29  51                   push ecx
// 00798c2a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00798c2e  50                   push eax
// 00798c2f  51                   push ecx
// 00798c30  52                   push edx
// 00798c31  e8aaf9ffff           call 0x7985e0
// 00798c36  83c41c               add esp, 0x1c
// 00798c39  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
