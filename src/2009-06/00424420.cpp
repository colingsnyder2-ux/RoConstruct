// from server: 100% by auto
// roc 2009-06 00424420  unit: MainLogManager  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00424420
//
// 00424420  53                   push ebx
// 00424421  55                   push ebp
// 00424422  56                   push esi
// 00424423  8b742414             mov esi, dword ptr [esp + 0x14]
// 00424427  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0042442b  57                   push edi
// 0042442c  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00424430  8bce                 mov ecx, esi
// 00424432  2bcf                 sub ecx, edi
// 00424434  b893244992           mov eax, 0x92492493
// 00424439  f7e9                 imul ecx
// 0042443b  03d1                 add edx, ecx
// 0042443d  c1fa04               sar edx, 4
// 00424440  8bc2                 mov eax, edx
// 00424442  c1e81f               shr eax, 0x1f
// 00424445  03c2                 add eax, edx
// 00424447  8d0cc500000000       lea ecx, [eax*8]
// 0042444e  2bc8                 sub ecx, eax
// 00424450  03c9                 add ecx, ecx
// 00424452  03c9                 add ecx, ecx
// 00424454  8bdd                 mov ebx, ebp
// 00424456  2bd9                 sub ebx, ecx
// 00424458  3bfe                 cmp edi, esi
// 0042445a  7415                 je 0x424471
// 0042445c  2bee                 sub ebp, esi
// 0042445e  8bff                 mov edi, edi
// 00424460  83ee1c               sub esi, 0x1c
// 00424463  56                   push esi
// 00424464  8d0c2e               lea ecx, [esi + ebp]
// 00424467  ff154ce48900         call dword ptr [0x89e44c]
// 0042446d  3bf7                 cmp esi, edi
// 0042446f  75ef                 jne 0x424460
// 00424471  5f                   pop edi
// 00424472  5e                   pop esi
// 00424473  5d                   pop ebp
// 00424474  8bc3                 mov eax, ebx
// 00424476  5b                   pop ebx
// 00424477  c3                   ret 
// standard library vector<string> (function ??$_Move_backward_opt@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@@std@@YAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@PAV10@00Urandom_access_iterator_tag@0@U_Swap_move_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
