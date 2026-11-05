// from server: 100% by auto
// roc 2010-06 00462a60  unit: RBX::VInstance::?$NonFactoryProduct  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00462a60
//
// 00462a60  6aff                 push -1
// 00462a62  6858a29900           push 0x99a258
// 00462a67  64a100000000         mov eax, dword ptr fs:[0]
// 00462a6d  50                   push eax
// 00462a6e  64892500000000       mov dword ptr fs:[0], esp
// 00462a75  51                   push ecx
// 00462a76  56                   push esi
// 00462a77  8bf1                 mov esi, ecx
// 00462a79  89742404             mov dword ptr [esp + 4], esi
// 00462a7d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00462a85  e896fdffff           call 0x462820
// 00462a8a  8b06                 mov eax, dword ptr [esi]
// 00462a8c  50                   push eax
// 00462a8d  e8084f3400           call 0x7a799a
// 00462a92  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00462a96  83c404               add esp, 4
// 00462a99  5e                   pop esi
// 00462a9a  64890d00000000       mov dword ptr fs:[0], ecx
// 00462aa1  83c410               add esp, 0x10
// 00462aa4  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
