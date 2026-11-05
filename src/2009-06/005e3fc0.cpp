// from server: 100% by auto
// roc 2009-06 005e3fc0  unit: RBX::ThreadPool::UPoolData::XP6AXV?$shared_ptr::V?$bind_t::?$thread_data  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005e3fc0
//
// 005e3fc0  6aff                 push -1
// 005e3fc2  6878ef8600           push 0x86ef78
// 005e3fc7  64a100000000         mov eax, dword ptr fs:[0]
// 005e3fcd  50                   push eax
// 005e3fce  64892500000000       mov dword ptr fs:[0], esp
// 005e3fd5  51                   push ecx
// 005e3fd6  56                   push esi
// 005e3fd7  8bf1                 mov esi, ecx
// 005e3fd9  89742404             mov dword ptr [esp + 4], esi
// 005e3fdd  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005e3fe5  e836ab0100           call 0x5feb20
// 005e3fea  8b06                 mov eax, dword ptr [esi]
// 005e3fec  50                   push eax
// 005e3fed  e8404a1300           call 0x718a32
// 005e3ff2  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005e3ff6  83c404               add esp, 4
// 005e3ff9  5e                   pop esi
// 005e3ffa  64890d00000000       mov dword ptr fs:[0], ecx
// 005e4001  83c410               add esp, 0x10
// 005e4004  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
