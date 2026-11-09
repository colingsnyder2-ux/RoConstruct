// from server: 100% by auto
// roc 2008-06 0066fc30  unit: RBX::AdornRbxGfx  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0066fc30
//
// 0066fc30  6aff                 push -1
// 0066fc32  68496b7c00           push 0x7c6b49
// 0066fc37  64a100000000         mov eax, dword ptr fs:[0]
// 0066fc3d  50                   push eax
// 0066fc3e  64892500000000       mov dword ptr fs:[0], esp
// 0066fc45  51                   push ecx
// 0066fc46  56                   push esi
// 0066fc47  8bf1                 mov esi, ecx
// 0066fc49  89742404             mov dword ptr [esp + 4], esi
// 0066fc4d  8d4e1c               lea ecx, [esi + 0x1c]
// 0066fc50  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0066fc58  ff15a44c8000         call dword ptr [0x804ca4]
// 0066fc5e  8bce                 mov ecx, esi
// 0066fc60  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0066fc68  ff1568248000         call dword ptr [0x802468]
// 0066fc6e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0066fc72  5e                   pop esi
// 0066fc73  64890d00000000       mov dword ptr fs:[0], ecx
// 0066fc7a  83c410               add esp, 0x10
// 0066fc7d  c3                   ret 
// standard library map_str<string> (function ??1?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@XZ)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
