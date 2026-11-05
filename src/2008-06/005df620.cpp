// from server: 100% by auto
// roc 2008-06 005df620  unit: RBX::Lighting  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005df620
//
// 005df620  6aff                 push -1
// 005df622  68496b7c00           push 0x7c6b49
// 005df627  64a100000000         mov eax, dword ptr fs:[0]
// 005df62d  50                   push eax
// 005df62e  64892500000000       mov dword ptr fs:[0], esp
// 005df635  51                   push ecx
// 005df636  56                   push esi
// 005df637  8bf1                 mov esi, ecx
// 005df639  89742404             mov dword ptr [esp + 4], esi
// 005df63d  8d4e1c               lea ecx, [esi + 0x1c]
// 005df640  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005df648  ff1568248000         call dword ptr [0x802468]
// 005df64e  8bce                 mov ecx, esi
// 005df650  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 005df658  ff1568248000         call dword ptr [0x802468]
// 005df65e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005df662  5e                   pop esi
// 005df663  64890d00000000       mov dword ptr fs:[0], ecx
// 005df66a  83c410               add esp, 0x10
// 005df66d  c3                   ret 
// standard library map_str<string> (function ??1?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@XZ)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
