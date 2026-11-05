// from server: 100% by auto
// roc 2011-06 005459d0  unit: G3D::ParseError  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005459d0
//
// 005459d0  6aff                 push -1
// 005459d2  6868a39d00           push 0x9da368
// 005459d7  64a100000000         mov eax, dword ptr fs:[0]
// 005459dd  50                   push eax
// 005459de  64892500000000       mov dword ptr fs:[0], esp
// 005459e5  51                   push ecx
// 005459e6  56                   push esi
// 005459e7  8bf1                 mov esi, ecx
// 005459e9  89742404             mov dword ptr [esp + 4], esi
// 005459ed  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005459f5  e8d6feffff           call 0x5458d0
// 005459fa  8b06                 mov eax, dword ptr [esi]
// 005459fc  50                   push eax
// 005459fd  e856462c00           call 0x80a058
// 00545a02  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00545a06  83c404               add esp, 4
// 00545a09  5e                   pop esi
// 00545a0a  64890d00000000       mov dword ptr fs:[0], ecx
// 00545a11  83c410               add esp, 0x10
// 00545a14  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
