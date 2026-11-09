// from server: 100% by auto
// roc 2010-06 0065c3f0  unit: RBX::VInstance::?$NonFactoryProduct  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0065c3f0
//
// 0065c3f0  6aff                 push -1
// 0065c3f2  6858a29900           push 0x99a258
// 0065c3f7  64a100000000         mov eax, dword ptr fs:[0]
// 0065c3fd  50                   push eax
// 0065c3fe  64892500000000       mov dword ptr fs:[0], esp
// 0065c405  51                   push ecx
// 0065c406  56                   push esi
// 0065c407  8bf1                 mov esi, ecx
// 0065c409  89742404             mov dword ptr [esp + 4], esi
// 0065c40d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0065c415  e8e6f9ffff           call 0x65be00
// 0065c41a  8b4614               mov eax, dword ptr [esi + 0x14]
// 0065c41d  50                   push eax
// 0065c41e  e877b51400           call 0x7a799a
// 0065c423  8b0e                 mov ecx, dword ptr [esi]
// 0065c425  51                   push ecx
// 0065c426  c7461400000000       mov dword ptr [esi + 0x14], 0
// 0065c42d  e868b51400           call 0x7a799a
// 0065c432  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0065c436  83c408               add esp, 8
// 0065c439  5e                   pop esi
// 0065c43a  64890d00000000       mov dword ptr fs:[0], ecx
// 0065c441  83c410               add esp, 0x10
// 0065c444  c3                   ret 
// standard library list<string> (function ??1?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
