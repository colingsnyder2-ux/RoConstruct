// from server: 100% by auto
// roc 2009-12 0073d750  unit: RBX::BillboardGui  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0073d750
//
// 0073d750  6aff                 push -1
// 0073d752  68d8c59300           push 0x93c5d8
// 0073d757  64a100000000         mov eax, dword ptr fs:[0]
// 0073d75d  50                   push eax
// 0073d75e  64892500000000       mov dword ptr fs:[0], esp
// 0073d765  51                   push ecx
// 0073d766  56                   push esi
// 0073d767  8bf1                 mov esi, ecx
// 0073d769  89742404             mov dword ptr [esp + 4], esi
// 0073d76d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0073d775  e886ffffff           call 0x73d700
// 0073d77a  8b06                 mov eax, dword ptr [esi]
// 0073d77c  50                   push eax
// 0073d77d  e8d8600b00           call 0x7f385a
// 0073d782  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0073d786  83c404               add esp, 4
// 0073d789  5e                   pop esi
// 0073d78a  64890d00000000       mov dword ptr fs:[0], ecx
// 0073d791  83c410               add esp, 0x10
// 0073d794  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
