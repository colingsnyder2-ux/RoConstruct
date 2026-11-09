// from server: 100% by auto
// roc 2011-06 006f34b0  unit: RBX::VDebrisService::?$FactoryProduct  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006f34b0
//
// 006f34b0  6aff                 push -1
// 006f34b2  6868a39d00           push 0x9da368
// 006f34b7  64a100000000         mov eax, dword ptr fs:[0]
// 006f34bd  50                   push eax
// 006f34be  64892500000000       mov dword ptr fs:[0], esp
// 006f34c5  51                   push ecx
// 006f34c6  56                   push esi
// 006f34c7  8bf1                 mov esi, ecx
// 006f34c9  89742404             mov dword ptr [esp + 4], esi
// 006f34cd  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006f34d5  e846feffff           call 0x6f3320
// 006f34da  8b06                 mov eax, dword ptr [esi]
// 006f34dc  50                   push eax
// 006f34dd  e8766b1100           call 0x80a058
// 006f34e2  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006f34e6  83c404               add esp, 4
// 006f34e9  5e                   pop esi
// 006f34ea  64890d00000000       mov dword ptr fs:[0], ecx
// 006f34f1  83c410               add esp, 0x10
// 006f34f4  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
