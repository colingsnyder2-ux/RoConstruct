// from server: 100% by auto
// roc 2012-06 004af460  unit: VerbBinderJob  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004af460
//
// 004af460  6aff                 push -1
// 004af462  68e9f3a900           push 0xa9f3e9
// 004af467  64a100000000         mov eax, dword ptr fs:[0]
// 004af46d  50                   push eax
// 004af46e  64892500000000       mov dword ptr fs:[0], esp
// 004af475  51                   push ecx
// 004af476  56                   push esi
// 004af477  8bf1                 mov esi, ecx
// 004af479  89742404             mov dword ptr [esp + 4], esi
// 004af47d  8d4e1c               lea ecx, [esi + 0x1c]
// 004af480  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004af488  ff153c26b200         call dword ptr [0xb2263c]
// 004af48e  8bce                 mov ecx, esi
// 004af490  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 004af498  ff153c26b200         call dword ptr [0xb2263c]
// 004af49e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004af4a2  5e                   pop esi
// 004af4a3  64890d00000000       mov dword ptr fs:[0], ecx
// 004af4aa  83c410               add esp, 0x10
// 004af4ad  c3                   ret 
// standard library map_str<string> (function ??1?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@XZ)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
