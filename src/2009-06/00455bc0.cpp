// from server: 100% by auto
// roc 2009-06 00455bc0  unit: RBX::VInstance::?$NonFactoryProduct  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00455bc0
//
// 00455bc0  6aff                 push -1
// 00455bc2  6878ef8600           push 0x86ef78
// 00455bc7  64a100000000         mov eax, dword ptr fs:[0]
// 00455bcd  50                   push eax
// 00455bce  64892500000000       mov dword ptr fs:[0], esp
// 00455bd5  51                   push ecx
// 00455bd6  56                   push esi
// 00455bd7  8bf1                 mov esi, ecx
// 00455bd9  89742404             mov dword ptr [esp + 4], esi
// 00455bdd  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00455be5  e896fdffff           call 0x455980
// 00455bea  8b06                 mov eax, dword ptr [esi]
// 00455bec  50                   push eax
// 00455bed  e8402e2c00           call 0x718a32
// 00455bf2  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00455bf6  83c404               add esp, 4
// 00455bf9  5e                   pop esi
// 00455bfa  64890d00000000       mov dword ptr fs:[0], ecx
// 00455c01  83c410               add esp, 0x10
// 00455c04  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
