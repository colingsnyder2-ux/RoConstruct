// from server: 100% by auto
// roc 2011-06 00403970  unit: RBX::VRenderHooksService::?$FactoryProduct::Creator  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00403970
//
// 00403970  51                   push ecx
// 00403971  55                   push ebp
// 00403972  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 00403976  894c2404             mov dword ptr [esp + 4], ecx
// 0040397a  85ed                 test ebp, ebp
// 0040397c  7508                 jne 0x403986
// 0040397e  8d450d               lea eax, [ebp + 0xd]
// 00403981  5d                   pop ebp
// 00403982  59                   pop ecx
// 00403983  c20800               ret 8
// 00403986  53                   push ebx
// 00403987  8b1d6403a400         mov ebx, dword ptr [0xa40364]
// 0040398d  56                   push esi
// 0040398e  57                   push edi
// 0040398f  33ff                 xor edi, edi
// 00403991  8bf5                 mov esi, ebp
// 00403993  56                   push esi
// 00403994  ffd3                 call ebx
// 00403996  40                   inc eax
// 00403997  03f0                 add esi, eax
// 00403999  03f8                 add edi, eax
// 0040399b  83f801               cmp eax, 1
// 0040399e  75f3                 jne 0x403993
// 004039a0  8b442418             mov eax, dword ptr [esp + 0x18]
// 004039a4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004039a8  8b11                 mov edx, dword ptr [ecx]
// 004039aa  57                   push edi
// 004039ab  55                   push ebp
// 004039ac  6a07                 push 7
// 004039ae  6a00                 push 0
// 004039b0  50                   push eax
// 004039b1  52                   push edx
// 004039b2  ff154400a400         call dword ptr [0xa40044]
// 004039b8  5f                   pop edi
// 004039b9  5e                   pop esi
// 004039ba  5b                   pop ebx
// 004039bb  5d                   pop ebp
// 004039bc  59                   pop ecx
// 004039bd  c20800               ret 8
// library atl-9.0/atl.cpp (function ?SetMultiStringValue@CRegKey@ATL@@QAEJPBD0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
