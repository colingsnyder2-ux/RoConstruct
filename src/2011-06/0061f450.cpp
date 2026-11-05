// from server: 100% by auto
// roc 2011-06 0061f450  unit: RBX::VInstance::$$A6AXV?$shared_ptr::?$signal::Vslot::?$callable  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0061f450
//
// 0061f450  6aff                 push -1
// 0061f452  6868a39d00           push 0x9da368
// 0061f457  64a100000000         mov eax, dword ptr fs:[0]
// 0061f45d  50                   push eax
// 0061f45e  64892500000000       mov dword ptr fs:[0], esp
// 0061f465  51                   push ecx
// 0061f466  56                   push esi
// 0061f467  8bf1                 mov esi, ecx
// 0061f469  89742404             mov dword ptr [esp + 4], esi
// 0061f46d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0061f475  e8a6e7ffff           call 0x61dc20
// 0061f47a  8b06                 mov eax, dword ptr [esi]
// 0061f47c  50                   push eax
// 0061f47d  e8d6ab1e00           call 0x80a058
// 0061f482  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0061f486  83c404               add esp, 4
// 0061f489  5e                   pop esi
// 0061f48a  64890d00000000       mov dword ptr fs:[0], ecx
// 0061f491  83c410               add esp, 0x10
// 0061f494  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
