// from server: 100% by auto
// roc 2009-12 00424d20  unit: ThreadLogManager  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00424d20
//
// 00424d20  53                   push ebx
// 00424d21  55                   push ebp
// 00424d22  56                   push esi
// 00424d23  8b742414             mov esi, dword ptr [esp + 0x14]
// 00424d27  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00424d2b  57                   push edi
// 00424d2c  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00424d30  8bce                 mov ecx, esi
// 00424d32  2bcf                 sub ecx, edi
// 00424d34  b893244992           mov eax, 0x92492493
// 00424d39  f7e9                 imul ecx
// 00424d3b  03d1                 add edx, ecx
// 00424d3d  c1fa04               sar edx, 4
// 00424d40  8bc2                 mov eax, edx
// 00424d42  c1e81f               shr eax, 0x1f
// 00424d45  03c2                 add eax, edx
// 00424d47  8d0cc500000000       lea ecx, [eax*8]
// 00424d4e  2bc8                 sub ecx, eax
// 00424d50  03c9                 add ecx, ecx
// 00424d52  03c9                 add ecx, ecx
// 00424d54  8bdd                 mov ebx, ebp
// 00424d56  2bd9                 sub ebx, ecx
// 00424d58  3bfe                 cmp edi, esi
// 00424d5a  7415                 je 0x424d71
// 00424d5c  2bee                 sub ebp, esi
// 00424d5e  8bff                 mov edi, edi
// 00424d60  83ee1c               sub esi, 0x1c
// 00424d63  56                   push esi
// 00424d64  8d0c2e               lea ecx, [esi + ebp]
// 00424d67  ff1584b69800         call dword ptr [0x98b684]
// 00424d6d  3bf7                 cmp esi, edi
// 00424d6f  75ef                 jne 0x424d60
// 00424d71  5f                   pop edi
// 00424d72  5e                   pop esi
// 00424d73  5d                   pop ebp
// 00424d74  8bc3                 mov eax, ebx
// 00424d76  5b                   pop ebx
// 00424d77  c3                   ret 
// standard library vector<string> (function ??$_Move_backward_opt@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@@std@@YAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@PAV10@00Urandom_access_iterator_tag@0@U_Swap_move_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
