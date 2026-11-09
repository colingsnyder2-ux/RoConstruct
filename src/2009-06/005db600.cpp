// from server: 100% by auto
// roc 2009-06 005db600  unit: RBX::VInstance::?$NonFactoryProduct  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005db600
//
// 005db600  6aff                 push -1
// 005db602  6878ef8600           push 0x86ef78
// 005db607  64a100000000         mov eax, dword ptr fs:[0]
// 005db60d  50                   push eax
// 005db60e  64892500000000       mov dword ptr fs:[0], esp
// 005db615  51                   push ecx
// 005db616  56                   push esi
// 005db617  8bf1                 mov esi, ecx
// 005db619  89742404             mov dword ptr [esp + 4], esi
// 005db61d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005db625  e896f9ffff           call 0x5dafc0
// 005db62a  8b4614               mov eax, dword ptr [esi + 0x14]
// 005db62d  50                   push eax
// 005db62e  e8ffd31300           call 0x718a32
// 005db633  8b0e                 mov ecx, dword ptr [esi]
// 005db635  51                   push ecx
// 005db636  c7461400000000       mov dword ptr [esi + 0x14], 0
// 005db63d  e8f0d31300           call 0x718a32
// 005db642  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005db646  83c408               add esp, 8
// 005db649  5e                   pop esi
// 005db64a  64890d00000000       mov dword ptr fs:[0], ecx
// 005db651  83c410               add esp, 0x10
// 005db654  c3                   ret 
// standard library list<string> (function ??1?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
