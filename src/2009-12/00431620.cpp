// from server: 100% by auto
// roc 2009-12 00431620  unit: COutputView  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00431620
//
// 00431620  6aff                 push -1
// 00431622  68d8c59300           push 0x93c5d8
// 00431627  64a100000000         mov eax, dword ptr fs:[0]
// 0043162d  50                   push eax
// 0043162e  64892500000000       mov dword ptr fs:[0], esp
// 00431635  51                   push ecx
// 00431636  56                   push esi
// 00431637  8bf1                 mov esi, ecx
// 00431639  89742404             mov dword ptr [esp + 4], esi
// 0043163d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00431645  e8467c2300           call 0x669290
// 0043164a  8b06                 mov eax, dword ptr [esi]
// 0043164c  50                   push eax
// 0043164d  e808223c00           call 0x7f385a
// 00431652  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00431656  83c404               add esp, 4
// 00431659  5e                   pop esi
// 0043165a  64890d00000000       mov dword ptr fs:[0], ecx
// 00431661  83c410               add esp, 0x10
// 00431664  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
