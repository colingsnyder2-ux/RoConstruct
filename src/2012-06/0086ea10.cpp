// from server: 100% by auto
// roc 2012-06 0086ea10  unit: RBX::VInstance::?$NonFactoryProduct  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0086ea10
//
// 0086ea10  6aff                 push -1
// 0086ea12  681890ad00           push 0xad9018
// 0086ea17  64a100000000         mov eax, dword ptr fs:[0]
// 0086ea1d  50                   push eax
// 0086ea1e  64892500000000       mov dword ptr fs:[0], esp
// 0086ea25  51                   push ecx
// 0086ea26  56                   push esi
// 0086ea27  8bf1                 mov esi, ecx
// 0086ea29  89742404             mov dword ptr [esp + 4], esi
// 0086ea2d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0086ea35  e8e6fcffff           call 0x86e720
// 0086ea3a  8b06                 mov eax, dword ptr [esi]
// 0086ea3c  50                   push eax
// 0086ea3d  e8d2361100           call 0x982114
// 0086ea42  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0086ea46  83c404               add esp, 4
// 0086ea49  5e                   pop esi
// 0086ea4a  64890d00000000       mov dword ptr fs:[0], ecx
// 0086ea51  83c410               add esp, 0x10
// 0086ea54  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
