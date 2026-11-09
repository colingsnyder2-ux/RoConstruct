// from server: 100% by auto
// roc 2011-06 00441500  unit: COutputView  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00441500
//
// 00441500  6aff                 push -1
// 00441502  6868a39d00           push 0x9da368
// 00441507  64a100000000         mov eax, dword ptr fs:[0]
// 0044150d  50                   push eax
// 0044150e  64892500000000       mov dword ptr fs:[0], esp
// 00441515  51                   push ecx
// 00441516  56                   push esi
// 00441517  8bf1                 mov esi, ecx
// 00441519  89742404             mov dword ptr [esp + 4], esi
// 0044151d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00441525  e8f6faffff           call 0x441020
// 0044152a  8b06                 mov eax, dword ptr [esi]
// 0044152c  50                   push eax
// 0044152d  e8268b3c00           call 0x80a058
// 00441532  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00441536  83c404               add esp, 4
// 00441539  5e                   pop esi
// 0044153a  64890d00000000       mov dword ptr fs:[0], ecx
// 00441541  83c410               add esp, 0x10
// 00441544  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
