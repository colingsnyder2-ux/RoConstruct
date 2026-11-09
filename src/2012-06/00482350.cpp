// from server: 100% by auto
// roc 2012-06 00482350  unit: CRobloxDoc  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00482350
//
// 00482350  6aff                 push -1
// 00482352  681890ad00           push 0xad9018
// 00482357  64a100000000         mov eax, dword ptr fs:[0]
// 0048235d  50                   push eax
// 0048235e  64892500000000       mov dword ptr fs:[0], esp
// 00482365  51                   push ecx
// 00482366  56                   push esi
// 00482367  8bf1                 mov esi, ecx
// 00482369  89742404             mov dword ptr [esp + 4], esi
// 0048236d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00482375  e896d9feff           call 0x46fd10
// 0048237a  8b06                 mov eax, dword ptr [esi]
// 0048237c  50                   push eax
// 0048237d  e892fd4f00           call 0x982114
// 00482382  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00482386  83c404               add esp, 4
// 00482389  5e                   pop esi
// 0048238a  64890d00000000       mov dword ptr fs:[0], ecx
// 00482391  83c410               add esp, 0x10
// 00482394  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
