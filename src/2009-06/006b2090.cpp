// from server: 100% by auto
// roc 2009-06 006b2090  unit: RBX::BlockBlockContact  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b2090
//
// 006b2090  53                   push ebx
// 006b2091  8b5c2408             mov ebx, dword ptr [esp + 8]
// 006b2095  55                   push ebp
// 006b2096  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 006b209a  3bdd                 cmp ebx, ebp
// 006b209c  7450                 je 0x6b20ee
// 006b209e  56                   push esi
// 006b209f  8b742418             mov esi, dword ptr [esp + 0x18]
// 006b20a3  57                   push edi
// 006b20a4  8b03                 mov eax, dword ptr [ebx]
// 006b20a6  8906                 mov dword ptr [esi], eax
// 006b20a8  8b7b04               mov edi, dword ptr [ebx + 4]
// 006b20ab  3b7e04               cmp edi, dword ptr [esi + 4]
// 006b20ae  742d                 je 0x6b20dd
// 006b20b0  85ff                 test edi, edi
// 006b20b2  740c                 je 0x6b20c0
// 006b20b4  8d4f08               lea ecx, [edi + 8]
// 006b20b7  ba01000000           mov edx, 1
// 006b20bc  f00fc111             lock xadd dword ptr [ecx], edx
// 006b20c0  8b4e04               mov ecx, dword ptr [esi + 4]
// 006b20c3  85c9                 test ecx, ecx
// 006b20c5  7413                 je 0x6b20da
// 006b20c7  8d4108               lea eax, [ecx + 8]
// 006b20ca  83caff               or edx, 0xffffffff
// 006b20cd  f00fc110             lock xadd dword ptr [eax], edx
// 006b20d1  7507                 jne 0x6b20da
// 006b20d3  8b01                 mov eax, dword ptr [ecx]
// 006b20d5  8b5008               mov edx, dword ptr [eax + 8]
// 006b20d8  ffd2                 call edx
// 006b20da  897e04               mov dword ptr [esi + 4], edi
// 006b20dd  83c308               add ebx, 8
// 006b20e0  83c608               add esi, 8
// 006b20e3  3bdd                 cmp ebx, ebp
// 006b20e5  75bd                 jne 0x6b20a4
// 006b20e7  5f                   pop edi
// 006b20e8  8bc6                 mov eax, esi
// 006b20ea  5e                   pop esi
// 006b20eb  5d                   pop ebp
// 006b20ec  5b                   pop ebx
// 006b20ed  c3                   ret 
// 006b20ee  8b442414             mov eax, dword ptr [esp + 0x14]
// 006b20f2  5d                   pop ebp
// 006b20f3  5b                   pop ebx
// 006b20f4  c3                   ret 
// library templates-boost-1_40_0/vector_wp.cpp (function ??$_Copy_opt@PAV?$weak_ptr@UT@@@boost@@PAV12@Uforward_iterator_tag@std@@@std@@YAPAV?$weak_ptr@UT@@@boost@@PAV12@00Uforward_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_40_0 vector_wp.cpp
