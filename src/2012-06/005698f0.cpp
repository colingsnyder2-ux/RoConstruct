// from server: 100% by auto
// roc 2012-06 005698f0  unit: std::N::NV?$allocator::V?$circular_buffer::?$sp_counted_impl_p  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005698f0
//
// 005698f0  6aff                 push -1
// 005698f2  681890ad00           push 0xad9018
// 005698f7  64a100000000         mov eax, dword ptr fs:[0]
// 005698fd  50                   push eax
// 005698fe  64892500000000       mov dword ptr fs:[0], esp
// 00569905  51                   push ecx
// 00569906  56                   push esi
// 00569907  8bf1                 mov esi, ecx
// 00569909  89742404             mov dword ptr [esp + 4], esi
// 0056990d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00569915  e8166cf2ff           call 0x490530
// 0056991a  8b06                 mov eax, dword ptr [esi]
// 0056991c  50                   push eax
// 0056991d  e8f2874100           call 0x982114
// 00569922  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00569926  83c404               add esp, 4
// 00569929  5e                   pop esi
// 0056992a  64890d00000000       mov dword ptr fs:[0], ecx
// 00569931  83c410               add esp, 0x10
// 00569934  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
