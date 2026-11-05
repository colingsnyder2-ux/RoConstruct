// from server: 100% by auto
// roc 2012-06 004c2400  unit: RBX::AdornRbxGfx  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004c2400
//
// 004c2400  6aff                 push -1
// 004c2402  68e9f3a900           push 0xa9f3e9
// 004c2407  64a100000000         mov eax, dword ptr fs:[0]
// 004c240d  50                   push eax
// 004c240e  64892500000000       mov dword ptr fs:[0], esp
// 004c2415  51                   push ecx
// 004c2416  56                   push esi
// 004c2417  8bf1                 mov esi, ecx
// 004c2419  89742404             mov dword ptr [esp + 4], esi
// 004c241d  8d4e1c               lea ecx, [esi + 0x1c]
// 004c2420  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004c2428  ff152c30b200         call dword ptr [0xb2302c]
// 004c242e  8bce                 mov ecx, esi
// 004c2430  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 004c2438  ff153c26b200         call dword ptr [0xb2263c]
// 004c243e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004c2442  5e                   pop esi
// 004c2443  64890d00000000       mov dword ptr fs:[0], ecx
// 004c244a  83c410               add esp, 0x10
// 004c244d  c3                   ret 
// standard library map_str<string> (function ??1?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@XZ)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
