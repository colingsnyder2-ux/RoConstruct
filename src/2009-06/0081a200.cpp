// from server: 100% by auto
// roc 2009-06 0081a200  unit: CXTCaptionButtonTheme  size: 319 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0081a200
//
// 0081a200  83ec14               sub esp, 0x14
// 0081a203  8b01                 mov eax, dword ptr [ecx]
// 0081a205  8b5014               mov edx, dword ptr [eax + 0x14]
// 0081a208  57                   push edi
// 0081a209  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0081a20d  57                   push edi
// 0081a20e  894c2408             mov dword ptr [esp + 8], ecx
// 0081a212  ffd2                 call edx
// 0081a214  85c0                 test eax, eax
// 0081a216  0f841a010000         je 0x81a336
// 0081a21c  53                   push ebx
// 0081a21d  55                   push ebp
// 0081a21e  56                   push esi
// 0081a21f  8b742428             mov esi, dword ptr [esp + 0x28]
// 0081a223  8b4618               mov eax, dword ptr [esi + 0x18]
// 0081a226  50                   push eax
// 0081a227  e8e01c0300           call 0x84bf0c
// 0081a22c  8d4e1c               lea ecx, [esi + 0x1c]
// 0081a22f  51                   push ecx
// 0081a230  8d542418             lea edx, [esp + 0x18]
// 0081a234  52                   push edx
// 0081a235  8be8                 mov ebp, eax
// 0081a237  ff1500ee8900         call dword ptr [0x89ee00]
// 0081a23d  8b4610               mov eax, dword ptr [esi + 0x10]
// 0081a240  8ad8                 mov bl, al
// 0081a242  c1e802               shr eax, 2
// 0081a245  2401                 and al, 1
// 0081a247  8bcf                 mov ecx, edi
// 0081a249  80e301               and bl, 1
// 0081a24c  8844242c             mov byte ptr [esp + 0x2c], al
// 0081a250  be01000000           mov esi, 1
// 0081a255  e80608ffff           call 0x80aa60
// 0081a25a  3c01                 cmp al, 1
// 0081a25c  7505                 jne 0x81a263
// 0081a25e  be05000000           mov esi, 5
// 0081a263  83bfa000000000       cmp dword ptr [edi + 0xa0], 0
// 0081a26a  750b                 jne 0x81a277
// 0081a26c  ff153cee8900         call dword ptr [0x89ee3c]
// 0081a272  3b4720               cmp eax, dword ptr [edi + 0x20]
// 0081a275  7505                 jne 0x81a27c
// 0081a277  be02000000           mov esi, 2
// 0081a27c  84db                 test bl, bl
// 0081a27e  7506                 jne 0x81a286
// 0081a280  837f7c00             cmp dword ptr [edi + 0x7c], 0
// 0081a284  7405                 je 0x81a28b
// 0081a286  be03000000           mov esi, 3
// 0081a28b  807c242c00           cmp byte ptr [esp + 0x2c], 0
// 0081a290  7405                 je 0x81a297
// 0081a292  be04000000           mov esi, 4
// 0081a297  8b7f20               mov edi, dword ptr [edi + 0x20]
// 0081a29a  85ed                 test ebp, ebp
// 0081a29c  7504                 jne 0x81a2a2
// 0081a29e  33db                 xor ebx, ebx
// 0081a2a0  eb03                 jmp 0x81a2a5
// 0081a2a2  8b5d04               mov ebx, dword ptr [ebp + 4]
// 0081a2a5  57                   push edi
// 0081a2a6  ff1598ee8900         call dword ptr [0x89ee98]
// 0081a2ac  50                   push eax
// 0081a2ad  e850eaefff           call 0x718d02
// 0081a2b2  8b4020               mov eax, dword ptr [eax + 0x20]
// 0081a2b5  57                   push edi
// 0081a2b6  53                   push ebx
// 0081a2b7  6835010000           push 0x135
// 0081a2bc  50                   push eax
// 0081a2bd  ff1590ee8900         call dword ptr [0x89ee90]
// 0081a2c3  85c0                 test eax, eax
// 0081a2c5  7427                 je 0x81a2ee
// 0081a2c7  85ed                 test ebp, ebp
// 0081a2c9  7511                 jne 0x81a2dc
// 0081a2cb  50                   push eax
// 0081a2cc  8d542418             lea edx, [esp + 0x18]
// 0081a2d0  33c9                 xor ecx, ecx
// 0081a2d2  52                   push edx
// 0081a2d3  51                   push ecx
// 0081a2d4  ff15b4ec8900         call dword ptr [0x89ecb4]
// 0081a2da  eb2d                 jmp 0x81a309
// 0081a2dc  8b4d04               mov ecx, dword ptr [ebp + 4]
// 0081a2df  50                   push eax
// 0081a2e0  8d542418             lea edx, [esp + 0x18]
// 0081a2e4  52                   push edx
// 0081a2e5  51                   push ecx
// 0081a2e6  ff15b4ec8900         call dword ptr [0x89ecb4]
// 0081a2ec  eb1b                 jmp 0x81a309
// 0081a2ee  e82da8f3ff           call 0x754b20
// 0081a2f3  6a0f                 push 0xf
// 0081a2f5  8bc8                 mov ecx, eax
// 0081a2f7  e8a49ff3ff           call 0x7542a0
// 0081a2fc  50                   push eax
// 0081a2fd  8d442418             lea eax, [esp + 0x18]
// 0081a301  50                   push eax
// 0081a302  8bcd                 mov ecx, ebp
// 0081a304  e8c7f4efff           call 0x7197d0
// 0081a309  85ed                 test ebp, ebp
// 0081a30b  7403                 je 0x81a310
// 0081a30d  8b6d04               mov ebp, dword ptr [ebp + 4]
// 0081a310  6a00                 push 0
// 0081a312  8d4c2418             lea ecx, [esp + 0x18]
// 0081a316  51                   push ecx
// 0081a317  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0081a31b  56                   push esi
// 0081a31c  6a01                 push 1
// 0081a31e  55                   push ebp
// 0081a31f  83c174               add ecx, 0x74
// 0081a322  e8f964f7ff           call 0x790820
// 0081a327  5e                   pop esi
// 0081a328  f7d8                 neg eax
// 0081a32a  5d                   pop ebp
// 0081a32b  1bc0                 sbb eax, eax
// 0081a32d  5b                   pop ebx
// 0081a32e  40                   inc eax
// 0081a32f  5f                   pop edi
// 0081a330  83c414               add esp, 0x14
// 0081a333  c20800               ret 8
// 0081a336  33c0                 xor eax, eax
// 0081a338  5f                   pop edi
// 0081a339  83c414               add esp, 0x14
// 0081a33c  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTButtonTheme.cpp (function ?DrawWinThemeBackground@CXTButtonTheme@@MAEHPAUtagDRAWITEMSTRUCT@@PAVCXTButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTButtonTheme.cpp
