// from server: 100% by auto
// roc 2009-12 00700e10  unit: RBX::TimerService  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00700e10
//
// 00700e10  6aff                 push -1
// 00700e12  68d8c59300           push 0x93c5d8
// 00700e17  64a100000000         mov eax, dword ptr fs:[0]
// 00700e1d  50                   push eax
// 00700e1e  64892500000000       mov dword ptr fs:[0], esp
// 00700e25  51                   push ecx
// 00700e26  56                   push esi
// 00700e27  8bf1                 mov esi, ecx
// 00700e29  89742404             mov dword ptr [esp + 4], esi
// 00700e2d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00700e35  e8e6fcffff           call 0x700b20
// 00700e3a  8b4614               mov eax, dword ptr [esi + 0x14]
// 00700e3d  50                   push eax
// 00700e3e  e8172a0f00           call 0x7f385a
// 00700e43  8b0e                 mov ecx, dword ptr [esi]
// 00700e45  51                   push ecx
// 00700e46  c7461400000000       mov dword ptr [esi + 0x14], 0
// 00700e4d  e8082a0f00           call 0x7f385a
// 00700e52  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00700e56  83c408               add esp, 8
// 00700e59  5e                   pop esi
// 00700e5a  64890d00000000       mov dword ptr fs:[0], ecx
// 00700e61  83c410               add esp, 0x10
// 00700e64  c3                   ret 
// standard library list<string> (function ??1?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
