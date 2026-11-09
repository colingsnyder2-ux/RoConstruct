// from server: 100% by auto
// roc 2009-12 006bf2b0  unit: RBX::VInstance::?$NonFactoryProduct  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006bf2b0
//
// 006bf2b0  6aff                 push -1
// 006bf2b2  68d8c59300           push 0x93c5d8
// 006bf2b7  64a100000000         mov eax, dword ptr fs:[0]
// 006bf2bd  50                   push eax
// 006bf2be  64892500000000       mov dword ptr fs:[0], esp
// 006bf2c5  51                   push ecx
// 006bf2c6  56                   push esi
// 006bf2c7  8bf1                 mov esi, ecx
// 006bf2c9  89742404             mov dword ptr [esp + 4], esi
// 006bf2cd  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006bf2d5  e886f3ffff           call 0x6be660
// 006bf2da  8b4614               mov eax, dword ptr [esi + 0x14]
// 006bf2dd  50                   push eax
// 006bf2de  e877451300           call 0x7f385a
// 006bf2e3  8b0e                 mov ecx, dword ptr [esi]
// 006bf2e5  51                   push ecx
// 006bf2e6  c7461400000000       mov dword ptr [esi + 0x14], 0
// 006bf2ed  e868451300           call 0x7f385a
// 006bf2f2  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006bf2f6  83c408               add esp, 8
// 006bf2f9  5e                   pop esi
// 006bf2fa  64890d00000000       mov dword ptr fs:[0], ecx
// 006bf301  83c410               add esp, 0x10
// 006bf304  c3                   ret 
// standard library list<string> (function ??1?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
