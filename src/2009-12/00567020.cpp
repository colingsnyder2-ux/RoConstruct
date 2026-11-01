// from server: 100% by auto
// roc 2009-12 00567020  unit: RakPeer  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00567020
//
// 00567020  8b4104               mov eax, dword ptr [ecx + 4]
// 00567023  53                   push ebx
// 00567024  8b5908               mov ebx, dword ptr [ecx + 8]
// 00567027  3bc3                 cmp eax, ebx
// 00567029  745d                 je 0x567088
// 0056702b  7706                 ja 0x567033
// 0056702d  8bd3                 mov edx, ebx
// 0056702f  2bd0                 sub edx, eax
// 00567031  eb07                 jmp 0x56703a
// 00567033  8b510c               mov edx, dword ptr [ecx + 0xc]
// 00567036  2bd0                 sub edx, eax
// 00567038  03d3                 add edx, ebx
// 0056703a  57                   push edi
// 0056703b  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0056703f  3bfa                 cmp edi, edx
// 00567041  7344                 jae 0x567087
// 00567043  8b510c               mov edx, dword ptr [ecx + 0xc]
// 00567046  56                   push esi
// 00567047  8d3438               lea esi, [eax + edi]
// 0056704a  3bf2                 cmp esi, edx
// 0056704c  7206                 jb 0x567054
// 0056704e  2bc2                 sub eax, edx
// 00567050  03c7                 add eax, edi
// 00567052  8bf0                 mov esi, eax
// 00567054  8d4601               lea eax, [esi + 1]
// 00567057  3bc2                 cmp eax, edx
// 00567059  7502                 jne 0x56705d
// 0056705b  33c0                 xor eax, eax
// 0056705d  3bc3                 cmp eax, ebx
// 0056705f  7417                 je 0x567078
// 00567061  8b11                 mov edx, dword ptr [ecx]
// 00567063  8b3c82               mov edi, dword ptr [edx + eax*4]
// 00567066  893cb2               mov dword ptr [edx + esi*4], edi
// 00567069  8bf0                 mov esi, eax
// 0056706b  40                   inc eax
// 0056706c  3b410c               cmp eax, dword ptr [ecx + 0xc]
// 0056706f  7502                 jne 0x567073
// 00567071  33c0                 xor eax, eax
// 00567073  3b4108               cmp eax, dword ptr [ecx + 8]
// 00567076  75e9                 jne 0x567061
// 00567078  8b4108               mov eax, dword ptr [ecx + 8]
// 0056707b  5e                   pop esi
// 0056707c  85c0                 test eax, eax
// 0056707e  7503                 jne 0x567083
// 00567080  8b410c               mov eax, dword ptr [ecx + 0xc]
// 00567083  48                   dec eax
// 00567084  894108               mov dword ptr [ecx + 8], eax
// 00567087  5f                   pop edi
// 00567088  5b                   pop ebx
// 00567089  c20400               ret 4
// library raknet-4.081/FileListTransfer.cpp (function ?RemoveAtIndex@?$Queue@P6AHUThreadData@FileListTransfer@RakNet@@PA_NPAX@Z@DataStructures@@QAEXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 FileListTransfer.cpp
