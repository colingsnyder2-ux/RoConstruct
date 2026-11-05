// from server: 100% by auto
// roc 2010-06 00413940  unit: CutVerb  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00413940
//
// 00413940  6aff                 push -1
// 00413942  6889009a00           push 0x9a0089
// 00413947  64a100000000         mov eax, dword ptr fs:[0]
// 0041394d  50                   push eax
// 0041394e  64892500000000       mov dword ptr fs:[0], esp
// 00413955  51                   push ecx
// 00413956  56                   push esi
// 00413957  8bf1                 mov esi, ecx
// 00413959  89742404             mov dword ptr [esp + 4], esi
// 0041395d  8d4e1c               lea ecx, [esi + 0x1c]
// 00413960  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00413968  ff1500a49e00         call dword ptr [0x9ea400]
// 0041396e  8bce                 mov ecx, esi
// 00413970  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00413978  ff1500a49e00         call dword ptr [0x9ea400]
// 0041397e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00413982  5e                   pop esi
// 00413983  64890d00000000       mov dword ptr fs:[0], ecx
// 0041398a  83c410               add esp, 0x10
// 0041398d  c3                   ret 
// standard library map_str<string> (function ??1?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@XZ)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
