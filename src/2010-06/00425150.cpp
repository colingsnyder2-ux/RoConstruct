// from server: 100% by auto
// roc 2010-06 00425150  unit: ThreadLogManager  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00425150
//
// 00425150  53                   push ebx
// 00425151  55                   push ebp
// 00425152  56                   push esi
// 00425153  8b742414             mov esi, dword ptr [esp + 0x14]
// 00425157  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0042515b  57                   push edi
// 0042515c  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00425160  8bce                 mov ecx, esi
// 00425162  2bcf                 sub ecx, edi
// 00425164  b893244992           mov eax, 0x92492493
// 00425169  f7e9                 imul ecx
// 0042516b  03d1                 add edx, ecx
// 0042516d  c1fa04               sar edx, 4
// 00425170  8bc2                 mov eax, edx
// 00425172  c1e81f               shr eax, 0x1f
// 00425175  03c2                 add eax, edx
// 00425177  8d0cc500000000       lea ecx, [eax*8]
// 0042517e  2bc8                 sub ecx, eax
// 00425180  03c9                 add ecx, ecx
// 00425182  03c9                 add ecx, ecx
// 00425184  8bdd                 mov ebx, ebp
// 00425186  2bd9                 sub ebx, ecx
// 00425188  3bfe                 cmp edi, esi
// 0042518a  7415                 je 0x4251a1
// 0042518c  2bee                 sub ebp, esi
// 0042518e  8bff                 mov edi, edi
// 00425190  83ee1c               sub esi, 0x1c
// 00425193  56                   push esi
// 00425194  8d0c2e               lea ecx, [esi + ebp]
// 00425197  ff1580a49e00         call dword ptr [0x9ea480]
// 0042519d  3bf7                 cmp esi, edi
// 0042519f  75ef                 jne 0x425190
// 004251a1  5f                   pop edi
// 004251a2  5e                   pop esi
// 004251a3  5d                   pop ebp
// 004251a4  8bc3                 mov eax, ebx
// 004251a6  5b                   pop ebx
// 004251a7  c3                   ret 
// standard library vector<string> (function ??$_Move_backward_opt@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@@std@@YAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@PAV10@00Urandom_access_iterator_tag@0@U_Swap_move_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
