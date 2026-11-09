// from server: 100% by auto
// roc 2007-08 005573f0  unit: ChatEnter  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005573f0
//
// 005573f0  6aff                 push -1
// 005573f2  6858197500           push 0x751958
// 005573f7  64a100000000         mov eax, dword ptr fs:[0]
// 005573fd  50                   push eax
// 005573fe  64892500000000       mov dword ptr fs:[0], esp
// 00557405  51                   push ecx
// 00557406  56                   push esi
// 00557407  8bf1                 mov esi, ecx
// 00557409  89742404             mov dword ptr [esp + 4], esi
// 0055740d  8d4e1c               lea ecx, [esi + 0x1c]
// 00557410  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00557418  ff15ace67700         call dword ptr [0x77e6ac]
// 0055741e  8bce                 mov ecx, esi
// 00557420  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00557428  ff15ace67700         call dword ptr [0x77e6ac]
// 0055742e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00557432  5e                   pop esi
// 00557433  64890d00000000       mov dword ptr fs:[0], ecx
// 0055743a  83c410               add esp, 0x10
// 0055743d  c3                   ret 
// standard library map_str<string> (function ??1?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@XZ)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
