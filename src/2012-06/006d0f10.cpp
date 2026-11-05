// from server: 100% by auto
// roc 2012-06 006d0f10  unit: std::D::DU?$char_traits::PAV?$basic_altstringbuf::?$sp_counted_impl_pd  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006d0f10
//
// 006d0f10  6aff                 push -1
// 006d0f12  6828acab00           push 0xabac28
// 006d0f17  64a100000000         mov eax, dword ptr fs:[0]
// 006d0f1d  50                   push eax
// 006d0f1e  64892500000000       mov dword ptr fs:[0], esp
// 006d0f25  51                   push ecx
// 006d0f26  56                   push esi
// 006d0f27  8bf1                 mov esi, ecx
// 006d0f29  89742404             mov dword ptr [esp + 4], esi
// 006d0f2d  8d4e1c               lea ecx, [esi + 0x1c]
// 006d0f30  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006d0f38  ff153c26b200         call dword ptr [0xb2263c]
// 006d0f3e  8bce                 mov ecx, esi
// 006d0f40  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 006d0f48  ff153c26b200         call dword ptr [0xb2263c]
// 006d0f4e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006d0f52  5e                   pop esi
// 006d0f53  64890d00000000       mov dword ptr fs:[0], ecx
// 006d0f5a  83c410               add esp, 0x10
// 006d0f5d  c3                   ret 
// standard library map_str<string> (function ??1?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@XZ)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
