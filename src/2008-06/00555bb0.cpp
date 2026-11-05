// from server: 100% by auto
// roc 2008-06 00555bb0  unit: RBX::Reflection::Z::$$A6AXMM::?$TSignalDesc::TSignalInstance  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00555bb0
//
// 00555bb0  6aff                 push -1
// 00555bb2  68e8727d00           push 0x7d72e8
// 00555bb7  64a100000000         mov eax, dword ptr fs:[0]
// 00555bbd  50                   push eax
// 00555bbe  64892500000000       mov dword ptr fs:[0], esp
// 00555bc5  51                   push ecx
// 00555bc6  56                   push esi
// 00555bc7  8bf1                 mov esi, ecx
// 00555bc9  89742404             mov dword ptr [esp + 4], esi
// 00555bcd  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00555bd5  e8663fecff           call 0x419b40
// 00555bda  8b06                 mov eax, dword ptr [esi]
// 00555bdc  50                   push eax
// 00555bdd  e898aa1400           call 0x6a067a
// 00555be2  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00555be6  83c404               add esp, 4
// 00555be9  5e                   pop esi
// 00555bea  64890d00000000       mov dword ptr fs:[0], ecx
// 00555bf1  83c410               add esp, 0x10
// 00555bf4  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
