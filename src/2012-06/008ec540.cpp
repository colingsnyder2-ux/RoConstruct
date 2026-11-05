// from server: 100% by auto
// roc 2012-06 008ec540  unit: RBX::VLuaDragger::?$FactoryProduct  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008ec540
//
// 008ec540  53                   push ebx
// 008ec541  8b5c2408             mov ebx, dword ptr [esp + 8]
// 008ec545  55                   push ebp
// 008ec546  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 008ec54a  3bdd                 cmp ebx, ebp
// 008ec54c  7450                 je 0x8ec59e
// 008ec54e  56                   push esi
// 008ec54f  8b742418             mov esi, dword ptr [esp + 0x18]
// 008ec553  57                   push edi
// 008ec554  8b03                 mov eax, dword ptr [ebx]
// 008ec556  8906                 mov dword ptr [esi], eax
// 008ec558  8b7b04               mov edi, dword ptr [ebx + 4]
// 008ec55b  3b7e04               cmp edi, dword ptr [esi + 4]
// 008ec55e  742d                 je 0x8ec58d
// 008ec560  85ff                 test edi, edi
// 008ec562  740c                 je 0x8ec570
// 008ec564  8d4f08               lea ecx, [edi + 8]
// 008ec567  ba01000000           mov edx, 1
// 008ec56c  f00fc111             lock xadd dword ptr [ecx], edx
// 008ec570  8b4e04               mov ecx, dword ptr [esi + 4]
// 008ec573  85c9                 test ecx, ecx
// 008ec575  7413                 je 0x8ec58a
// 008ec577  8d4108               lea eax, [ecx + 8]
// 008ec57a  83caff               or edx, 0xffffffff
// 008ec57d  f00fc110             lock xadd dword ptr [eax], edx
// 008ec581  7507                 jne 0x8ec58a
// 008ec583  8b01                 mov eax, dword ptr [ecx]
// 008ec585  8b5008               mov edx, dword ptr [eax + 8]
// 008ec588  ffd2                 call edx
// 008ec58a  897e04               mov dword ptr [esi + 4], edi
// 008ec58d  83c308               add ebx, 8
// 008ec590  83c608               add esi, 8
// 008ec593  3bdd                 cmp ebx, ebp
// 008ec595  75bd                 jne 0x8ec554
// 008ec597  5f                   pop edi
// 008ec598  8bc6                 mov eax, esi
// 008ec59a  5e                   pop esi
// 008ec59b  5d                   pop ebp
// 008ec59c  5b                   pop ebx
// 008ec59d  c3                   ret 
// 008ec59e  8b442414             mov eax, dword ptr [esp + 0x14]
// 008ec5a2  5d                   pop ebp
// 008ec5a3  5b                   pop ebx
// 008ec5a4  c3                   ret 
// library templates-boost-1_40_0/vector_wp.cpp (function ??$_Copy_opt@PAV?$weak_ptr@UT@@@boost@@PAV12@Uforward_iterator_tag@std@@@std@@YAPAV?$weak_ptr@UT@@@boost@@PAV12@00Uforward_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_40_0 vector_wp.cpp
