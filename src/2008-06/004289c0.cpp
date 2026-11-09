// from server: 100% by auto
// roc 2008-06 004289c0  unit: MainLogManager  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004289c0
//
// 004289c0  53                   push ebx
// 004289c1  55                   push ebp
// 004289c2  56                   push esi
// 004289c3  8b742414             mov esi, dword ptr [esp + 0x14]
// 004289c7  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 004289cb  57                   push edi
// 004289cc  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 004289d0  8bce                 mov ecx, esi
// 004289d2  2bcf                 sub ecx, edi
// 004289d4  b893244992           mov eax, 0x92492493
// 004289d9  f7e9                 imul ecx
// 004289db  03d1                 add edx, ecx
// 004289dd  c1fa04               sar edx, 4
// 004289e0  8bc2                 mov eax, edx
// 004289e2  c1e81f               shr eax, 0x1f
// 004289e5  03c2                 add eax, edx
// 004289e7  8d0cc500000000       lea ecx, [eax*8]
// 004289ee  2bc8                 sub ecx, eax
// 004289f0  03c9                 add ecx, ecx
// 004289f2  03c9                 add ecx, ecx
// 004289f4  8bdd                 mov ebx, ebp
// 004289f6  2bd9                 sub ebx, ecx
// 004289f8  3bfe                 cmp edi, esi
// 004289fa  7415                 je 0x428a11
// 004289fc  2bee                 sub ebp, esi
// 004289fe  8bff                 mov edi, edi
// 00428a00  83ee1c               sub esi, 0x1c
// 00428a03  56                   push esi
// 00428a04  8d0c2e               lea ecx, [esi + ebp]
// 00428a07  ff15f0238000         call dword ptr [0x8023f0]
// 00428a0d  3bf7                 cmp esi, edi
// 00428a0f  75ef                 jne 0x428a00
// 00428a11  5f                   pop edi
// 00428a12  5e                   pop esi
// 00428a13  5d                   pop ebp
// 00428a14  8bc3                 mov eax, ebx
// 00428a16  5b                   pop ebx
// 00428a17  c3                   ret 
// standard library vector<string> (function ??$_Move_backward_opt@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@@std@@YAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@PAV10@00Urandom_access_iterator_tag@0@U_Swap_move_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
