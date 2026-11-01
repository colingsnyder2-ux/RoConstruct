// from server: 100% by auto
// roc 2009-12 005312b0  unit: RBX::VInstance::$$A6AXV?$shared_ptr::?$signal::Vslot::?$sp_counted_impl_p  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005312b0
//
// 005312b0  6aff                 push -1
// 005312b2  68d8c59300           push 0x93c5d8
// 005312b7  64a100000000         mov eax, dword ptr fs:[0]
// 005312bd  50                   push eax
// 005312be  64892500000000       mov dword ptr fs:[0], esp
// 005312c5  51                   push ecx
// 005312c6  56                   push esi
// 005312c7  8bf1                 mov esi, ecx
// 005312c9  89742404             mov dword ptr [esp + 4], esi
// 005312cd  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005312d5  e866bff2ff           call 0x45d240
// 005312da  8b06                 mov eax, dword ptr [esi]
// 005312dc  50                   push eax
// 005312dd  e878252c00           call 0x7f385a
// 005312e2  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005312e6  83c404               add esp, 4
// 005312e9  5e                   pop esi
// 005312ea  64890d00000000       mov dword ptr fs:[0], ecx
// 005312f1  83c410               add esp, 0x10
// 005312f4  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
