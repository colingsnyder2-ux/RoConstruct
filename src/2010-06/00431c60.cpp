// from server: 100% by auto
// roc 2010-06 00431c60  unit: COutputView  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00431c60
//
// 00431c60  6aff                 push -1
// 00431c62  6858a29900           push 0x99a258
// 00431c67  64a100000000         mov eax, dword ptr fs:[0]
// 00431c6d  50                   push eax
// 00431c6e  64892500000000       mov dword ptr fs:[0], esp
// 00431c75  51                   push ecx
// 00431c76  56                   push esi
// 00431c77  8bf1                 mov esi, ecx
// 00431c79  89742404             mov dword ptr [esp + 4], esi
// 00431c7d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00431c85  e866aa2100           call 0x64c6f0
// 00431c8a  8b06                 mov eax, dword ptr [esi]
// 00431c8c  50                   push eax
// 00431c8d  e8085d3700           call 0x7a799a
// 00431c92  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00431c96  83c404               add esp, 4
// 00431c99  5e                   pop esi
// 00431c9a  64890d00000000       mov dword ptr fs:[0], ecx
// 00431ca1  83c410               add esp, 0x10
// 00431ca4  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
