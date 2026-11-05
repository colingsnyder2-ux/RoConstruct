// from server: 100% by auto
// roc 2011-06 00425360  unit: CInstanceRecord  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00425360
//
// 00425360  6aff                 push -1
// 00425362  6868a39d00           push 0x9da368
// 00425367  64a100000000         mov eax, dword ptr fs:[0]
// 0042536d  50                   push eax
// 0042536e  64892500000000       mov dword ptr fs:[0], esp
// 00425375  51                   push ecx
// 00425376  56                   push esi
// 00425377  8bf1                 mov esi, ecx
// 00425379  89742404             mov dword ptr [esp + 4], esi
// 0042537d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00425385  e886fcffff           call 0x425010
// 0042538a  8b06                 mov eax, dword ptr [esi]
// 0042538c  50                   push eax
// 0042538d  e8c64c3e00           call 0x80a058
// 00425392  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00425396  83c404               add esp, 4
// 00425399  5e                   pop esi
// 0042539a  64890d00000000       mov dword ptr fs:[0], ecx
// 004253a1  83c410               add esp, 0x10
// 004253a4  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
