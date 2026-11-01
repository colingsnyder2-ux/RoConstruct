// from server: 100% by auto
// roc 2009-12 00702fc0  unit: RBX::Assembly  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00702fc0
//
// 00702fc0  6aff                 push -1
// 00702fc2  6818859400           push 0x948518
// 00702fc7  64a100000000         mov eax, dword ptr fs:[0]
// 00702fcd  50                   push eax
// 00702fce  64892500000000       mov dword ptr fs:[0], esp
// 00702fd5  51                   push ecx
// 00702fd6  56                   push esi
// 00702fd7  8bf1                 mov esi, ecx
// 00702fd9  89742404             mov dword ptr [esp + 4], esi
// 00702fdd  8d4e1c               lea ecx, [esi + 0x1c]
// 00702fe0  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00702fe8  ff15e4b69800         call dword ptr [0x98b6e4]
// 00702fee  8bce                 mov ecx, esi
// 00702ff0  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00702ff8  ff15e4b69800         call dword ptr [0x98b6e4]
// 00702ffe  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00703002  5e                   pop esi
// 00703003  64890d00000000       mov dword ptr fs:[0], ecx
// 0070300a  83c410               add esp, 0x10
// 0070300d  c3                   ret 
// standard library map_str<string> (function ??1?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@XZ)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
