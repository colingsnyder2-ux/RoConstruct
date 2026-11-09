// from server: 100% by auto
// roc 2008-06 00445310  unit: 1RBX::Metadata::VReflection::?$FactoryProduct  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00445310
//
// 00445310  53                   push ebx
// 00445311  55                   push ebp
// 00445312  56                   push esi
// 00445313  8b742410             mov esi, dword ptr [esp + 0x10]
// 00445317  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0044531b  57                   push edi
// 0044531c  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00445320  8bcf                 mov ecx, edi
// 00445322  2bce                 sub ecx, esi
// 00445324  b893244992           mov eax, 0x92492493
// 00445329  f7e9                 imul ecx
// 0044532b  03d1                 add edx, ecx
// 0044532d  c1fa04               sar edx, 4
// 00445330  8bc2                 mov eax, edx
// 00445332  c1e81f               shr eax, 0x1f
// 00445335  03c2                 add eax, edx
// 00445337  8d0cc500000000       lea ecx, [eax*8]
// 0044533e  2bc8                 sub ecx, eax
// 00445340  8d2c8b               lea ebp, [ebx + ecx*4]
// 00445343  3bf7                 cmp esi, edi
// 00445345  741a                 je 0x445361
// 00445347  2bde                 sub ebx, esi
// 00445349  8da42400000000       lea esp, [esp]
// 00445350  56                   push esi
// 00445351  8d0c33               lea ecx, [ebx + esi]
// 00445354  ff150c248000         call dword ptr [0x80240c]
// 0044535a  83c61c               add esi, 0x1c
// 0044535d  3bf7                 cmp esi, edi
// 0044535f  75ef                 jne 0x445350
// 00445361  5f                   pop edi
// 00445362  5e                   pop esi
// 00445363  8bc5                 mov eax, ebp
// 00445365  5d                   pop ebp
// 00445366  5b                   pop ebx
// 00445367  c3                   ret 
// standard library vector<string> (function ??$_Copy_opt@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@@std@@YAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@PAV10@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
