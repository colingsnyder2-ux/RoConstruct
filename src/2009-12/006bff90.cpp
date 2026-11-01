// from server: 100% by auto
// roc 2009-12 006bff90  unit: RBX::VInstance::?$NonFactoryProduct  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006bff90
//
// 006bff90  6aff                 push -1
// 006bff92  68d8c59300           push 0x93c5d8
// 006bff97  64a100000000         mov eax, dword ptr fs:[0]
// 006bff9d  50                   push eax
// 006bff9e  64892500000000       mov dword ptr fs:[0], esp
// 006bffa5  51                   push ecx
// 006bffa6  56                   push esi
// 006bffa7  8bf1                 mov esi, ecx
// 006bffa9  89742404             mov dword ptr [esp + 4], esi
// 006bffad  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006bffb5  e856ecffff           call 0x6bec10
// 006bffba  8b4614               mov eax, dword ptr [esi + 0x14]
// 006bffbd  50                   push eax
// 006bffbe  e897381300           call 0x7f385a
// 006bffc3  8b0e                 mov ecx, dword ptr [esi]
// 006bffc5  51                   push ecx
// 006bffc6  c7461400000000       mov dword ptr [esi + 0x14], 0
// 006bffcd  e888381300           call 0x7f385a
// 006bffd2  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006bffd6  83c408               add esp, 8
// 006bffd9  5e                   pop esi
// 006bffda  64890d00000000       mov dword ptr fs:[0], ecx
// 006bffe1  83c410               add esp, 0x10
// 006bffe4  c3                   ret 
// standard library list<string> (function ??1?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
