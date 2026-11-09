// from server: 100% by auto
// roc 2012-06 0093eb00  unit: RBX::ChatLine  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0093eb00
//
// 0093eb00  6aff                 push -1
// 0093eb02  681890ad00           push 0xad9018
// 0093eb07  64a100000000         mov eax, dword ptr fs:[0]
// 0093eb0d  50                   push eax
// 0093eb0e  64892500000000       mov dword ptr fs:[0], esp
// 0093eb15  51                   push ecx
// 0093eb16  56                   push esi
// 0093eb17  8bf1                 mov esi, ecx
// 0093eb19  89742404             mov dword ptr [esp + 4], esi
// 0093eb1d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0093eb25  e8c6f5ffff           call 0x93e0f0
// 0093eb2a  8b06                 mov eax, dword ptr [esi]
// 0093eb2c  50                   push eax
// 0093eb2d  e8e2350400           call 0x982114
// 0093eb32  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0093eb36  83c404               add esp, 4
// 0093eb39  5e                   pop esi
// 0093eb3a  64890d00000000       mov dword ptr fs:[0], ecx
// 0093eb41  83c410               add esp, 0x10
// 0093eb44  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
