// from server: 100% by auto
// roc 2009-12 006c34c0  unit: RBX::VContentProvider::?$BoundFuncDesc  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006c34c0
//
// 006c34c0  6aff                 push -1
// 006c34c2  68d8c59300           push 0x93c5d8
// 006c34c7  64a100000000         mov eax, dword ptr fs:[0]
// 006c34cd  50                   push eax
// 006c34ce  64892500000000       mov dword ptr fs:[0], esp
// 006c34d5  51                   push ecx
// 006c34d6  56                   push esi
// 006c34d7  8bf1                 mov esi, ecx
// 006c34d9  89742404             mov dword ptr [esp + 4], esi
// 006c34dd  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006c34e5  e8e6fbffff           call 0x6c30d0
// 006c34ea  8b4614               mov eax, dword ptr [esi + 0x14]
// 006c34ed  50                   push eax
// 006c34ee  e867031300           call 0x7f385a
// 006c34f3  8b0e                 mov ecx, dword ptr [esi]
// 006c34f5  51                   push ecx
// 006c34f6  c7461400000000       mov dword ptr [esi + 0x14], 0
// 006c34fd  e858031300           call 0x7f385a
// 006c3502  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006c3506  83c408               add esp, 8
// 006c3509  5e                   pop esi
// 006c350a  64890d00000000       mov dword ptr fs:[0], ecx
// 006c3511  83c410               add esp, 0x10
// 006c3514  c3                   ret 
// standard library list<string> (function ??1?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
