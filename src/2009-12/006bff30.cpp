// from server: 100% by auto
// roc 2009-12 006bff30  unit: RBX::VInstance::?$NonFactoryProduct  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006bff30
//
// 006bff30  6aff                 push -1
// 006bff32  68d8c59300           push 0x93c5d8
// 006bff37  64a100000000         mov eax, dword ptr fs:[0]
// 006bff3d  50                   push eax
// 006bff3e  64892500000000       mov dword ptr fs:[0], esp
// 006bff45  51                   push ecx
// 006bff46  56                   push esi
// 006bff47  8bf1                 mov esi, ecx
// 006bff49  89742404             mov dword ptr [esp + 4], esi
// 006bff4d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006bff55  e846e7ffff           call 0x6be6a0
// 006bff5a  8b06                 mov eax, dword ptr [esi]
// 006bff5c  50                   push eax
// 006bff5d  e8f8381300           call 0x7f385a
// 006bff62  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006bff66  83c404               add esp, 4
// 006bff69  5e                   pop esi
// 006bff6a  64890d00000000       mov dword ptr fs:[0], ecx
// 006bff71  83c410               add esp, 0x10
// 006bff74  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
