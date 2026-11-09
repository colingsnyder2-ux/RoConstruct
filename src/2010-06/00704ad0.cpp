// from server: 100% by auto
// roc 2010-06 00704ad0  unit: RBX::VInstance::?$NonFactoryProduct  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00704ad0
//
// 00704ad0  6aff                 push -1
// 00704ad2  6858a29900           push 0x99a258
// 00704ad7  64a100000000         mov eax, dword ptr fs:[0]
// 00704add  50                   push eax
// 00704ade  64892500000000       mov dword ptr fs:[0], esp
// 00704ae5  51                   push ecx
// 00704ae6  56                   push esi
// 00704ae7  8bf1                 mov esi, ecx
// 00704ae9  89742404             mov dword ptr [esp + 4], esi
// 00704aed  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00704af5  e816fdffff           call 0x704810
// 00704afa  8b4614               mov eax, dword ptr [esi + 0x14]
// 00704afd  50                   push eax
// 00704afe  e8972e0a00           call 0x7a799a
// 00704b03  8b0e                 mov ecx, dword ptr [esi]
// 00704b05  51                   push ecx
// 00704b06  c7461400000000       mov dword ptr [esi + 0x14], 0
// 00704b0d  e8882e0a00           call 0x7a799a
// 00704b12  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00704b16  83c408               add esp, 8
// 00704b19  5e                   pop esi
// 00704b1a  64890d00000000       mov dword ptr fs:[0], ecx
// 00704b21  83c410               add esp, 0x10
// 00704b24  c3                   ret 
// standard library list<string> (function ??1?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
