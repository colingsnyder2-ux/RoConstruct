// from server: 100% by auto
// roc 2009-12 0057d100  unit: std::Vlength_error::U?$error_info_injector::?$clone_impl  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0057d100
//
// 0057d100  6aff                 push -1
// 0057d102  68d8c59300           push 0x93c5d8
// 0057d107  64a100000000         mov eax, dword ptr fs:[0]
// 0057d10d  50                   push eax
// 0057d10e  64892500000000       mov dword ptr fs:[0], esp
// 0057d115  51                   push ecx
// 0057d116  56                   push esi
// 0057d117  8bf1                 mov esi, ecx
// 0057d119  89742404             mov dword ptr [esp + 4], esi
// 0057d11d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0057d125  e876f7ffff           call 0x57c8a0
// 0057d12a  8b4614               mov eax, dword ptr [esi + 0x14]
// 0057d12d  50                   push eax
// 0057d12e  e827672700           call 0x7f385a
// 0057d133  8b0e                 mov ecx, dword ptr [esi]
// 0057d135  51                   push ecx
// 0057d136  c7461400000000       mov dword ptr [esi + 0x14], 0
// 0057d13d  e818672700           call 0x7f385a
// 0057d142  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0057d146  83c408               add esp, 8
// 0057d149  5e                   pop esi
// 0057d14a  64890d00000000       mov dword ptr fs:[0], ecx
// 0057d151  83c410               add esp, 0x10
// 0057d154  c3                   ret 
// standard library list<string> (function ??1?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
