// from server: 100% by auto
// roc 2010-06 00704900  unit: RBX::VInstance::?$NonFactoryProduct  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00704900
//
// 00704900  51                   push ecx
// 00704901  8b542410             mov edx, dword ptr [esp + 0x10]
// 00704905  c6042400             mov byte ptr [esp], 0
// 00704909  8b0424               mov eax, dword ptr [esp]
// 0070490c  50                   push eax
// 0070490d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00704911  52                   push edx
// 00704912  8b542410             mov edx, dword ptr [esp + 0x10]
// 00704916  83c108               add ecx, 8
// 00704919  51                   push ecx
// 0070491a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0070491e  50                   push eax
// 0070491f  51                   push ecx
// 00704920  52                   push edx
// 00704921  e88afaffff           call 0x7043b0
// 00704926  83c41c               add esp, 0x1c
// 00704929  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
