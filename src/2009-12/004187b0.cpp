// from server: 100% by auto
// roc 2009-12 004187b0  unit: RBX::VTool::?$FactoryProduct::Creator  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004187b0
//
// 004187b0  6aff                 push -1
// 004187b2  68d8c59300           push 0x93c5d8
// 004187b7  64a100000000         mov eax, dword ptr fs:[0]
// 004187bd  50                   push eax
// 004187be  64892500000000       mov dword ptr fs:[0], esp
// 004187c5  51                   push ecx
// 004187c6  56                   push esi
// 004187c7  8bf1                 mov esi, ecx
// 004187c9  89742404             mov dword ptr [esp + 4], esi
// 004187cd  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004187d5  e826feffff           call 0x418600
// 004187da  8b06                 mov eax, dword ptr [esi]
// 004187dc  50                   push eax
// 004187dd  e878b03d00           call 0x7f385a
// 004187e2  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004187e6  83c404               add esp, 4
// 004187e9  5e                   pop esi
// 004187ea  64890d00000000       mov dword ptr fs:[0], ecx
// 004187f1  83c410               add esp, 0x10
// 004187f4  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
