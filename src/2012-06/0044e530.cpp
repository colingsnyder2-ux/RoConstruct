// from server: 100% by auto
// roc 2012-06 0044e530  unit: boost::gregorian::Ubad_day_of_year::?$error_info_injector  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0044e530
//
// 0044e530  6aff                 push -1
// 0044e532  681890ad00           push 0xad9018
// 0044e537  64a100000000         mov eax, dword ptr fs:[0]
// 0044e53d  50                   push eax
// 0044e53e  64892500000000       mov dword ptr fs:[0], esp
// 0044e545  51                   push ecx
// 0044e546  56                   push esi
// 0044e547  8bf1                 mov esi, ecx
// 0044e549  89742404             mov dword ptr [esp + 4], esi
// 0044e54d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0044e555  e846f9ffff           call 0x44dea0
// 0044e55a  8b06                 mov eax, dword ptr [esi]
// 0044e55c  50                   push eax
// 0044e55d  e8b23b5300           call 0x982114
// 0044e562  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0044e566  83c404               add esp, 4
// 0044e569  5e                   pop esi
// 0044e56a  64890d00000000       mov dword ptr fs:[0], ecx
// 0044e571  83c410               add esp, 0x10
// 0044e574  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
