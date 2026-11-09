// from server: 100% by auto
// roc 2008-06 00436960  unit: COutputView  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00436960
//
// 00436960  6aff                 push -1
// 00436962  68e8727d00           push 0x7d72e8
// 00436967  64a100000000         mov eax, dword ptr fs:[0]
// 0043696d  50                   push eax
// 0043696e  64892500000000       mov dword ptr fs:[0], esp
// 00436975  51                   push ecx
// 00436976  56                   push esi
// 00436977  8bf1                 mov esi, ecx
// 00436979  89742404             mov dword ptr [esp + 4], esi
// 0043697d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00436985  e846fdffff           call 0x4366d0
// 0043698a  8b06                 mov eax, dword ptr [esi]
// 0043698c  50                   push eax
// 0043698d  e8e89c2600           call 0x6a067a
// 00436992  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00436996  83c404               add esp, 4
// 00436999  5e                   pop esi
// 0043699a  64890d00000000       mov dword ptr fs:[0], ecx
// 004369a1  83c410               add esp, 0x10
// 004369a4  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
