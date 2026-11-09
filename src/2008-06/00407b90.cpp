// from server: 100% by auto
// roc 2008-06 00407b90  unit: VCApp::?$CComObject  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00407b90
//
// 00407b90  6aff                 push -1
// 00407b92  68e8727d00           push 0x7d72e8
// 00407b97  64a100000000         mov eax, dword ptr fs:[0]
// 00407b9d  50                   push eax
// 00407b9e  64892500000000       mov dword ptr fs:[0], esp
// 00407ba5  51                   push ecx
// 00407ba6  56                   push esi
// 00407ba7  8bf1                 mov esi, ecx
// 00407ba9  89742404             mov dword ptr [esp + 4], esi
// 00407bad  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00407bb5  e816fcffff           call 0x4077d0
// 00407bba  8b06                 mov eax, dword ptr [esi]
// 00407bbc  50                   push eax
// 00407bbd  e8b88a2900           call 0x6a067a
// 00407bc2  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00407bc6  83c404               add esp, 4
// 00407bc9  5e                   pop esi
// 00407bca  64890d00000000       mov dword ptr fs:[0], ecx
// 00407bd1  83c410               add esp, 0x10
// 00407bd4  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
