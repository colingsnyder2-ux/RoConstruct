// from server: 100% by auto
// roc 2010-06 006bcdc0  unit: RBX::BillboardGui  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006bcdc0
//
// 006bcdc0  6aff                 push -1
// 006bcdc2  6858a29900           push 0x99a258
// 006bcdc7  64a100000000         mov eax, dword ptr fs:[0]
// 006bcdcd  50                   push eax
// 006bcdce  64892500000000       mov dword ptr fs:[0], esp
// 006bcdd5  51                   push ecx
// 006bcdd6  56                   push esi
// 006bcdd7  8bf1                 mov esi, ecx
// 006bcdd9  89742404             mov dword ptr [esp + 4], esi
// 006bcddd  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006bcde5  e856eeffff           call 0x6bbc40
// 006bcdea  8b06                 mov eax, dword ptr [esi]
// 006bcdec  50                   push eax
// 006bcded  e8a8ab0e00           call 0x7a799a
// 006bcdf2  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006bcdf6  83c404               add esp, 4
// 006bcdf9  5e                   pop esi
// 006bcdfa  64890d00000000       mov dword ptr fs:[0], ecx
// 006bce01  83c410               add esp, 0x10
// 006bce04  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
