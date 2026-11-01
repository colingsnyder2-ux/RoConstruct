// from server: 100% by auto
// roc 2009-12 004442c0  unit: RBX::RbxG3D::Material  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004442c0
//
// 004442c0  53                   push ebx
// 004442c1  55                   push ebp
// 004442c2  56                   push esi
// 004442c3  8b742410             mov esi, dword ptr [esp + 0x10]
// 004442c7  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 004442cb  57                   push edi
// 004442cc  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 004442d0  8bcf                 mov ecx, edi
// 004442d2  2bce                 sub ecx, esi
// 004442d4  b893244992           mov eax, 0x92492493
// 004442d9  f7e9                 imul ecx
// 004442db  03d1                 add edx, ecx
// 004442dd  c1fa04               sar edx, 4
// 004442e0  8bc2                 mov eax, edx
// 004442e2  c1e81f               shr eax, 0x1f
// 004442e5  03c2                 add eax, edx
// 004442e7  8d0cc500000000       lea ecx, [eax*8]
// 004442ee  2bc8                 sub ecx, eax
// 004442f0  8d2c8b               lea ebp, [ebx + ecx*4]
// 004442f3  3bf7                 cmp esi, edi
// 004442f5  741a                 je 0x444311
// 004442f7  2bde                 sub ebx, esi
// 004442f9  8da42400000000       lea esp, [esp]
// 00444300  56                   push esi
// 00444301  8d0c33               lea ecx, [ebx + esi]
// 00444304  ff159cb69800         call dword ptr [0x98b69c]
// 0044430a  83c61c               add esi, 0x1c
// 0044430d  3bf7                 cmp esi, edi
// 0044430f  75ef                 jne 0x444300
// 00444311  5f                   pop edi
// 00444312  5e                   pop esi
// 00444313  8bc5                 mov eax, ebp
// 00444315  5d                   pop ebp
// 00444316  5b                   pop ebx
// 00444317  c3                   ret 
// standard library vector<string> (function ??$_Copy_opt@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@@std@@YAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@PAV10@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
