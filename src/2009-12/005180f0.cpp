// from server: 100% by auto
// roc 2009-12 005180f0  unit: RBX::VInstance::?$NonFactoryProduct  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005180f0
//
// 005180f0  6aff                 push -1
// 005180f2  68d8c59300           push 0x93c5d8
// 005180f7  64a100000000         mov eax, dword ptr fs:[0]
// 005180fd  50                   push eax
// 005180fe  64892500000000       mov dword ptr fs:[0], esp
// 00518105  51                   push ecx
// 00518106  56                   push esi
// 00518107  8bf1                 mov esi, ecx
// 00518109  89742404             mov dword ptr [esp + 4], esi
// 0051810d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00518115  e836e4ffff           call 0x516550
// 0051811a  8b4614               mov eax, dword ptr [esi + 0x14]
// 0051811d  50                   push eax
// 0051811e  e837b72d00           call 0x7f385a
// 00518123  8b0e                 mov ecx, dword ptr [esi]
// 00518125  51                   push ecx
// 00518126  c7461400000000       mov dword ptr [esi + 0x14], 0
// 0051812d  e828b72d00           call 0x7f385a
// 00518132  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00518136  83c408               add esp, 8
// 00518139  5e                   pop esi
// 0051813a  64890d00000000       mov dword ptr fs:[0], ecx
// 00518141  83c410               add esp, 0x10
// 00518144  c3                   ret 
// standard library list<string> (function ??1?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
