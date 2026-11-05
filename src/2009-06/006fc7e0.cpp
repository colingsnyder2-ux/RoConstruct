// from server: 100% by auto
// roc 2009-06 006fc7e0  unit: RBX::BrickBuilder  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006fc7e0
//
// 006fc7e0  6aff                 push -1
// 006fc7e2  68991c8700           push 0x871c99
// 006fc7e7  64a100000000         mov eax, dword ptr fs:[0]
// 006fc7ed  50                   push eax
// 006fc7ee  64892500000000       mov dword ptr fs:[0], esp
// 006fc7f5  51                   push ecx
// 006fc7f6  56                   push esi
// 006fc7f7  8bf1                 mov esi, ecx
// 006fc7f9  89742404             mov dword ptr [esp + 4], esi
// 006fc7fd  8d4e1c               lea ecx, [esi + 0x1c]
// 006fc800  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006fc808  ff15e40e8a00         call dword ptr [0x8a0ee4]
// 006fc80e  8bce                 mov ecx, esi
// 006fc810  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 006fc818  ff15c4e48900         call dword ptr [0x89e4c4]
// 006fc81e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006fc822  5e                   pop esi
// 006fc823  64890d00000000       mov dword ptr fs:[0], ecx
// 006fc82a  83c410               add esp, 0x10
// 006fc82d  c3                   ret 
// standard library map_str<string> (function ??1?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@XZ)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
