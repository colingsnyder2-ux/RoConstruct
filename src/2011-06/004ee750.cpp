// from server: 100% by auto
// roc 2011-06 004ee750  unit: RBX::VInstance::?$GuidItem::VRegistry::?$sp_counted_impl_p  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004ee750
//
// 004ee750  6aff                 push -1
// 004ee752  6868a39d00           push 0x9da368
// 004ee757  64a100000000         mov eax, dword ptr fs:[0]
// 004ee75d  50                   push eax
// 004ee75e  64892500000000       mov dword ptr fs:[0], esp
// 004ee765  51                   push ecx
// 004ee766  56                   push esi
// 004ee767  8bf1                 mov esi, ecx
// 004ee769  89742404             mov dword ptr [esp + 4], esi
// 004ee76d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004ee775  e8061df9ff           call 0x480480
// 004ee77a  8b06                 mov eax, dword ptr [esi]
// 004ee77c  50                   push eax
// 004ee77d  e8d6b83100           call 0x80a058
// 004ee782  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004ee786  83c404               add esp, 4
// 004ee789  5e                   pop esi
// 004ee78a  64890d00000000       mov dword ptr fs:[0], ecx
// 004ee791  83c410               add esp, 0x10
// 004ee794  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
