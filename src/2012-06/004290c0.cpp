// from server: 100% by auto
// roc 2012-06 004290c0  unit: RBX::VInstance::$$A6AXV?$shared_ptr::?$signal::Vslot::?$callable  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004290c0
//
// 004290c0  6aff                 push -1
// 004290c2  681890ad00           push 0xad9018
// 004290c7  64a100000000         mov eax, dword ptr fs:[0]
// 004290cd  50                   push eax
// 004290ce  64892500000000       mov dword ptr fs:[0], esp
// 004290d5  51                   push ecx
// 004290d6  56                   push esi
// 004290d7  8bf1                 mov esi, ecx
// 004290d9  89742404             mov dword ptr [esp + 4], esi
// 004290dd  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004290e5  e8d6fdffff           call 0x428ec0
// 004290ea  8b06                 mov eax, dword ptr [esi]
// 004290ec  50                   push eax
// 004290ed  e822905500           call 0x982114
// 004290f2  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004290f6  83c404               add esp, 4
// 004290f9  5e                   pop esi
// 004290fa  64890d00000000       mov dword ptr fs:[0], ecx
// 00429101  83c410               add esp, 0x10
// 00429104  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
