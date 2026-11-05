// from server: 100% by auto
// roc 2010-06 008a9040  unit: CXTCaptionButtonTheme  size: 319 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a9040
//
// 008a9040  83ec14               sub esp, 0x14
// 008a9043  8b01                 mov eax, dword ptr [ecx]
// 008a9045  8b5014               mov edx, dword ptr [eax + 0x14]
// 008a9048  57                   push edi
// 008a9049  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 008a904d  57                   push edi
// 008a904e  894c2408             mov dword ptr [esp + 8], ecx
// 008a9052  ffd2                 call edx
// 008a9054  85c0                 test eax, eax
// 008a9056  0f841a010000         je 0x8a9176
// 008a905c  53                   push ebx
// 008a905d  55                   push ebp
// 008a905e  56                   push esi
// 008a905f  8b742428             mov esi, dword ptr [esp + 0x28]
// 008a9063  8b4618               mov eax, dword ptr [esi + 0x18]
// 008a9066  50                   push eax
// 008a9067  e8003d0d00           call 0x97cd6c
// 008a906c  8d4e1c               lea ecx, [esi + 0x1c]
// 008a906f  51                   push ecx
// 008a9070  8d542418             lea edx, [esp + 0x18]
// 008a9074  52                   push edx
// 008a9075  8be8                 mov ebp, eax
// 008a9077  ff1548bc9e00         call dword ptr [0x9ebc48]
// 008a907d  8b4610               mov eax, dword ptr [esi + 0x10]
// 008a9080  8ad8                 mov bl, al
// 008a9082  c1e802               shr eax, 2
// 008a9085  2401                 and al, 1
// 008a9087  8bcf                 mov ecx, edi
// 008a9089  80e301               and bl, 1
// 008a908c  8844242c             mov byte ptr [esp + 0x2c], al
// 008a9090  be01000000           mov esi, 1
// 008a9095  e87607ffff           call 0x899810
// 008a909a  3c01                 cmp al, 1
// 008a909c  7505                 jne 0x8a90a3
// 008a909e  be05000000           mov esi, 5
// 008a90a3  83bfa000000000       cmp dword ptr [edi + 0xa0], 0
// 008a90aa  750b                 jne 0x8a90b7
// 008a90ac  ff1584bc9e00         call dword ptr [0x9ebc84]
// 008a90b2  3b4720               cmp eax, dword ptr [edi + 0x20]
// 008a90b5  7505                 jne 0x8a90bc
// 008a90b7  be02000000           mov esi, 2
// 008a90bc  84db                 test bl, bl
// 008a90be  7506                 jne 0x8a90c6
// 008a90c0  837f7c00             cmp dword ptr [edi + 0x7c], 0
// 008a90c4  7405                 je 0x8a90cb
// 008a90c6  be03000000           mov esi, 3
// 008a90cb  807c242c00           cmp byte ptr [esp + 0x2c], 0
// 008a90d0  7405                 je 0x8a90d7
// 008a90d2  be04000000           mov esi, 4
// 008a90d7  8b7f20               mov edi, dword ptr [edi + 0x20]
// 008a90da  85ed                 test ebp, ebp
// 008a90dc  7504                 jne 0x8a90e2
// 008a90de  33db                 xor ebx, ebx
// 008a90e0  eb03                 jmp 0x8a90e5
// 008a90e2  8b5d04               mov ebx, dword ptr [ebp + 4]
// 008a90e5  57                   push edi
// 008a90e6  ff154cba9e00         call dword ptr [0x9eba4c]
// 008a90ec  50                   push eax
// 008a90ed  e878ebefff           call 0x7a7c6a
// 008a90f2  8b4020               mov eax, dword ptr [eax + 0x20]
// 008a90f5  57                   push edi
// 008a90f6  53                   push ebx
// 008a90f7  6835010000           push 0x135
// 008a90fc  50                   push eax
// 008a90fd  ff1554ba9e00         call dword ptr [0x9eba54]
// 008a9103  85c0                 test eax, eax
// 008a9105  7427                 je 0x8a912e
// 008a9107  85ed                 test ebp, ebp
// 008a9109  7511                 jne 0x8a911c
// 008a910b  50                   push eax
// 008a910c  8d542418             lea edx, [esp + 0x18]
// 008a9110  33c9                 xor ecx, ecx
// 008a9112  52                   push edx
// 008a9113  51                   push ecx
// 008a9114  ff151cba9e00         call dword ptr [0x9eba1c]
// 008a911a  eb2d                 jmp 0x8a9149
// 008a911c  8b4d04               mov ecx, dword ptr [ebp + 4]
// 008a911f  50                   push eax
// 008a9120  8d542418             lea edx, [esp + 0x18]
// 008a9124  52                   push edx
// 008a9125  51                   push ecx
// 008a9126  ff151cba9e00         call dword ptr [0x9eba1c]
// 008a912c  eb1b                 jmp 0x8a9149
// 008a912e  e8eda9f3ff           call 0x7e3b20
// 008a9133  6a0f                 push 0xf
// 008a9135  8bc8                 mov ecx, eax
// 008a9137  e874a1f3ff           call 0x7e32b0
// 008a913c  50                   push eax
// 008a913d  8d442418             lea eax, [esp + 0x18]
// 008a9141  50                   push eax
// 008a9142  8bcd                 mov ecx, ebp
// 008a9144  e8f5f5efff           call 0x7a873e
// 008a9149  85ed                 test ebp, ebp
// 008a914b  7403                 je 0x8a9150
// 008a914d  8b6d04               mov ebp, dword ptr [ebp + 4]
// 008a9150  6a00                 push 0
// 008a9152  8d4c2418             lea ecx, [esp + 0x18]
// 008a9156  51                   push ecx
// 008a9157  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008a915b  56                   push esi
// 008a915c  6a01                 push 1
// 008a915e  55                   push ebp
// 008a915f  83c174               add ecx, 0x74
// 008a9162  e8d966f7ff           call 0x81f840
// 008a9167  5e                   pop esi
// 008a9168  f7d8                 neg eax
// 008a916a  5d                   pop ebp
// 008a916b  1bc0                 sbb eax, eax
// 008a916d  5b                   pop ebx
// 008a916e  40                   inc eax
// 008a916f  5f                   pop edi
// 008a9170  83c414               add esp, 0x14
// 008a9173  c20800               ret 8
// 008a9176  33c0                 xor eax, eax
// 008a9178  5f                   pop edi
// 008a9179  83c414               add esp, 0x14
// 008a917c  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTButtonTheme.cpp (function ?DrawWinThemeBackground@CXTButtonTheme@@MAEHPAUtagDRAWITEMSTRUCT@@PAVCXTButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTButtonTheme.cpp
