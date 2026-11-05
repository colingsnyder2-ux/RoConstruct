// from server: 100% by auto
// roc 2008-06 00562bd0  unit: std::D::DU?$char_traits::?$basic_ifstream  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00562bd0
//
// 00562bd0  6aff                 push -1
// 00562bd2  68e8727d00           push 0x7d72e8
// 00562bd7  64a100000000         mov eax, dword ptr fs:[0]
// 00562bdd  50                   push eax
// 00562bde  64892500000000       mov dword ptr fs:[0], esp
// 00562be5  51                   push ecx
// 00562be6  56                   push esi
// 00562be7  8bf1                 mov esi, ecx
// 00562be9  89742404             mov dword ptr [esp + 4], esi
// 00562bed  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00562bf5  e856ecffff           call 0x561850
// 00562bfa  8b4614               mov eax, dword ptr [esi + 0x14]
// 00562bfd  50                   push eax
// 00562bfe  e877da1300           call 0x6a067a
// 00562c03  8b0e                 mov ecx, dword ptr [esi]
// 00562c05  51                   push ecx
// 00562c06  c7461400000000       mov dword ptr [esi + 0x14], 0
// 00562c0d  e868da1300           call 0x6a067a
// 00562c12  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00562c16  83c408               add esp, 8
// 00562c19  5e                   pop esi
// 00562c1a  64890d00000000       mov dword ptr fs:[0], ecx
// 00562c21  83c410               add esp, 0x10
// 00562c24  c3                   ret 
// standard library list<string> (function ??1?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
