// from server: 100% by auto
// roc 2008-06 004b0a80  unit: RBX::Network::Replicator::NewInstanceItem  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004b0a80
//
// 004b0a80  6aff                 push -1
// 004b0a82  68e8727d00           push 0x7d72e8
// 004b0a87  64a100000000         mov eax, dword ptr fs:[0]
// 004b0a8d  50                   push eax
// 004b0a8e  64892500000000       mov dword ptr fs:[0], esp
// 004b0a95  51                   push ecx
// 004b0a96  56                   push esi
// 004b0a97  8bf1                 mov esi, ecx
// 004b0a99  89742404             mov dword ptr [esp + 4], esi
// 004b0a9d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004b0aa5  e8e6a8f7ff           call 0x42b390
// 004b0aaa  8b4614               mov eax, dword ptr [esi + 0x14]
// 004b0aad  50                   push eax
// 004b0aae  e8c7fb1e00           call 0x6a067a
// 004b0ab3  8b0e                 mov ecx, dword ptr [esi]
// 004b0ab5  51                   push ecx
// 004b0ab6  c7461400000000       mov dword ptr [esi + 0x14], 0
// 004b0abd  e8b8fb1e00           call 0x6a067a
// 004b0ac2  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004b0ac6  83c408               add esp, 8
// 004b0ac9  5e                   pop esi
// 004b0aca  64890d00000000       mov dword ptr fs:[0], ecx
// 004b0ad1  83c410               add esp, 0x10
// 004b0ad4  c3                   ret 
// standard library list<string> (function ??1?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
