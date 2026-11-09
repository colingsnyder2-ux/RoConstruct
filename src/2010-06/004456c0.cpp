// from server: 100% by auto
// roc 2010-06 004456c0  unit: RBX::Reflection::Metadata::VItem::?$BoundPropGetSet  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004456c0
//
// 004456c0  53                   push ebx
// 004456c1  55                   push ebp
// 004456c2  56                   push esi
// 004456c3  8b742410             mov esi, dword ptr [esp + 0x10]
// 004456c7  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 004456cb  57                   push edi
// 004456cc  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 004456d0  8bcf                 mov ecx, edi
// 004456d2  2bce                 sub ecx, esi
// 004456d4  b893244992           mov eax, 0x92492493
// 004456d9  f7e9                 imul ecx
// 004456db  03d1                 add edx, ecx
// 004456dd  c1fa04               sar edx, 4
// 004456e0  8bc2                 mov eax, edx
// 004456e2  c1e81f               shr eax, 0x1f
// 004456e5  03c2                 add eax, edx
// 004456e7  8d0cc500000000       lea ecx, [eax*8]
// 004456ee  2bc8                 sub ecx, eax
// 004456f0  8d2c8b               lea ebp, [ebx + ecx*4]
// 004456f3  3bf7                 cmp esi, edi
// 004456f5  741a                 je 0x445711
// 004456f7  2bde                 sub ebx, esi
// 004456f9  8da42400000000       lea esp, [esp]
// 00445700  56                   push esi
// 00445701  8d0c33               lea ecx, [ebx + esi]
// 00445704  ff1568a49e00         call dword ptr [0x9ea468]
// 0044570a  83c61c               add esi, 0x1c
// 0044570d  3bf7                 cmp esi, edi
// 0044570f  75ef                 jne 0x445700
// 00445711  5f                   pop edi
// 00445712  5e                   pop esi
// 00445713  8bc5                 mov eax, ebp
// 00445715  5d                   pop ebp
// 00445716  5b                   pop ebx
// 00445717  c3                   ret 
// standard library vector<string> (function ??$_Copy_opt@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@@std@@YAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@PAV10@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
