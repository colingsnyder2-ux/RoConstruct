// from server: 100% by auto
// roc 2010-06 0066beb0  unit: RBX::TimerService  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0066beb0
//
// 0066beb0  6aff                 push -1
// 0066beb2  6858a29900           push 0x99a258
// 0066beb7  64a100000000         mov eax, dword ptr fs:[0]
// 0066bebd  50                   push eax
// 0066bebe  64892500000000       mov dword ptr fs:[0], esp
// 0066bec5  51                   push ecx
// 0066bec6  56                   push esi
// 0066bec7  8bf1                 mov esi, ecx
// 0066bec9  89742404             mov dword ptr [esp + 4], esi
// 0066becd  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0066bed5  e8e6fcffff           call 0x66bbc0
// 0066beda  8b4614               mov eax, dword ptr [esi + 0x14]
// 0066bedd  50                   push eax
// 0066bede  e8b7ba1300           call 0x7a799a
// 0066bee3  8b0e                 mov ecx, dword ptr [esi]
// 0066bee5  51                   push ecx
// 0066bee6  c7461400000000       mov dword ptr [esi + 0x14], 0
// 0066beed  e8a8ba1300           call 0x7a799a
// 0066bef2  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0066bef6  83c408               add esp, 8
// 0066bef9  5e                   pop esi
// 0066befa  64890d00000000       mov dword ptr fs:[0], ecx
// 0066bf01  83c410               add esp, 0x10
// 0066bf04  c3                   ret 
// standard library list<string> (function ??1?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
