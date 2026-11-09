// from server: 100% by auto
// roc 2009-12 0041bbb0  unit: RBX::VInstance::$$A6AXV?$shared_ptr::?$signal::slot  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0041bbb0
//
// 0041bbb0  6aff                 push -1
// 0041bbb2  68d8c59300           push 0x93c5d8
// 0041bbb7  64a100000000         mov eax, dword ptr fs:[0]
// 0041bbbd  50                   push eax
// 0041bbbe  64892500000000       mov dword ptr fs:[0], esp
// 0041bbc5  51                   push ecx
// 0041bbc6  56                   push esi
// 0041bbc7  8bf1                 mov esi, ecx
// 0041bbc9  89742404             mov dword ptr [esp + 4], esi
// 0041bbcd  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0041bbd5  e8e6fbffff           call 0x41b7c0
// 0041bbda  8b06                 mov eax, dword ptr [esi]
// 0041bbdc  50                   push eax
// 0041bbdd  e8787c3d00           call 0x7f385a
// 0041bbe2  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0041bbe6  83c404               add esp, 4
// 0041bbe9  5e                   pop esi
// 0041bbea  64890d00000000       mov dword ptr fs:[0], ecx
// 0041bbf1  83c410               add esp, 0x10
// 0041bbf4  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
