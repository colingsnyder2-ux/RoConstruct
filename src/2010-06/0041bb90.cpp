// from server: 100% by auto
// roc 2010-06 0041bb90  unit: RBX::VInstance::$$A6AXV?$shared_ptr::?$signal::slot  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0041bb90
//
// 0041bb90  6aff                 push -1
// 0041bb92  6858a29900           push 0x99a258
// 0041bb97  64a100000000         mov eax, dword ptr fs:[0]
// 0041bb9d  50                   push eax
// 0041bb9e  64892500000000       mov dword ptr fs:[0], esp
// 0041bba5  51                   push ecx
// 0041bba6  56                   push esi
// 0041bba7  8bf1                 mov esi, ecx
// 0041bba9  89742404             mov dword ptr [esp + 4], esi
// 0041bbad  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0041bbb5  e8e6fbffff           call 0x41b7a0
// 0041bbba  8b06                 mov eax, dword ptr [esi]
// 0041bbbc  50                   push eax
// 0041bbbd  e8d8bd3800           call 0x7a799a
// 0041bbc2  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0041bbc6  83c404               add esp, 4
// 0041bbc9  5e                   pop esi
// 0041bbca  64890d00000000       mov dword ptr fs:[0], ecx
// 0041bbd1  83c410               add esp, 0x10
// 0041bbd4  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
