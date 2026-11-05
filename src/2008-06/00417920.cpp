// from server: 100% by auto
// roc 2008-06 00417920  unit: VCLuaFunction::?$CComContainedObject  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00417920
//
// 00417920  57                   push edi
// 00417921  8b7c2408             mov edi, dword ptr [esp + 8]
// 00417925  85ff                 test edi, edi
// 00417927  7506                 jne 0x41792f
// 00417929  33c0                 xor eax, eax
// 0041792b  5f                   pop edi
// 0041792c  c20400               ret 4
// 0041792f  53                   push ebx
// 00417930  55                   push ebp
// 00417931  56                   push esi
// 00417932  8d6f04               lea ebp, [edi + 4]
// 00417935  55                   push ebp
// 00417936  33db                 xor ebx, ebx
// 00417938  ff15d4228000         call dword ptr [0x8022d4]
// 0041793e  8b771c               mov esi, dword ptr [edi + 0x1c]
// 00417941  85f6                 test esi, esi
// 00417943  744d                 je 0x417992
// 00417945  ff1598218000         call dword ptr [0x802198]
// 0041794b  33c9                 xor ecx, ecx
// 0041794d  8d4900               lea ecx, [ecx]
// 00417950  394604               cmp dword ptr [esi + 4], eax
// 00417953  7419                 je 0x41796e
// 00417955  8bce                 mov ecx, esi
// 00417957  8b7608               mov esi, dword ptr [esi + 8]
// 0041795a  85f6                 test esi, esi
// 0041795c  75f2                 jne 0x417950
// 0041795e  55                   push ebp
// 0041795f  ff15f4218000         call dword ptr [0x8021f4]
// 00417965  5e                   pop esi
// 00417966  5d                   pop ebp
// 00417967  8bc3                 mov eax, ebx
// 00417969  5b                   pop ebx
// 0041796a  5f                   pop edi
// 0041796b  c20400               ret 4
// 0041796e  85c9                 test ecx, ecx
// 00417970  7518                 jne 0x41798a
// 00417972  8b4608               mov eax, dword ptr [esi + 8]
// 00417975  89471c               mov dword ptr [edi + 0x1c], eax
// 00417978  8b1e                 mov ebx, dword ptr [esi]
// 0041797a  55                   push ebp
// 0041797b  ff15f4218000         call dword ptr [0x8021f4]
// 00417981  5e                   pop esi
// 00417982  5d                   pop ebp
// 00417983  8bc3                 mov eax, ebx
// 00417985  5b                   pop ebx
// 00417986  5f                   pop edi
// 00417987  c20400               ret 4
// 0041798a  8b5608               mov edx, dword ptr [esi + 8]
// 0041798d  895108               mov dword ptr [ecx + 8], edx
// 00417990  8b1e                 mov ebx, dword ptr [esi]
// 00417992  55                   push ebp
// 00417993  ff15f4218000         call dword ptr [0x8021f4]
// 00417999  5e                   pop esi
// 0041799a  5d                   pop ebp
// 0041799b  8bc3                 mov eax, ebx
// 0041799d  5b                   pop ebx
// 0041799e  5f                   pop edi
// 0041799f  c20400               ret 4
// library atl-8.0/atl.cpp (function _AtlWinModuleExtractCreateWndData@4)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
