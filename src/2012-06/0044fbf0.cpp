// from server: 100% by auto
// roc 2012-06 0044fbf0  unit: boost::gregorian::Ubad_day_of_year::U?$error_info_injector::?$clone_impl  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0044fbf0
//
// 0044fbf0  6aff                 push -1
// 0044fbf2  681890ad00           push 0xad9018
// 0044fbf7  64a100000000         mov eax, dword ptr fs:[0]
// 0044fbfd  50                   push eax
// 0044fbfe  64892500000000       mov dword ptr fs:[0], esp
// 0044fc05  51                   push ecx
// 0044fc06  56                   push esi
// 0044fc07  8bf1                 mov esi, ecx
// 0044fc09  89742404             mov dword ptr [esp + 4], esi
// 0044fc0d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0044fc15  e876ebffff           call 0x44e790
// 0044fc1a  8b06                 mov eax, dword ptr [esi]
// 0044fc1c  50                   push eax
// 0044fc1d  e8f2245300           call 0x982114
// 0044fc22  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0044fc26  83c404               add esp, 4
// 0044fc29  5e                   pop esi
// 0044fc2a  64890d00000000       mov dword ptr fs:[0], ecx
// 0044fc31  83c410               add esp, 0x10
// 0044fc34  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
