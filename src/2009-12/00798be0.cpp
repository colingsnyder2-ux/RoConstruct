// from server: 100% by auto
// roc 2009-12 00798be0  unit: lua_exception  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00798be0
//
// 00798be0  51                   push ecx
// 00798be1  8b542410             mov edx, dword ptr [esp + 0x10]
// 00798be5  c6042400             mov byte ptr [esp], 0
// 00798be9  8b0424               mov eax, dword ptr [esp]
// 00798bec  50                   push eax
// 00798bed  8b442414             mov eax, dword ptr [esp + 0x14]
// 00798bf1  52                   push edx
// 00798bf2  8b542410             mov edx, dword ptr [esp + 0x10]
// 00798bf6  83c108               add ecx, 8
// 00798bf9  51                   push ecx
// 00798bfa  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00798bfe  50                   push eax
// 00798bff  51                   push ecx
// 00798c00  52                   push edx
// 00798c01  e88af9ffff           call 0x798590
// 00798c06  83c41c               add esp, 0x1c
// 00798c09  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
