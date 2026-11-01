// from server: 100% by auto
// roc 2009-12 006a1b20  unit: RBX::VScriptContext::?$FactoryProduct  size: 124 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006a1b20
//
// 006a1b20  55                   push ebp
// 006a1b21  8b6c2408             mov ebp, dword ptr [esp + 8]
// 006a1b25  3b6c240c             cmp ebp, dword ptr [esp + 0xc]
// 006a1b29  746b                 je 0x6a1b96
// 006a1b2b  53                   push ebx
// 006a1b2c  56                   push esi
// 006a1b2d  57                   push edi
// 006a1b2e  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 006a1b32  8b4500               mov eax, dword ptr [ebp]
// 006a1b35  8907                 mov dword ptr [edi], eax
// 006a1b37  8b5d04               mov ebx, dword ptr [ebp + 4]
// 006a1b3a  3b5f04               cmp ebx, dword ptr [edi + 4]
// 006a1b3d  7444                 je 0x6a1b83
// 006a1b3f  85db                 test ebx, ebx
// 006a1b41  740c                 je 0x6a1b4f
// 006a1b43  8d4b04               lea ecx, [ebx + 4]
// 006a1b46  ba01000000           mov edx, 1
// 006a1b4b  f00fc111             lock xadd dword ptr [ecx], edx
// 006a1b4f  8b7704               mov esi, dword ptr [edi + 4]
// 006a1b52  85f6                 test esi, esi
// 006a1b54  742a                 je 0x6a1b80
// 006a1b56  8d4604               lea eax, [esi + 4]
// 006a1b59  83c9ff               or ecx, 0xffffffff
// 006a1b5c  f00fc108             lock xadd dword ptr [eax], ecx
// 006a1b60  751e                 jne 0x6a1b80
// 006a1b62  8b16                 mov edx, dword ptr [esi]
// 006a1b64  8b4204               mov eax, dword ptr [edx + 4]
// 006a1b67  8bce                 mov ecx, esi
// 006a1b69  ffd0                 call eax
// 006a1b6b  8d4e08               lea ecx, [esi + 8]
// 006a1b6e  83caff               or edx, 0xffffffff
// 006a1b71  f00fc111             lock xadd dword ptr [ecx], edx
// 006a1b75  7509                 jne 0x6a1b80
// 006a1b77  8b06                 mov eax, dword ptr [esi]
// 006a1b79  8b5008               mov edx, dword ptr [eax + 8]
// 006a1b7c  8bce                 mov ecx, esi
// 006a1b7e  ffd2                 call edx
// 006a1b80  895f04               mov dword ptr [edi + 4], ebx
// 006a1b83  83c508               add ebp, 8
// 006a1b86  83c708               add edi, 8
// 006a1b89  3b6c2418             cmp ebp, dword ptr [esp + 0x18]
// 006a1b8d  75a3                 jne 0x6a1b32
// 006a1b8f  8bc7                 mov eax, edi
// 006a1b91  5f                   pop edi
// 006a1b92  5e                   pop esi
// 006a1b93  5b                   pop ebx
// 006a1b94  5d                   pop ebp
// 006a1b95  c3                   ret 
// 006a1b96  8b442410             mov eax, dword ptr [esp + 0x10]
// 006a1b9a  5d                   pop ebp
// 006a1b9b  c3                   ret 
// library templates-boost-1_34_1/vector_sp.cpp (function ??$_Copy_opt@PAV?$shared_ptr@UT@@@boost@@PAV12@Uforward_iterator_tag@std@@@std@@YAPAV?$shared_ptr@UT@@@boost@@PAV12@00Uforward_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 vector_sp.cpp
