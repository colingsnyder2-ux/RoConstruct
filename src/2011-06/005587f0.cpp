// from server: 100% by auto
// roc 2011-06 005587f0  unit: seg_00550000  size: 736 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005587f0
//
// 005587f0  55                   push ebp
// 005587f1  8b6c2408             mov ebp, dword ptr [esp + 8]
// 005587f5  85ed                 test ebp, ebp
// 005587f7  0f84d1020000         je 0x558ace
// 005587fd  56                   push esi
// 005587fe  8b742410             mov esi, dword ptr [esp + 0x10]
// 00558802  85f6                 test esi, esi
// 00558804  0f84c3020000         je 0x558acd
// 0055880a  56                   push esi
// 0055880b  55                   push ebp
// 0055880c  e8effdffff           call 0x558600
// 00558811  83c408               add esp, 8
// 00558814  f6460808             test byte ptr [esi + 8], 8
// 00558818  7414                 je 0x55882e
// 0055881a  0fb74614             movzx eax, word ptr [esi + 0x14]
// 0055881e  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00558821  50                   push eax
// 00558822  51                   push ecx
// 00558823  55                   push ebp
// 00558824  e8e7250100           call 0x56ae10
// 00558829  83c40c               add esp, 0xc
// 0055882c  eb14                 jmp 0x558842
// 0055882e  807e1903             cmp byte ptr [esi + 0x19], 3
// 00558832  750e                 jne 0x558842
// 00558834  68c01fa800           push 0xa81fc0
// 00558839  55                   push ebp
// 0055883a  e8f18a0000           call 0x561330
// 0055883f  83c408               add esp, 8
// 00558842  f6460810             test byte ptr [esi + 8], 0x10
// 00558846  7449                 je 0x558891
// 00558848  f7457000000800       test dword ptr [ebp + 0x70], 0x80000
// 0055884f  7425                 je 0x558876
// 00558851  807e1903             cmp byte ptr [esi + 0x19], 3
// 00558855  751f                 jne 0x558876
// 00558857  33d2                 xor edx, edx
// 00558859  33c0                 xor eax, eax
// 0055885b  663b5616             cmp dx, word ptr [esi + 0x16]
// 0055885f  7315                 jae 0x558876
// 00558861  8b4e4c               mov ecx, dword ptr [esi + 0x4c]
// 00558864  03c8                 add ecx, eax
// 00558866  80caff               or dl, 0xff
// 00558869  2a11                 sub dl, byte ptr [ecx]
// 0055886b  40                   inc eax
// 0055886c  8811                 mov byte ptr [ecx], dl
// 0055886e  0fb74e16             movzx ecx, word ptr [esi + 0x16]
// 00558872  3bc1                 cmp eax, ecx
// 00558874  7ceb                 jl 0x558861
// 00558876  0fb65619             movzx edx, byte ptr [esi + 0x19]
// 0055887a  0fb74616             movzx eax, word ptr [esi + 0x16]
// 0055887e  52                   push edx
// 0055887f  8b564c               mov edx, dword ptr [esi + 0x4c]
// 00558882  50                   push eax
// 00558883  8d4e50               lea ecx, [esi + 0x50]
// 00558886  51                   push ecx
// 00558887  52                   push edx
// 00558888  55                   push ebp
// 00558889  e802420100           call 0x56ca90
// 0055888e  83c414               add esp, 0x14
// 00558891  f6460820             test byte ptr [esi + 8], 0x20
// 00558895  7412                 je 0x5588a9
// 00558897  0fb64619             movzx eax, byte ptr [esi + 0x19]
// 0055889b  50                   push eax
// 0055889c  8d4e5a               lea ecx, [esi + 0x5a]
// 0055889f  51                   push ecx
// 005588a0  55                   push ebp
// 005588a1  e84a430100           call 0x56cbf0
// 005588a6  83c40c               add esp, 0xc
// 005588a9  f6460840             test byte ptr [esi + 8], 0x40
// 005588ad  7412                 je 0x5588c1
// 005588af  0fb75614             movzx edx, word ptr [esi + 0x14]
// 005588b3  8b467c               mov eax, dword ptr [esi + 0x7c]
// 005588b6  52                   push edx
// 005588b7  50                   push eax
// 005588b8  55                   push ebp
// 005588b9  e862260100           call 0x56af20
// 005588be  83c40c               add esp, 0xc
// 005588c1  f7460800010000       test dword ptr [esi + 8], 0x100
// 005588c8  7416                 je 0x5588e0
// 005588ca  0fb64e6c             movzx ecx, byte ptr [esi + 0x6c]
// 005588ce  8b5668               mov edx, dword ptr [esi + 0x68]
// 005588d1  8b4664               mov eax, dword ptr [esi + 0x64]
// 005588d4  51                   push ecx
// 005588d5  52                   push edx
// 005588d6  50                   push eax
// 005588d7  55                   push ebp
// 005588d8  e873440100           call 0x56cd50
// 005588dd  83c410               add esp, 0x10
// 005588e0  f7460800040000       test dword ptr [esi + 8], 0x400
// 005588e7  743c                 je 0x558925
// 005588e9  8b8eb0000000         mov ecx, dword ptr [esi + 0xb0]
// 005588ef  8b96ac000000         mov edx, dword ptr [esi + 0xac]
// 005588f5  0fb686b5000000       movzx eax, byte ptr [esi + 0xb5]
// 005588fc  51                   push ecx
// 005588fd  0fb68eb4000000       movzx ecx, byte ptr [esi + 0xb4]
// 00558904  52                   push edx
// 00558905  8b96a8000000         mov edx, dword ptr [esi + 0xa8]
// 0055890b  50                   push eax
// 0055890c  8b86a4000000         mov eax, dword ptr [esi + 0xa4]
// 00558912  51                   push ecx
// 00558913  8b8ea0000000         mov ecx, dword ptr [esi + 0xa0]
// 00558919  52                   push edx
// 0055891a  50                   push eax
// 0055891b  51                   push ecx
// 0055891c  55                   push ebp
// 0055891d  e8fe2a0100           call 0x56b420
// 00558922  83c420               add esp, 0x20
// 00558925  f7460800400000       test dword ptr [esi + 8], 0x4000
// 0055892c  7427                 je 0x558955
// 0055892e  dd86e8000000         fld qword ptr [esi + 0xe8]
// 00558934  0fb696dc000000       movzx edx, byte ptr [esi + 0xdc]
// 0055893b  83ec10               sub esp, 0x10
// 0055893e  dd5c2408             fstp qword ptr [esp + 8]
// 00558942  dd86e0000000         fld qword ptr [esi + 0xe0]
// 00558948  dd1c24               fstp qword ptr [esp]
// 0055894b  52                   push edx
// 0055894c  55                   push ebp
// 0055894d  e8ee440100           call 0x56ce40
// 00558952  83c418               add esp, 0x18
// 00558955  f6460880             test byte ptr [esi + 8], 0x80
// 00558959  7416                 je 0x558971
// 0055895b  0fb64678             movzx eax, byte ptr [esi + 0x78]
// 0055895f  8b4e74               mov ecx, dword ptr [esi + 0x74]
// 00558962  8b5670               mov edx, dword ptr [esi + 0x70]
// 00558965  50                   push eax
// 00558966  51                   push ecx
// 00558967  52                   push edx
// 00558968  55                   push ebp
// 00558969  e882450100           call 0x56cef0
// 0055896e  83c410               add esp, 0x10
// 00558971  57                   push edi
// 00558972  bf00020000           mov edi, 0x200
// 00558977  857e08               test dword ptr [esi + 8], edi
// 0055897a  7410                 je 0x55898c
// 0055897c  8d463c               lea eax, [esi + 0x3c]
// 0055897f  50                   push eax
// 00558980  55                   push ebp
// 00558981  e85a460100           call 0x56cfe0
// 00558986  83c408               add esp, 8
// 00558989  097d68               or dword ptr [ebp + 0x68], edi
// 0055898c  f7460800200000       test dword ptr [esi + 8], 0x2000
// 00558993  53                   push ebx
// 00558994  742a                 je 0x5589c0
// 00558996  33ff                 xor edi, edi
// 00558998  39bed8000000         cmp dword ptr [esi + 0xd8], edi
// 0055899e  7e20                 jle 0x5589c0
// 005589a0  33db                 xor ebx, ebx
// 005589a2  8b8ed4000000         mov ecx, dword ptr [esi + 0xd4]
// 005589a8  03cb                 add ecx, ebx
// 005589aa  51                   push ecx
// 005589ab  55                   push ebp
// 005589ac  e8cf3a0100           call 0x56c480
// 005589b1  47                   inc edi
// 005589b2  83c408               add esp, 8
// 005589b5  83c310               add ebx, 0x10
// 005589b8  3bbed8000000         cmp edi, dword ptr [esi + 0xd8]
// 005589be  7ce2                 jl 0x5589a2
// 005589c0  33db                 xor ebx, ebx
// 005589c2  395e30               cmp dword ptr [esi + 0x30], ebx
// 005589c5  0f8e84000000         jle 0x558a4f
// 005589cb  33ff                 xor edi, edi
// 005589cd  8d4900               lea ecx, [ecx]
// 005589d0  8b5638               mov edx, dword ptr [esi + 0x38]
// 005589d3  8b0417               mov eax, dword ptr [edi + edx]
// 005589d6  85c0                 test eax, eax
// 005589d8  7e1a                 jle 0x5589f4
// 005589da  689c1fa800           push 0xa81f9c
// 005589df  55                   push ebp
// 005589e0  e8fb890000           call 0x5613e0
// 005589e5  8b4638               mov eax, dword ptr [esi + 0x38]
// 005589e8  83c408               add esp, 8
// 005589eb  c70407fdffffff       mov dword ptr [edi + eax], 0xfffffffd
// 005589f2  eb52                 jmp 0x558a46
// 005589f4  7528                 jne 0x558a1e
// 005589f6  8bca                 mov ecx, edx
// 005589f8  8b140f               mov edx, dword ptr [edi + ecx]
// 005589fb  8d040f               lea eax, [edi + ecx]
// 005589fe  8b4808               mov ecx, dword ptr [eax + 8]
// 00558a01  52                   push edx
// 00558a02  8b5004               mov edx, dword ptr [eax + 4]
// 00558a05  6a00                 push 0
// 00558a07  51                   push ecx
// 00558a08  52                   push edx
// 00558a09  55                   push ebp
// 00558a0a  e8e1280100           call 0x56b2f0
// 00558a0f  8b4638               mov eax, dword ptr [esi + 0x38]
// 00558a12  83c414               add esp, 0x14
// 00558a15  c70407feffffff       mov dword ptr [edi + eax], 0xfffffffe
// 00558a1c  eb28                 jmp 0x558a46
// 00558a1e  83f8ff               cmp eax, -1
// 00558a21  7523                 jne 0x558a46
// 00558a23  8bca                 mov ecx, edx
// 00558a25  8b540f08             mov edx, dword ptr [edi + ecx + 8]
// 00558a29  8d040f               lea eax, [edi + ecx]
// 00558a2c  8b4004               mov eax, dword ptr [eax + 4]
// 00558a2f  6a00                 push 0
// 00558a31  52                   push edx
// 00558a32  50                   push eax
// 00558a33  55                   push ebp
// 00558a34  e8a7270100           call 0x56b1e0
// 00558a39  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 00558a3c  83c410               add esp, 0x10
// 00558a3f  c7040ffdffffff       mov dword ptr [edi + ecx], 0xfffffffd
// 00558a46  43                   inc ebx
// 00558a47  83c710               add edi, 0x10
// 00558a4a  3b5e30               cmp ebx, dword ptr [esi + 0x30]
// 00558a4d  7c81                 jl 0x5589d0
// 00558a4f  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 00558a55  85c0                 test eax, eax
// 00558a57  7472                 je 0x558acb
// 00558a59  8bbebc000000         mov edi, dword ptr [esi + 0xbc]
// 00558a5f  8d1480               lea edx, [eax + eax*4]
// 00558a62  8d0497               lea eax, [edi + edx*4]
// 00558a65  3bf8                 cmp edi, eax
// 00558a67  7362                 jae 0x558acb
// 00558a69  bb00000100           mov ebx, 0x10000
// 00558a6e  8bff                 mov edi, edi
// 00558a70  57                   push edi
// 00558a71  55                   push ebp
// 00558a72  e84982ffff           call 0x550cc0
// 00558a77  83c408               add esp, 8
// 00558a7a  83f801               cmp eax, 1
// 00558a7d  7433                 je 0x558ab2
// 00558a7f  8a4f10               mov cl, byte ptr [edi + 0x10]
// 00558a82  84c9                 test cl, cl
// 00558a84  742c                 je 0x558ab2
// 00558a86  f6c102               test cl, 2
// 00558a89  7427                 je 0x558ab2
// 00558a8b  f6c104               test cl, 4
// 00558a8e  7522                 jne 0x558ab2
// 00558a90  f6470320             test byte ptr [edi + 3], 0x20
// 00558a94  750a                 jne 0x558aa0
// 00558a96  83f803               cmp eax, 3
// 00558a99  7405                 je 0x558aa0
// 00558a9b  855d6c               test dword ptr [ebp + 0x6c], ebx
// 00558a9e  7412                 je 0x558ab2
// 00558aa0  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 00558aa3  8b5708               mov edx, dword ptr [edi + 8]
// 00558aa6  51                   push ecx
// 00558aa7  52                   push edx
// 00558aa8  57                   push edi
// 00558aa9  55                   push ebp
// 00558aaa  e861300100           call 0x56bb10
// 00558aaf  83c410               add esp, 0x10
// 00558ab2  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 00558ab8  8b8ebc000000         mov ecx, dword ptr [esi + 0xbc]
// 00558abe  8d0480               lea eax, [eax + eax*4]
// 00558ac1  83c714               add edi, 0x14
// 00558ac4  8d1481               lea edx, [ecx + eax*4]
// 00558ac7  3bfa                 cmp edi, edx
// 00558ac9  72a5                 jb 0x558a70
// 00558acb  5b                   pop ebx
// 00558acc  5f                   pop edi
// 00558acd  5e                   pop esi
// 00558ace  5d                   pop ebp
// 00558acf  c3                   ret 
// library libpng-1.2.10/pngwrite.c (function _png_write_info)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngwrite.c
