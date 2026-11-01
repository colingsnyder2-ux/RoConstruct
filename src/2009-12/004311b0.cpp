// from server: 100% by auto
// roc 2009-12 004311b0  unit: COutputView  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004311b0
//
// 004311b0  6aff                 push -1
// 004311b2  68d8c59300           push 0x93c5d8
// 004311b7  64a100000000         mov eax, dword ptr fs:[0]
// 004311bd  50                   push eax
// 004311be  64892500000000       mov dword ptr fs:[0], esp
// 004311c5  51                   push ecx
// 004311c6  56                   push esi
// 004311c7  8bf1                 mov esi, ecx
// 004311c9  89742404             mov dword ptr [esp + 4], esi
// 004311cd  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004311d5  e856fbffff           call 0x430d30
// 004311da  8b06                 mov eax, dword ptr [esi]
// 004311dc  50                   push eax
// 004311dd  e878263c00           call 0x7f385a
// 004311e2  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004311e6  83c404               add esp, 4
// 004311e9  5e                   pop esi
// 004311ea  64890d00000000       mov dword ptr fs:[0], ecx
// 004311f1  83c410               add esp, 0x10
// 004311f4  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
