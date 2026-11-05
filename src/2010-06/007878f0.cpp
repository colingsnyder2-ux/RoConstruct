// from server: 100% by auto
// roc 2010-06 007878f0  unit: RBX::HUMAN::GettingUp  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007878f0
//
// 007878f0  51                   push ecx
// 007878f1  8b542410             mov edx, dword ptr [esp + 0x10]
// 007878f5  c6042400             mov byte ptr [esp], 0
// 007878f9  8b0424               mov eax, dword ptr [esp]
// 007878fc  50                   push eax
// 007878fd  8b442414             mov eax, dword ptr [esp + 0x14]
// 00787901  52                   push edx
// 00787902  8b542410             mov edx, dword ptr [esp + 0x10]
// 00787906  83c108               add ecx, 8
// 00787909  51                   push ecx
// 0078790a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0078790e  50                   push eax
// 0078790f  51                   push ecx
// 00787910  52                   push edx
// 00787911  e8faf7ffff           call 0x787110
// 00787916  83c41c               add esp, 0x1c
// 00787919  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
