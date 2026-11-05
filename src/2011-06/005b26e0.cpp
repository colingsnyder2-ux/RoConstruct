// from server: 100% by auto
// roc 2011-06 005b26e0  unit: RBX::VStandardOut::?$sp_counted_impl_p  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005b26e0
//
// 005b26e0  6aff                 push -1
// 005b26e2  68f81f9e00           push 0x9e1ff8
// 005b26e7  64a100000000         mov eax, dword ptr fs:[0]
// 005b26ed  50                   push eax
// 005b26ee  64892500000000       mov dword ptr fs:[0], esp
// 005b26f5  51                   push ecx
// 005b26f6  56                   push esi
// 005b26f7  57                   push edi
// 005b26f8  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 005b26fc  8bf1                 mov esi, ecx
// 005b26fe  57                   push edi
// 005b26ff  8974240c             mov dword ptr [esp + 0xc], esi
// 005b2703  ff15c804a400         call dword ptr [0xa404c8]
// 005b2709  83c71c               add edi, 0x1c
// 005b270c  57                   push edi
// 005b270d  8d4e1c               lea ecx, [esi + 0x1c]
// 005b2710  c744241800000000     mov dword ptr [esp + 0x18], 0
// 005b2718  ff15c804a400         call dword ptr [0xa404c8]
// 005b271e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005b2722  5f                   pop edi
// 005b2723  8bc6                 mov eax, esi
// 005b2725  5e                   pop esi
// 005b2726  64890d00000000       mov dword ptr fs:[0], ecx
// 005b272d  83c410               add esp, 0x10
// 005b2730  c20400               ret 4
// standard library map_str<string> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@ABU01@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
