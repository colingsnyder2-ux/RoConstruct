// from server: 100% by auto
// roc 2009-06 004c8630  unit: RBX::VInstance::?$NonFactoryProduct  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004c8630
//
// 004c8630  6aff                 push -1
// 004c8632  6878ef8600           push 0x86ef78
// 004c8637  64a100000000         mov eax, dword ptr fs:[0]
// 004c863d  50                   push eax
// 004c863e  64892500000000       mov dword ptr fs:[0], esp
// 004c8645  51                   push ecx
// 004c8646  56                   push esi
// 004c8647  8bf1                 mov esi, ecx
// 004c8649  89742404             mov dword ptr [esp + 4], esi
// 004c864d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004c8655  e8f6efffff           call 0x4c7650
// 004c865a  8b4614               mov eax, dword ptr [esi + 0x14]
// 004c865d  50                   push eax
// 004c865e  e8cf032500           call 0x718a32
// 004c8663  8b0e                 mov ecx, dword ptr [esi]
// 004c8665  51                   push ecx
// 004c8666  c7461400000000       mov dword ptr [esi + 0x14], 0
// 004c866d  e8c0032500           call 0x718a32
// 004c8672  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004c8676  83c408               add esp, 8
// 004c8679  5e                   pop esi
// 004c867a  64890d00000000       mov dword ptr fs:[0], ecx
// 004c8681  83c410               add esp, 0x10
// 004c8684  c3                   ret 
// standard library list<string> (function ??1?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
