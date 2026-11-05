// from server: 100% by auto
// roc 2010-06 004317f0  unit: COutputView  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004317f0
//
// 004317f0  6aff                 push -1
// 004317f2  6858a29900           push 0x99a258
// 004317f7  64a100000000         mov eax, dword ptr fs:[0]
// 004317fd  50                   push eax
// 004317fe  64892500000000       mov dword ptr fs:[0], esp
// 00431805  51                   push ecx
// 00431806  56                   push esi
// 00431807  8bf1                 mov esi, ecx
// 00431809  89742404             mov dword ptr [esp + 4], esi
// 0043180d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00431815  e8d6f9ffff           call 0x4311f0
// 0043181a  8b06                 mov eax, dword ptr [esi]
// 0043181c  50                   push eax
// 0043181d  e878613700           call 0x7a799a
// 00431822  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00431826  83c404               add esp, 4
// 00431829  5e                   pop esi
// 0043182a  64890d00000000       mov dword ptr fs:[0], ecx
// 00431831  83c410               add esp, 0x10
// 00431834  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
