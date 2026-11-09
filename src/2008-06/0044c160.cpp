// from server: 100% by auto
// roc 2008-06 0044c160  unit: CRobloxModule  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044c160
//
// 0044c160  6aff                 push -1
// 0044c162  68e8727d00           push 0x7d72e8
// 0044c167  64a100000000         mov eax, dword ptr fs:[0]
// 0044c16d  50                   push eax
// 0044c16e  64892500000000       mov dword ptr fs:[0], esp
// 0044c175  51                   push ecx
// 0044c176  56                   push esi
// 0044c177  8bf1                 mov esi, ecx
// 0044c179  89742404             mov dword ptr [esp + 4], esi
// 0044c17d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0044c185  e846f6ffff           call 0x44b7d0
// 0044c18a  8b06                 mov eax, dword ptr [esi]
// 0044c18c  50                   push eax
// 0044c18d  e8e8442500           call 0x6a067a
// 0044c192  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0044c196  83c404               add esp, 4
// 0044c199  5e                   pop esi
// 0044c19a  64890d00000000       mov dword ptr fs:[0], ecx
// 0044c1a1  83c410               add esp, 0x10
// 0044c1a4  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
