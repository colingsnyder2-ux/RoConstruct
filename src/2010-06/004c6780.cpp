// from server: 100% by auto
// roc 2010-06 004c6780  unit: RBX::VInstance::?$NonFactoryProduct  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004c6780
//
// 004c6780  6aff                 push -1
// 004c6782  6858a29900           push 0x99a258
// 004c6787  64a100000000         mov eax, dword ptr fs:[0]
// 004c678d  50                   push eax
// 004c678e  64892500000000       mov dword ptr fs:[0], esp
// 004c6795  51                   push ecx
// 004c6796  56                   push esi
// 004c6797  8bf1                 mov esi, ecx
// 004c6799  89742404             mov dword ptr [esp + 4], esi
// 004c679d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004c67a5  e866e7ffff           call 0x4c4f10
// 004c67aa  8b4614               mov eax, dword ptr [esi + 0x14]
// 004c67ad  50                   push eax
// 004c67ae  e8e7112e00           call 0x7a799a
// 004c67b3  8b0e                 mov ecx, dword ptr [esi]
// 004c67b5  51                   push ecx
// 004c67b6  c7461400000000       mov dword ptr [esi + 0x14], 0
// 004c67bd  e8d8112e00           call 0x7a799a
// 004c67c2  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004c67c6  83c408               add esp, 8
// 004c67c9  5e                   pop esi
// 004c67ca  64890d00000000       mov dword ptr fs:[0], ecx
// 004c67d1  83c410               add esp, 0x10
// 004c67d4  c3                   ret 
// standard library list<string> (function ??1?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
