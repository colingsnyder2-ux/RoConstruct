// from server: 100% by auto
// roc 2011-06 0066b110  unit: RBX::Profiling::Profiler  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0066b110
//
// 0066b110  8b442404             mov eax, dword ptr [esp + 4]
// 0066b114  56                   push esi
// 0066b115  50                   push eax
// 0066b116  8bf1                 mov esi, ecx
// 0066b118  e893ffffff           call 0x66b0b0
// 0066b11d  c706c4c7a900         mov dword ptr [esi], 0xa9c7c4
// 0066b123  8bc6                 mov eax, esi
// 0066b125  5e                   pop esi
// 0066b126  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
