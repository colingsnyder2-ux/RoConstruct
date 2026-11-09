// from server: 100% by auto
// roc 2009-06 005faf30  unit: RBX::DataModel::PAVGenericJob::?$thread_specific_ptr::PAUdelete_data::?$sp_counted_impl_pd  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005faf30
//
// 005faf30  6aff                 push -1
// 005faf32  68083a8600           push 0x863a08
// 005faf37  64a100000000         mov eax, dword ptr fs:[0]
// 005faf3d  50                   push eax
// 005faf3e  64892500000000       mov dword ptr fs:[0], esp
// 005faf45  51                   push ecx
// 005faf46  56                   push esi
// 005faf47  8bf1                 mov esi, ecx
// 005faf49  89742404             mov dword ptr [esp + 4], esi
// 005faf4d  8d4e1c               lea ecx, [esi + 0x1c]
// 005faf50  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005faf58  ff15c4e48900         call dword ptr [0x89e4c4]
// 005faf5e  8bce                 mov ecx, esi
// 005faf60  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 005faf68  ff15c4e48900         call dword ptr [0x89e4c4]
// 005faf6e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005faf72  5e                   pop esi
// 005faf73  64890d00000000       mov dword ptr fs:[0], ecx
// 005faf7a  83c410               add esp, 0x10
// 005faf7d  c3                   ret 
// standard library map_str<string> (function ??1?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@XZ)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
