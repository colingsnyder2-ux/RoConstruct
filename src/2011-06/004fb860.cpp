// from server: 100% by auto
// roc 2011-06 004fb860  unit: RBX::Network::Replicator  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004fb860
//
// 004fb860  6aff                 push -1
// 004fb862  6868a39d00           push 0x9da368
// 004fb867  64a100000000         mov eax, dword ptr fs:[0]
// 004fb86d  50                   push eax
// 004fb86e  64892500000000       mov dword ptr fs:[0], esp
// 004fb875  51                   push ecx
// 004fb876  56                   push esi
// 004fb877  8bf1                 mov esi, ecx
// 004fb879  89742404             mov dword ptr [esp + 4], esi
// 004fb87d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004fb885  e8c6edffff           call 0x4fa650
// 004fb88a  8b06                 mov eax, dword ptr [esi]
// 004fb88c  50                   push eax
// 004fb88d  e8c6e73000           call 0x80a058
// 004fb892  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004fb896  83c404               add esp, 4
// 004fb899  5e                   pop esi
// 004fb89a  64890d00000000       mov dword ptr fs:[0], ecx
// 004fb8a1  83c410               add esp, 0x10
// 004fb8a4  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
