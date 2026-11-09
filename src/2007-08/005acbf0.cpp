// from server: 100% by auto
// roc 2007-08 005acbf0  unit: RBX::Lighting  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005acbf0
//
// 005acbf0  6aff                 push -1
// 005acbf2  68397a7500           push 0x757a39
// 005acbf7  64a100000000         mov eax, dword ptr fs:[0]
// 005acbfd  50                   push eax
// 005acbfe  64892500000000       mov dword ptr fs:[0], esp
// 005acc05  51                   push ecx
// 005acc06  56                   push esi
// 005acc07  8bf1                 mov esi, ecx
// 005acc09  89742404             mov dword ptr [esp + 4], esi
// 005acc0d  8d4e1c               lea ecx, [esi + 0x1c]
// 005acc10  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005acc18  ff15ace67700         call dword ptr [0x77e6ac]
// 005acc1e  8bce                 mov ecx, esi
// 005acc20  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 005acc28  ff15ace67700         call dword ptr [0x77e6ac]
// 005acc2e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005acc32  5e                   pop esi
// 005acc33  64890d00000000       mov dword ptr fs:[0], ecx
// 005acc3a  83c410               add esp, 0x10
// 005acc3d  c3                   ret 
// standard library map_str<string> (function ??1?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@XZ)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
