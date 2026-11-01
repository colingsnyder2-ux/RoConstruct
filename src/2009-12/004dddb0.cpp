// from server: 100% by auto
// roc 2009-12 004dddb0  unit: G3D::Shader  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004dddb0
//
// 004dddb0  6aff                 push -1
// 004dddb2  68d8c59300           push 0x93c5d8
// 004dddb7  64a100000000         mov eax, dword ptr fs:[0]
// 004dddbd  50                   push eax
// 004dddbe  64892500000000       mov dword ptr fs:[0], esp
// 004dddc5  51                   push ecx
// 004dddc6  56                   push esi
// 004dddc7  8bf1                 mov esi, ecx
// 004dddc9  89742404             mov dword ptr [esp + 4], esi
// 004dddcd  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004dddd5  e816f8ffff           call 0x4dd5f0
// 004dddda  8b06                 mov eax, dword ptr [esi]
// 004ddddc  50                   push eax
// 004ddddd  e8785a3100           call 0x7f385a
// 004ddde2  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004ddde6  83c404               add esp, 4
// 004ddde9  5e                   pop esi
// 004dddea  64890d00000000       mov dword ptr fs:[0], ecx
// 004dddf1  83c410               add esp, 0x10
// 004dddf4  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
