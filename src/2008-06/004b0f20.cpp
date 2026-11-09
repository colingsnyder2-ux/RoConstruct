// from server: 100% by auto
// roc 2008-06 004b0f20  unit: RBX::Network::Replicator::NewInstanceItem  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004b0f20
//
// 004b0f20  6aff                 push -1
// 004b0f22  68e8727d00           push 0x7d72e8
// 004b0f27  64a100000000         mov eax, dword ptr fs:[0]
// 004b0f2d  50                   push eax
// 004b0f2e  64892500000000       mov dword ptr fs:[0], esp
// 004b0f35  51                   push ecx
// 004b0f36  56                   push esi
// 004b0f37  8bf1                 mov esi, ecx
// 004b0f39  89742404             mov dword ptr [esp + 4], esi
// 004b0f3d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004b0f45  e866e2ffff           call 0x4af1b0
// 004b0f4a  8b06                 mov eax, dword ptr [esi]
// 004b0f4c  50                   push eax
// 004b0f4d  e828f71e00           call 0x6a067a
// 004b0f52  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004b0f56  83c404               add esp, 4
// 004b0f59  5e                   pop esi
// 004b0f5a  64890d00000000       mov dword ptr fs:[0], ecx
// 004b0f61  83c410               add esp, 0x10
// 004b0f64  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
