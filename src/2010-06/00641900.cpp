// from server: 100% by auto
// roc 2010-06 00641900  unit: RBX::VInstance::?$NonFactoryProduct  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00641900
//
// 00641900  6aff                 push -1
// 00641902  6858a29900           push 0x99a258
// 00641907  64a100000000         mov eax, dword ptr fs:[0]
// 0064190d  50                   push eax
// 0064190e  64892500000000       mov dword ptr fs:[0], esp
// 00641915  51                   push ecx
// 00641916  56                   push esi
// 00641917  8bf1                 mov esi, ecx
// 00641919  89742404             mov dword ptr [esp + 4], esi
// 0064191d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00641925  e8e6f7ffff           call 0x641110
// 0064192a  8b4614               mov eax, dword ptr [esi + 0x14]
// 0064192d  50                   push eax
// 0064192e  e867601600           call 0x7a799a
// 00641933  8b0e                 mov ecx, dword ptr [esi]
// 00641935  51                   push ecx
// 00641936  c7461400000000       mov dword ptr [esi + 0x14], 0
// 0064193d  e858601600           call 0x7a799a
// 00641942  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00641946  83c408               add esp, 8
// 00641949  5e                   pop esi
// 0064194a  64890d00000000       mov dword ptr fs:[0], ecx
// 00641951  83c410               add esp, 0x10
// 00641954  c3                   ret 
// standard library list<string> (function ??1?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
