// from server: 100% by auto
// roc 2007-08 00444fc0  unit: RBX::Reflection::Metadata::VItem::?$BoundPropGetSet  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00444fc0
//
// 00444fc0  53                   push ebx
// 00444fc1  55                   push ebp
// 00444fc2  56                   push esi
// 00444fc3  8b742410             mov esi, dword ptr [esp + 0x10]
// 00444fc7  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00444fcb  57                   push edi
// 00444fcc  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00444fd0  8bcf                 mov ecx, edi
// 00444fd2  2bce                 sub ecx, esi
// 00444fd4  b893244992           mov eax, 0x92492493
// 00444fd9  f7e9                 imul ecx
// 00444fdb  03d1                 add edx, ecx
// 00444fdd  c1fa04               sar edx, 4
// 00444fe0  8bc2                 mov eax, edx
// 00444fe2  c1e81f               shr eax, 0x1f
// 00444fe5  03c2                 add eax, edx
// 00444fe7  8d0cc500000000       lea ecx, [eax*8]
// 00444fee  2bc8                 sub ecx, eax
// 00444ff0  3bf7                 cmp esi, edi
// 00444ff2  8d2c8b               lea ebp, [ebx + ecx*4]
// 00444ff5  741a                 je 0x445011
// 00444ff7  2bde                 sub ebx, esi
// 00444ff9  8da42400000000       lea esp, [esp]
// 00445000  56                   push esi
// 00445001  8d0c33               lea ecx, [ebx + esi]
// 00445004  ff1590e67700         call dword ptr [0x77e690]
// 0044500a  83c61c               add esi, 0x1c
// 0044500d  3bf7                 cmp esi, edi
// 0044500f  75ef                 jne 0x445000
// 00445011  5f                   pop edi
// 00445012  5e                   pop esi
// 00445013  8bc5                 mov eax, ebp
// 00445015  5d                   pop ebp
// 00445016  5b                   pop ebx
// 00445017  c3                   ret 
// standard library vector<string> (function ??$_Copy_opt@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@@std@@YAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@PAV10@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
