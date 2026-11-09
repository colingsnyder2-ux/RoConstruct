// from server: 100% by auto
// roc 2011-06 006c1a90  unit: RBX::InsertService  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006c1a90
//
// 006c1a90  6aff                 push -1
// 006c1a92  6829e09e00           push 0x9ee029
// 006c1a97  64a100000000         mov eax, dword ptr fs:[0]
// 006c1a9d  50                   push eax
// 006c1a9e  64892500000000       mov dword ptr fs:[0], esp
// 006c1aa5  51                   push ecx
// 006c1aa6  56                   push esi
// 006c1aa7  57                   push edi
// 006c1aa8  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 006c1aac  8bf1                 mov esi, ecx
// 006c1aae  57                   push edi
// 006c1aaf  8974240c             mov dword ptr [esp + 0xc], esi
// 006c1ab3  ff15c804a400         call dword ptr [0xa404c8]
// 006c1ab9  83c71c               add edi, 0x1c
// 006c1abc  57                   push edi
// 006c1abd  8d4e1c               lea ecx, [esi + 0x1c]
// 006c1ac0  c744241800000000     mov dword ptr [esp + 0x18], 0
// 006c1ac8  ff15c804a400         call dword ptr [0xa404c8]
// 006c1ace  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006c1ad2  5f                   pop edi
// 006c1ad3  8bc6                 mov eax, esi
// 006c1ad5  5e                   pop esi
// 006c1ad6  64890d00000000       mov dword ptr fs:[0], ecx
// 006c1add  83c410               add esp, 0x10
// 006c1ae0  c20400               ret 4
// standard library map_str<string> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@ABU01@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
