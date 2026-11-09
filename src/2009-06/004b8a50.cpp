// from server: 100% by auto
// roc 2009-06 004b8a50  unit: RBX::Network::Player  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004b8a50
//
// 004b8a50  6aff                 push -1
// 004b8a52  6878ef8600           push 0x86ef78
// 004b8a57  64a100000000         mov eax, dword ptr fs:[0]
// 004b8a5d  50                   push eax
// 004b8a5e  64892500000000       mov dword ptr fs:[0], esp
// 004b8a65  51                   push ecx
// 004b8a66  56                   push esi
// 004b8a67  8bf1                 mov esi, ecx
// 004b8a69  89742404             mov dword ptr [esp + 4], esi
// 004b8a6d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004b8a75  e816e7ffff           call 0x4b7190
// 004b8a7a  8b4614               mov eax, dword ptr [esi + 0x14]
// 004b8a7d  50                   push eax
// 004b8a7e  e8afff2500           call 0x718a32
// 004b8a83  8b0e                 mov ecx, dword ptr [esi]
// 004b8a85  51                   push ecx
// 004b8a86  c7461400000000       mov dword ptr [esi + 0x14], 0
// 004b8a8d  e8a0ff2500           call 0x718a32
// 004b8a92  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004b8a96  83c408               add esp, 8
// 004b8a99  5e                   pop esi
// 004b8a9a  64890d00000000       mov dword ptr fs:[0], ecx
// 004b8aa1  83c410               add esp, 0x10
// 004b8aa4  c3                   ret 
// standard library list<string> (function ??1?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
