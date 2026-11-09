// from server: 100% by auto
// roc 2010-06 007637f0  unit: RBX::Assembly  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007637f0
//
// 007637f0  53                   push ebx
// 007637f1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 007637f5  55                   push ebp
// 007637f6  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 007637fa  3bdd                 cmp ebx, ebp
// 007637fc  7450                 je 0x76384e
// 007637fe  56                   push esi
// 007637ff  8b742418             mov esi, dword ptr [esp + 0x18]
// 00763803  57                   push edi
// 00763804  8b03                 mov eax, dword ptr [ebx]
// 00763806  8906                 mov dword ptr [esi], eax
// 00763808  8b7b04               mov edi, dword ptr [ebx + 4]
// 0076380b  3b7e04               cmp edi, dword ptr [esi + 4]
// 0076380e  742d                 je 0x76383d
// 00763810  85ff                 test edi, edi
// 00763812  740c                 je 0x763820
// 00763814  8d4f08               lea ecx, [edi + 8]
// 00763817  ba01000000           mov edx, 1
// 0076381c  f00fc111             lock xadd dword ptr [ecx], edx
// 00763820  8b4e04               mov ecx, dword ptr [esi + 4]
// 00763823  85c9                 test ecx, ecx
// 00763825  7413                 je 0x76383a
// 00763827  8d4108               lea eax, [ecx + 8]
// 0076382a  83caff               or edx, 0xffffffff
// 0076382d  f00fc110             lock xadd dword ptr [eax], edx
// 00763831  7507                 jne 0x76383a
// 00763833  8b01                 mov eax, dword ptr [ecx]
// 00763835  8b5008               mov edx, dword ptr [eax + 8]
// 00763838  ffd2                 call edx
// 0076383a  897e04               mov dword ptr [esi + 4], edi
// 0076383d  83c308               add ebx, 8
// 00763840  83c608               add esi, 8
// 00763843  3bdd                 cmp ebx, ebp
// 00763845  75bd                 jne 0x763804
// 00763847  5f                   pop edi
// 00763848  8bc6                 mov eax, esi
// 0076384a  5e                   pop esi
// 0076384b  5d                   pop ebp
// 0076384c  5b                   pop ebx
// 0076384d  c3                   ret 
// 0076384e  8b442414             mov eax, dword ptr [esp + 0x14]
// 00763852  5d                   pop ebp
// 00763853  5b                   pop ebx
// 00763854  c3                   ret 
// library templates-boost-1_40_0/vector_wp.cpp (function ??$_Copy_opt@PAV?$weak_ptr@UT@@@boost@@PAV12@Uforward_iterator_tag@std@@@std@@YAPAV?$weak_ptr@UT@@@boost@@PAV12@00Uforward_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_40_0 vector_wp.cpp
