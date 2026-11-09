// from server: 100% by auto
// roc 2010-06 0062cbb0  unit: RBX::VInstance::?$NonFactoryProduct  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0062cbb0
//
// 0062cbb0  6aff                 push -1
// 0062cbb2  6858a29900           push 0x99a258
// 0062cbb7  64a100000000         mov eax, dword ptr fs:[0]
// 0062cbbd  50                   push eax
// 0062cbbe  64892500000000       mov dword ptr fs:[0], esp
// 0062cbc5  51                   push ecx
// 0062cbc6  56                   push esi
// 0062cbc7  8bf1                 mov esi, ecx
// 0062cbc9  89742404             mov dword ptr [esp + 4], esi
// 0062cbcd  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0062cbd5  e886fcffff           call 0x62c860
// 0062cbda  8b4614               mov eax, dword ptr [esi + 0x14]
// 0062cbdd  50                   push eax
// 0062cbde  e8b7ad1700           call 0x7a799a
// 0062cbe3  8b0e                 mov ecx, dword ptr [esi]
// 0062cbe5  51                   push ecx
// 0062cbe6  c7461400000000       mov dword ptr [esi + 0x14], 0
// 0062cbed  e8a8ad1700           call 0x7a799a
// 0062cbf2  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0062cbf6  83c408               add esp, 8
// 0062cbf9  5e                   pop esi
// 0062cbfa  64890d00000000       mov dword ptr fs:[0], ecx
// 0062cc01  83c410               add esp, 0x10
// 0062cc04  c3                   ret 
// standard library list<string> (function ??1?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
