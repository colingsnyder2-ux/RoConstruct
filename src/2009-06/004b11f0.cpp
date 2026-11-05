// from server: 100% by auto
// roc 2009-06 004b11f0  unit: G3D::Shader  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004b11f0
//
// 004b11f0  6aff                 push -1
// 004b11f2  6878ef8600           push 0x86ef78
// 004b11f7  64a100000000         mov eax, dword ptr fs:[0]
// 004b11fd  50                   push eax
// 004b11fe  64892500000000       mov dword ptr fs:[0], esp
// 004b1205  51                   push ecx
// 004b1206  56                   push esi
// 004b1207  8bf1                 mov esi, ecx
// 004b1209  89742404             mov dword ptr [esp + 4], esi
// 004b120d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004b1215  e896f8ffff           call 0x4b0ab0
// 004b121a  8b06                 mov eax, dword ptr [esi]
// 004b121c  50                   push eax
// 004b121d  e810782600           call 0x718a32
// 004b1222  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004b1226  83c404               add esp, 4
// 004b1229  5e                   pop esi
// 004b122a  64890d00000000       mov dword ptr fs:[0], ecx
// 004b1231  83c410               add esp, 0x10
// 004b1234  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
