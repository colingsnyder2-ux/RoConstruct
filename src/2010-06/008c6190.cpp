// from server: 100% by auto
// roc 2010-06 008c6190  unit: RBX::AdornRbxGfx  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008c6190
//
// 008c6190  6aff                 push -1
// 008c6192  6889009a00           push 0x9a0089
// 008c6197  64a100000000         mov eax, dword ptr fs:[0]
// 008c619d  50                   push eax
// 008c619e  64892500000000       mov dword ptr fs:[0], esp
// 008c61a5  51                   push ecx
// 008c61a6  56                   push esi
// 008c61a7  8bf1                 mov esi, ecx
// 008c61a9  89742404             mov dword ptr [esp + 4], esi
// 008c61ad  8d4e1c               lea ecx, [esi + 0x1c]
// 008c61b0  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008c61b8  ff150cb89e00         call dword ptr [0x9eb80c]
// 008c61be  8bce                 mov ecx, esi
// 008c61c0  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 008c61c8  ff1500a49e00         call dword ptr [0x9ea400]
// 008c61ce  8b4c2408             mov ecx, dword ptr [esp + 8]
// 008c61d2  5e                   pop esi
// 008c61d3  64890d00000000       mov dword ptr fs:[0], ecx
// 008c61da  83c410               add esp, 0x10
// 008c61dd  c3                   ret 
// standard library map_str<string> (function ??1?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@XZ)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
