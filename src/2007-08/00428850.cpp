// from server: 100% by auto
// roc 2007-08 00428850  unit: COleException  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00428850
//
// 00428850  53                   push ebx
// 00428851  55                   push ebp
// 00428852  56                   push esi
// 00428853  8b742414             mov esi, dword ptr [esp + 0x14]
// 00428857  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0042885b  57                   push edi
// 0042885c  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00428860  8bce                 mov ecx, esi
// 00428862  2bcf                 sub ecx, edi
// 00428864  b893244992           mov eax, 0x92492493
// 00428869  f7e9                 imul ecx
// 0042886b  03d1                 add edx, ecx
// 0042886d  c1fa04               sar edx, 4
// 00428870  8bc2                 mov eax, edx
// 00428872  c1e81f               shr eax, 0x1f
// 00428875  03c2                 add eax, edx
// 00428877  8d0cc500000000       lea ecx, [eax*8]
// 0042887e  2bc8                 sub ecx, eax
// 00428880  03c9                 add ecx, ecx
// 00428882  03c9                 add ecx, ecx
// 00428884  8bdd                 mov ebx, ebp
// 00428886  2bd9                 sub ebx, ecx
// 00428888  3bfe                 cmp edi, esi
// 0042888a  7415                 je 0x4288a1
// 0042888c  2bee                 sub ebp, esi
// 0042888e  8bff                 mov edi, edi
// 00428890  83ee1c               sub esi, 0x1c
// 00428893  56                   push esi
// 00428894  8d0c2e               lea ecx, [esi + ebp]
// 00428897  ff1548e67700         call dword ptr [0x77e648]
// 0042889d  3bf7                 cmp esi, edi
// 0042889f  75ef                 jne 0x428890
// 004288a1  5f                   pop edi
// 004288a2  5e                   pop esi
// 004288a3  5d                   pop ebp
// 004288a4  8bc3                 mov eax, ebx
// 004288a6  5b                   pop ebx
// 004288a7  c3                   ret 
// standard library vector<string> (function ??$_Move_backward_opt@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@@std@@YAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@PAV10@00Urandom_access_iterator_tag@0@U_Swap_move_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
