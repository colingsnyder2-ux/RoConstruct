// from server: 100% by auto
// roc 2009-06 004c7ed0  unit: RBX::VInstance::?$NonFactoryProduct  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004c7ed0
//
// 004c7ed0  6aff                 push -1
// 004c7ed2  6878ef8600           push 0x86ef78
// 004c7ed7  64a100000000         mov eax, dword ptr fs:[0]
// 004c7edd  50                   push eax
// 004c7ede  64892500000000       mov dword ptr fs:[0], esp
// 004c7ee5  51                   push ecx
// 004c7ee6  56                   push esi
// 004c7ee7  8bf1                 mov esi, ecx
// 004c7ee9  89742404             mov dword ptr [esp + 4], esi
// 004c7eed  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004c7ef5  e876ebffff           call 0x4c6a70
// 004c7efa  8b4614               mov eax, dword ptr [esi + 0x14]
// 004c7efd  50                   push eax
// 004c7efe  e82f0b2500           call 0x718a32
// 004c7f03  8b0e                 mov ecx, dword ptr [esi]
// 004c7f05  51                   push ecx
// 004c7f06  c7461400000000       mov dword ptr [esi + 0x14], 0
// 004c7f0d  e8200b2500           call 0x718a32
// 004c7f12  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004c7f16  83c408               add esp, 8
// 004c7f19  5e                   pop esi
// 004c7f1a  64890d00000000       mov dword ptr fs:[0], ecx
// 004c7f21  83c410               add esp, 0x10
// 004c7f24  c3                   ret 
// standard library list<string> (function ??1?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
