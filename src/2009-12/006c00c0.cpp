// from server: 100% by auto
// roc 2009-12 006c00c0  unit: RBX::VInstance::?$NonFactoryProduct  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006c00c0
//
// 006c00c0  6aff                 push -1
// 006c00c2  68d8c59300           push 0x93c5d8
// 006c00c7  64a100000000         mov eax, dword ptr fs:[0]
// 006c00cd  50                   push eax
// 006c00ce  64892500000000       mov dword ptr fs:[0], esp
// 006c00d5  51                   push ecx
// 006c00d6  56                   push esi
// 006c00d7  8bf1                 mov esi, ecx
// 006c00d9  89742404             mov dword ptr [esp + 4], esi
// 006c00dd  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006c00e5  e876f7ffff           call 0x6bf860
// 006c00ea  8b4614               mov eax, dword ptr [esi + 0x14]
// 006c00ed  50                   push eax
// 006c00ee  e867371300           call 0x7f385a
// 006c00f3  8b0e                 mov ecx, dword ptr [esi]
// 006c00f5  51                   push ecx
// 006c00f6  c7461400000000       mov dword ptr [esi + 0x14], 0
// 006c00fd  e858371300           call 0x7f385a
// 006c0102  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006c0106  83c408               add esp, 8
// 006c0109  5e                   pop esi
// 006c010a  64890d00000000       mov dword ptr fs:[0], ecx
// 006c0111  83c410               add esp, 0x10
// 006c0114  c3                   ret 
// standard library list<string> (function ??1?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
