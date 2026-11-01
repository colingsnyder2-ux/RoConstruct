// from server: 100% by auto
// roc 2009-12 0075d140  unit: RBX::SelectionPointLasso  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0075d140
//
// 0075d140  53                   push ebx
// 0075d141  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0075d145  55                   push ebp
// 0075d146  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 0075d14a  3bdd                 cmp ebx, ebp
// 0075d14c  7450                 je 0x75d19e
// 0075d14e  56                   push esi
// 0075d14f  8b742418             mov esi, dword ptr [esp + 0x18]
// 0075d153  57                   push edi
// 0075d154  8b03                 mov eax, dword ptr [ebx]
// 0075d156  8906                 mov dword ptr [esi], eax
// 0075d158  8b7b04               mov edi, dword ptr [ebx + 4]
// 0075d15b  3b7e04               cmp edi, dword ptr [esi + 4]
// 0075d15e  742d                 je 0x75d18d
// 0075d160  85ff                 test edi, edi
// 0075d162  740c                 je 0x75d170
// 0075d164  8d4f08               lea ecx, [edi + 8]
// 0075d167  ba01000000           mov edx, 1
// 0075d16c  f00fc111             lock xadd dword ptr [ecx], edx
// 0075d170  8b4e04               mov ecx, dword ptr [esi + 4]
// 0075d173  85c9                 test ecx, ecx
// 0075d175  7413                 je 0x75d18a
// 0075d177  8d4108               lea eax, [ecx + 8]
// 0075d17a  83caff               or edx, 0xffffffff
// 0075d17d  f00fc110             lock xadd dword ptr [eax], edx
// 0075d181  7507                 jne 0x75d18a
// 0075d183  8b01                 mov eax, dword ptr [ecx]
// 0075d185  8b5008               mov edx, dword ptr [eax + 8]
// 0075d188  ffd2                 call edx
// 0075d18a  897e04               mov dword ptr [esi + 4], edi
// 0075d18d  83c308               add ebx, 8
// 0075d190  83c608               add esi, 8
// 0075d193  3bdd                 cmp ebx, ebp
// 0075d195  75bd                 jne 0x75d154
// 0075d197  5f                   pop edi
// 0075d198  8bc6                 mov eax, esi
// 0075d19a  5e                   pop esi
// 0075d19b  5d                   pop ebp
// 0075d19c  5b                   pop ebx
// 0075d19d  c3                   ret 
// 0075d19e  8b442414             mov eax, dword ptr [esp + 0x14]
// 0075d1a2  5d                   pop ebp
// 0075d1a3  5b                   pop ebx
// 0075d1a4  c3                   ret 
// library templates-boost-1_40_0/vector_wp.cpp (function ??$_Copy_opt@PAV?$weak_ptr@UT@@@boost@@PAV12@Uforward_iterator_tag@std@@@std@@YAPAV?$weak_ptr@UT@@@boost@@PAV12@00Uforward_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_40_0 vector_wp.cpp
