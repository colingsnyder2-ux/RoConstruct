// from server: 100% by auto
// roc 2011-06 007b6f30  unit: RBX::SpatialFilter  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007b6f30
//
// 007b6f30  53                   push ebx
// 007b6f31  8b5c2408             mov ebx, dword ptr [esp + 8]
// 007b6f35  55                   push ebp
// 007b6f36  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 007b6f3a  3bdd                 cmp ebx, ebp
// 007b6f3c  7450                 je 0x7b6f8e
// 007b6f3e  56                   push esi
// 007b6f3f  8b742418             mov esi, dword ptr [esp + 0x18]
// 007b6f43  57                   push edi
// 007b6f44  8b03                 mov eax, dword ptr [ebx]
// 007b6f46  8906                 mov dword ptr [esi], eax
// 007b6f48  8b7b04               mov edi, dword ptr [ebx + 4]
// 007b6f4b  3b7e04               cmp edi, dword ptr [esi + 4]
// 007b6f4e  742d                 je 0x7b6f7d
// 007b6f50  85ff                 test edi, edi
// 007b6f52  740c                 je 0x7b6f60
// 007b6f54  8d4f08               lea ecx, [edi + 8]
// 007b6f57  ba01000000           mov edx, 1
// 007b6f5c  f00fc111             lock xadd dword ptr [ecx], edx
// 007b6f60  8b4e04               mov ecx, dword ptr [esi + 4]
// 007b6f63  85c9                 test ecx, ecx
// 007b6f65  7413                 je 0x7b6f7a
// 007b6f67  8d4108               lea eax, [ecx + 8]
// 007b6f6a  83caff               or edx, 0xffffffff
// 007b6f6d  f00fc110             lock xadd dword ptr [eax], edx
// 007b6f71  7507                 jne 0x7b6f7a
// 007b6f73  8b01                 mov eax, dword ptr [ecx]
// 007b6f75  8b5008               mov edx, dword ptr [eax + 8]
// 007b6f78  ffd2                 call edx
// 007b6f7a  897e04               mov dword ptr [esi + 4], edi
// 007b6f7d  83c308               add ebx, 8
// 007b6f80  83c608               add esi, 8
// 007b6f83  3bdd                 cmp ebx, ebp
// 007b6f85  75bd                 jne 0x7b6f44
// 007b6f87  5f                   pop edi
// 007b6f88  8bc6                 mov eax, esi
// 007b6f8a  5e                   pop esi
// 007b6f8b  5d                   pop ebp
// 007b6f8c  5b                   pop ebx
// 007b6f8d  c3                   ret 
// 007b6f8e  8b442414             mov eax, dword ptr [esp + 0x14]
// 007b6f92  5d                   pop ebp
// 007b6f93  5b                   pop ebx
// 007b6f94  c3                   ret 
// library templates-boost-1_40_0/vector_wp.cpp (function ??$_Copy_opt@PAV?$weak_ptr@UT@@@boost@@PAV12@Uforward_iterator_tag@std@@@std@@YAPAV?$weak_ptr@UT@@@boost@@PAV12@00Uforward_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_40_0 vector_wp.cpp
