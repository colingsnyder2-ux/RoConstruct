// from server: 100% by auto
// roc 2010-06 009619e0  unit: RBX::SceneUpdater  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009619e0
//
// 009619e0  6aff                 push -1
// 009619e2  6858a29900           push 0x99a258
// 009619e7  64a100000000         mov eax, dword ptr fs:[0]
// 009619ed  50                   push eax
// 009619ee  64892500000000       mov dword ptr fs:[0], esp
// 009619f5  51                   push ecx
// 009619f6  56                   push esi
// 009619f7  8bf1                 mov esi, ecx
// 009619f9  89742404             mov dword ptr [esp + 4], esi
// 009619fd  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00961a05  e8a6f8ffff           call 0x9612b0
// 00961a0a  8b4614               mov eax, dword ptr [esi + 0x14]
// 00961a0d  50                   push eax
// 00961a0e  e8875fe4ff           call 0x7a799a
// 00961a13  8b0e                 mov ecx, dword ptr [esi]
// 00961a15  51                   push ecx
// 00961a16  c7461400000000       mov dword ptr [esi + 0x14], 0
// 00961a1d  e8785fe4ff           call 0x7a799a
// 00961a22  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00961a26  83c408               add esp, 8
// 00961a29  5e                   pop esi
// 00961a2a  64890d00000000       mov dword ptr fs:[0], ecx
// 00961a31  83c410               add esp, 0x10
// 00961a34  c3                   ret 
// standard library list<string> (function ??1?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
