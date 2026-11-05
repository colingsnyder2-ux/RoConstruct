// from server: 100% by auto
// roc 2012-06 0065d1b0  unit: seg_00650000  size: 436 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0065d1b0
//
// 0065d1b0  53                   push ebx
// 0065d1b1  55                   push ebp
// 0065d1b2  56                   push esi
// 0065d1b3  8b742410             mov esi, dword ptr [esp + 0x10]
// 0065d1b7  f6466801             test byte ptr [esi + 0x68], 1
// 0065d1bb  57                   push edi
// 0065d1bc  750e                 jne 0x65d1cc
// 0065d1be  687caeb800           push 0xb8ae7c
// 0065d1c3  56                   push esi
// 0065d1c4  e8e70fffff           call 0x64e1b0
// 0065d1c9  83c408               add esp, 8
// 0065d1cc  8b4668               mov eax, dword ptr [esi + 0x68]
// 0065d1cf  a804                 test al, 4
// 0065d1d1  7406                 je 0x65d1d9
// 0065d1d3  83c808               or eax, 8
// 0065d1d6  894668               mov dword ptr [esi + 0x68], eax
// 0065d1d9  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 0065d1df  50                   push eax
// 0065d1e0  56                   push esi
// 0065d1e1  e83a13ffff           call 0x64e520
// 0065d1e6  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 0065d1ea  8d4d01               lea ecx, [ebp + 1]
// 0065d1ed  51                   push ecx
// 0065d1ee  56                   push esi
// 0065d1ef  e85c13ffff           call 0x64e550
// 0065d1f4  8bf8                 mov edi, eax
// 0065d1f6  33db                 xor ebx, ebx
// 0065d1f8  83c410               add esp, 0x10
// 0065d1fb  89be88020000         mov dword ptr [esi + 0x288], edi
// 0065d201  3bfb                 cmp edi, ebx
// 0065d203  7513                 jne 0x65d218
// 0065d205  6854aeb800           push 0xb8ae54
// 0065d20a  56                   push esi
// 0065d20b  e85010ffff           call 0x64e260
// 0065d210  83c408               add esp, 8
// 0065d213  5f                   pop edi
// 0065d214  5e                   pop esi
// 0065d215  5d                   pop ebp
// 0065d216  5b                   pop ebx
// 0065d217  c3                   ret 
// 0065d218  55                   push ebp
// 0065d219  57                   push edi
// 0065d21a  56                   push esi
// 0065d21b  e8d00bffff           call 0x64ddf0
// 0065d220  55                   push ebp
// 0065d221  57                   push edi
// 0065d222  56                   push esi
// 0065d223  e8680cfeff           call 0x63de90
// 0065d228  53                   push ebx
// 0065d229  56                   push esi
// 0065d22a  e821ddffff           call 0x65af50
// 0065d22f  83c420               add esp, 0x20
// 0065d232  85c0                 test eax, eax
// 0065d234  741b                 je 0x65d251
// 0065d236  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 0065d23c  52                   push edx
// 0065d23d  56                   push esi
// 0065d23e  e8dd12ffff           call 0x64e520
// 0065d243  83c408               add esp, 8
// 0065d246  5f                   pop edi
// 0065d247  899e88020000         mov dword ptr [esi + 0x288], ebx
// 0065d24d  5e                   pop esi
// 0065d24e  5d                   pop ebp
// 0065d24f  5b                   pop ebx
// 0065d250  c3                   ret 
// 0065d251  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 0065d257  881c28               mov byte ptr [eax + ebp], bl
// 0065d25a  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 0065d260  8bf8                 mov edi, eax
// 0065d262  381f                 cmp byte ptr [edi], bl
// 0065d264  7405                 je 0x65d26b
// 0065d266  47                   inc edi
// 0065d267  381f                 cmp byte ptr [edi], bl
// 0065d269  75fb                 jne 0x65d266
// 0065d26b  8d4c28fe             lea ecx, [eax + ebp - 2]
// 0065d26f  3bf9                 cmp edi, ecx
// 0065d271  7226                 jb 0x65d299
// 0065d273  683caeb800           push 0xb8ae3c
// 0065d278  56                   push esi
// 0065d279  e8e20fffff           call 0x64e260
// 0065d27e  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 0065d284  52                   push edx
// 0065d285  56                   push esi
// 0065d286  e89512ffff           call 0x64e520
// 0065d28b  83c410               add esp, 0x10
// 0065d28e  5f                   pop edi
// 0065d28f  899e88020000         mov dword ptr [esi + 0x288], ebx
// 0065d295  5e                   pop esi
// 0065d296  5d                   pop ebp
// 0065d297  5b                   pop ebx
// 0065d298  c3                   ret 
// 0065d299  0fbe5f01             movsx ebx, byte ptr [edi + 1]
// 0065d29d  47                   inc edi
// 0065d29e  85db                 test ebx, ebx
// 0065d2a0  7410                 je 0x65d2b2
// 0065d2a2  6814aeb800           push 0xb8ae14
// 0065d2a7  56                   push esi
// 0065d2a8  e8b30fffff           call 0x64e260
// 0065d2ad  83c408               add esp, 8
// 0065d2b0  33db                 xor ebx, ebx
// 0065d2b2  2bbe88020000         sub edi, dword ptr [esi + 0x288]
// 0065d2b8  8d442414             lea eax, [esp + 0x14]
// 0065d2bc  50                   push eax
// 0065d2bd  47                   inc edi
// 0065d2be  57                   push edi
// 0065d2bf  55                   push ebp
// 0065d2c0  53                   push ebx
// 0065d2c1  56                   push esi
// 0065d2c2  e8c9cbffff           call 0x659e90
// 0065d2c7  6a10                 push 0x10
// 0065d2c9  56                   push esi
// 0065d2ca  e88112ffff           call 0x64e550
// 0065d2cf  8be8                 mov ebp, eax
// 0065d2d1  83c41c               add esp, 0x1c
// 0065d2d4  85ed                 test ebp, ebp
// 0065d2d6  7526                 jne 0x65d2fe
// 0065d2d8  68e8adb800           push 0xb8ade8
// 0065d2dd  56                   push esi
// 0065d2de  e87d0fffff           call 0x64e260
// 0065d2e3  8b8e88020000         mov ecx, dword ptr [esi + 0x288]
// 0065d2e9  51                   push ecx
// 0065d2ea  56                   push esi
// 0065d2eb  e83012ffff           call 0x64e520
// 0065d2f0  83c410               add esp, 0x10
// 0065d2f3  5f                   pop edi
// 0065d2f4  89ae88020000         mov dword ptr [esi + 0x288], ebp
// 0065d2fa  5e                   pop esi
// 0065d2fb  5d                   pop ebp
// 0065d2fc  5b                   pop ebx
// 0065d2fd  c3                   ret 
// 0065d2fe  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0065d302  895d00               mov dword ptr [ebp], ebx
// 0065d305  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 0065d30b  6a01                 push 1
// 0065d30d  895504               mov dword ptr [ebp + 4], edx
// 0065d310  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 0065d316  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0065d31a  55                   push ebp
// 0065d31b  52                   push edx
// 0065d31c  03c7                 add eax, edi
// 0065d31e  56                   push esi
// 0065d31f  894508               mov dword ptr [ebp + 8], eax
// 0065d322  894d0c               mov dword ptr [ebp + 0xc], ecx
// 0065d325  e8c69dfeff           call 0x6470f0
// 0065d32a  55                   push ebp
// 0065d32b  56                   push esi
// 0065d32c  8bf8                 mov edi, eax
// 0065d32e  e8ed11ffff           call 0x64e520
// 0065d333  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 0065d339  50                   push eax
// 0065d33a  56                   push esi
// 0065d33b  e8e011ffff           call 0x64e520
// 0065d340  83c420               add esp, 0x20
// 0065d343  c7868802000000000000 mov dword ptr [esi + 0x288], 0
// 0065d34d  85ff                 test edi, edi
// 0065d34f  740e                 je 0x65d35f
// 0065d351  68bcadb800           push 0xb8adbc
// 0065d356  56                   push esi
// 0065d357  e8540effff           call 0x64e1b0
// 0065d35c  83c408               add esp, 8
// 0065d35f  5f                   pop edi
// 0065d360  5e                   pop esi
// 0065d361  5d                   pop ebp
// 0065d362  5b                   pop ebx
// 0065d363  c3                   ret 
// library libpng-1.2.32/pngrutil.c (function _png_handle_zTXt)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngrutil.c
