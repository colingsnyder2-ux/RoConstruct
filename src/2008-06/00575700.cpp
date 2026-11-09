// from server: 100% by auto
// roc 2008-06 00575700  unit: RBX::ServiceProvider  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00575700
//
// 00575700  6aff                 push -1
// 00575702  68a8057d00           push 0x7d05a8
// 00575707  64a100000000         mov eax, dword ptr fs:[0]
// 0057570d  50                   push eax
// 0057570e  64892500000000       mov dword ptr fs:[0], esp
// 00575715  51                   push ecx
// 00575716  56                   push esi
// 00575717  8bf1                 mov esi, ecx
// 00575719  89742404             mov dword ptr [esp + 4], esi
// 0057571d  8d4e1c               lea ecx, [esi + 0x1c]
// 00575720  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00575728  ff1568248000         call dword ptr [0x802468]
// 0057572e  8bce                 mov ecx, esi
// 00575730  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00575738  ff1568248000         call dword ptr [0x802468]
// 0057573e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00575742  5e                   pop esi
// 00575743  64890d00000000       mov dword ptr fs:[0], ecx
// 0057574a  83c410               add esp, 0x10
// 0057574d  c3                   ret 
// standard library map_str<string> (function ??1?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@XZ)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
