// from server: 100% by auto
// roc 2012-06 0065d040  unit: seg_00650000  size: 356 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0065d040
//
// 0065d040  55                   push ebp
// 0065d041  56                   push esi
// 0065d042  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0065d046  f6466801             test byte ptr [esi + 0x68], 1
// 0065d04a  57                   push edi
// 0065d04b  750e                 jne 0x65d05b
// 0065d04d  68a0adb800           push 0xb8ada0
// 0065d052  56                   push esi
// 0065d053  e85811ffff           call 0x64e1b0
// 0065d058  83c408               add esp, 8
// 0065d05b  8b4668               mov eax, dword ptr [esi + 0x68]
// 0065d05e  a804                 test al, 4
// 0065d060  7406                 je 0x65d068
// 0065d062  83c808               or eax, 8
// 0065d065  894668               mov dword ptr [esi + 0x68], eax
// 0065d068  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 0065d06e  50                   push eax
// 0065d06f  56                   push esi
// 0065d070  e8ab14ffff           call 0x64e520
// 0065d075  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 0065d079  8d4d01               lea ecx, [ebp + 1]
// 0065d07c  51                   push ecx
// 0065d07d  56                   push esi
// 0065d07e  e8cd14ffff           call 0x64e550
// 0065d083  8bf8                 mov edi, eax
// 0065d085  83c410               add esp, 0x10
// 0065d088  89be88020000         mov dword ptr [esi + 0x288], edi
// 0065d08e  85ff                 test edi, edi
// 0065d090  7512                 jne 0x65d0a4
// 0065d092  687cadb800           push 0xb8ad7c
// 0065d097  56                   push esi
// 0065d098  e8c311ffff           call 0x64e260
// 0065d09d  83c408               add esp, 8
// 0065d0a0  5f                   pop edi
// 0065d0a1  5e                   pop esi
// 0065d0a2  5d                   pop ebp
// 0065d0a3  c3                   ret 
// 0065d0a4  55                   push ebp
// 0065d0a5  57                   push edi
// 0065d0a6  56                   push esi
// 0065d0a7  e8440dffff           call 0x64ddf0
// 0065d0ac  55                   push ebp
// 0065d0ad  57                   push edi
// 0065d0ae  56                   push esi
// 0065d0af  e8dc0dfeff           call 0x63de90
// 0065d0b4  6a00                 push 0
// 0065d0b6  56                   push esi
// 0065d0b7  e894deffff           call 0x65af50
// 0065d0bc  83c420               add esp, 0x20
// 0065d0bf  85c0                 test eax, eax
// 0065d0c1  741e                 je 0x65d0e1
// 0065d0c3  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 0065d0c9  52                   push edx
// 0065d0ca  56                   push esi
// 0065d0cb  e85014ffff           call 0x64e520
// 0065d0d0  83c408               add esp, 8
// 0065d0d3  5f                   pop edi
// 0065d0d4  c7868802000000000000 mov dword ptr [esi + 0x288], 0
// 0065d0de  5e                   pop esi
// 0065d0df  5d                   pop ebp
// 0065d0e0  c3                   ret 
// 0065d0e1  53                   push ebx
// 0065d0e2  8b9e88020000         mov ebx, dword ptr [esi + 0x288]
// 0065d0e8  8d042b               lea eax, [ebx + ebp]
// 0065d0eb  c60000               mov byte ptr [eax], 0
// 0065d0ee  803b00               cmp byte ptr [ebx], 0
// 0065d0f1  8beb                 mov ebp, ebx
// 0065d0f3  7407                 je 0x65d0fc
// 0065d0f5  45                   inc ebp
// 0065d0f6  807d0000             cmp byte ptr [ebp], 0
// 0065d0fa  75f9                 jne 0x65d0f5
// 0065d0fc  3be8                 cmp ebp, eax
// 0065d0fe  7401                 je 0x65d101
// 0065d100  45                   inc ebp
// 0065d101  6a10                 push 0x10
// 0065d103  56                   push esi
// 0065d104  e84714ffff           call 0x64e550
// 0065d109  8bf8                 mov edi, eax
// 0065d10b  83c408               add esp, 8
// 0065d10e  85ff                 test edi, edi
// 0065d110  7526                 jne 0x65d138
// 0065d112  6850adb800           push 0xb8ad50
// 0065d117  56                   push esi
// 0065d118  e84311ffff           call 0x64e260
// 0065d11d  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 0065d123  50                   push eax
// 0065d124  56                   push esi
// 0065d125  e8f613ffff           call 0x64e520
// 0065d12a  83c410               add esp, 0x10
// 0065d12d  5b                   pop ebx
// 0065d12e  89be88020000         mov dword ptr [esi + 0x288], edi
// 0065d134  5f                   pop edi
// 0065d135  5e                   pop esi
// 0065d136  5d                   pop ebp
// 0065d137  c3                   ret 
// 0065d138  8bc5                 mov eax, ebp
// 0065d13a  c707ffffffff         mov dword ptr [edi], 0xffffffff
// 0065d140  895f04               mov dword ptr [edi + 4], ebx
// 0065d143  896f08               mov dword ptr [edi + 8], ebp
// 0065d146  8d5001               lea edx, [eax + 1]
// 0065d149  8da42400000000       lea esp, [esp]
// 0065d150  8a08                 mov cl, byte ptr [eax]
// 0065d152  40                   inc eax
// 0065d153  84c9                 test cl, cl
// 0065d155  75f9                 jne 0x65d150
// 0065d157  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0065d15b  6a01                 push 1
// 0065d15d  57                   push edi
// 0065d15e  51                   push ecx
// 0065d15f  2bc2                 sub eax, edx
// 0065d161  56                   push esi
// 0065d162  89470c               mov dword ptr [edi + 0xc], eax
// 0065d165  e8869ffeff           call 0x6470f0
// 0065d16a  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 0065d170  52                   push edx
// 0065d171  56                   push esi
// 0065d172  8bd8                 mov ebx, eax
// 0065d174  e8a713ffff           call 0x64e520
// 0065d179  57                   push edi
// 0065d17a  56                   push esi
// 0065d17b  c7868802000000000000 mov dword ptr [esi + 0x288], 0
// 0065d185  e89613ffff           call 0x64e520
// 0065d18a  83c420               add esp, 0x20
// 0065d18d  85db                 test ebx, ebx
// 0065d18f  740e                 je 0x65d19f
// 0065d191  6824adb800           push 0xb8ad24
// 0065d196  56                   push esi
// 0065d197  e8c410ffff           call 0x64e260
// 0065d19c  83c408               add esp, 8
// 0065d19f  5b                   pop ebx
// 0065d1a0  5f                   pop edi
// 0065d1a1  5e                   pop esi
// 0065d1a2  5d                   pop ebp
// 0065d1a3  c3                   ret 
// library libpng-1.2.35/pngrutil.c (function _png_handle_tEXt)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.35 pngrutil.c
