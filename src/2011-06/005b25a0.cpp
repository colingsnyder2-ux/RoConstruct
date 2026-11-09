// from server: 100% by auto
// roc 2011-06 005b25a0  unit: RBX::VStandardOut::?$sp_counted_impl_p  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005b25a0
//
// 005b25a0  6aff                 push -1
// 005b25a2  68f81f9e00           push 0x9e1ff8
// 005b25a7  64a100000000         mov eax, dword ptr fs:[0]
// 005b25ad  50                   push eax
// 005b25ae  64892500000000       mov dword ptr fs:[0], esp
// 005b25b5  51                   push ecx
// 005b25b6  56                   push esi
// 005b25b7  8bf1                 mov esi, ecx
// 005b25b9  89742404             mov dword ptr [esp + 4], esi
// 005b25bd  8d4e1c               lea ecx, [esi + 0x1c]
// 005b25c0  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005b25c8  ff15d004a400         call dword ptr [0xa404d0]
// 005b25ce  8bce                 mov ecx, esi
// 005b25d0  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 005b25d8  ff15d004a400         call dword ptr [0xa404d0]
// 005b25de  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005b25e2  5e                   pop esi
// 005b25e3  64890d00000000       mov dword ptr fs:[0], ecx
// 005b25ea  83c410               add esp, 0x10
// 005b25ed  c3                   ret 
// standard library map_str<string> (function ??1?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@XZ)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
