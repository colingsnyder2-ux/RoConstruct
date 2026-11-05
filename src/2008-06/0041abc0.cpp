// from server: 100% by auto
// roc 2008-06 0041abc0  unit: std::D::DU?$char_traits::$$A6AXV?$basic_string::V?$function::?$holder  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0041abc0
//
// 0041abc0  6aff                 push -1
// 0041abc2  68e8727d00           push 0x7d72e8
// 0041abc7  64a100000000         mov eax, dword ptr fs:[0]
// 0041abcd  50                   push eax
// 0041abce  64892500000000       mov dword ptr fs:[0], esp
// 0041abd5  51                   push ecx
// 0041abd6  56                   push esi
// 0041abd7  8bf1                 mov esi, ecx
// 0041abd9  89742404             mov dword ptr [esp + 4], esi
// 0041abdd  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0041abe5  e816ffffff           call 0x41ab00
// 0041abea  8b4614               mov eax, dword ptr [esi + 0x14]
// 0041abed  50                   push eax
// 0041abee  e8875a2800           call 0x6a067a
// 0041abf3  8b0e                 mov ecx, dword ptr [esi]
// 0041abf5  51                   push ecx
// 0041abf6  c7461400000000       mov dword ptr [esi + 0x14], 0
// 0041abfd  e8785a2800           call 0x6a067a
// 0041ac02  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0041ac06  83c408               add esp, 8
// 0041ac09  5e                   pop esi
// 0041ac0a  64890d00000000       mov dword ptr fs:[0], ecx
// 0041ac11  83c410               add esp, 0x10
// 0041ac14  c3                   ret 
// standard library list<string> (function ??1?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
