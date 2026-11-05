// from server: 100% by auto
// roc 2012-06 00415360  unit: UString_sink::?$stream_buffer  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00415360
//
// 00415360  6aff                 push -1
// 00415362  68e9f3a900           push 0xa9f3e9
// 00415367  64a100000000         mov eax, dword ptr fs:[0]
// 0041536d  50                   push eax
// 0041536e  64892500000000       mov dword ptr fs:[0], esp
// 00415375  51                   push ecx
// 00415376  56                   push esi
// 00415377  8bf1                 mov esi, ecx
// 00415379  89742404             mov dword ptr [esp + 4], esi
// 0041537d  8d4e1c               lea ecx, [esi + 0x1c]
// 00415380  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00415388  ff156826b200         call dword ptr [0xb22668]
// 0041538e  8bce                 mov ecx, esi
// 00415390  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00415398  ff153c26b200         call dword ptr [0xb2263c]
// 0041539e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004153a2  5e                   pop esi
// 004153a3  64890d00000000       mov dword ptr fs:[0], ecx
// 004153aa  83c410               add esp, 0x10
// 004153ad  c3                   ret 
// standard library map_str<string> (function ??1?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@XZ)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
