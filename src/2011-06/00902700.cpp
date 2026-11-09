// from server: 100% by auto
// roc 2011-06 00902700  unit: CXTCaptionButtonTheme  size: 319 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00902700
//
// 00902700  83ec14               sub esp, 0x14
// 00902703  8b01                 mov eax, dword ptr [ecx]
// 00902705  8b5014               mov edx, dword ptr [eax + 0x14]
// 00902708  57                   push edi
// 00902709  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0090270d  57                   push edi
// 0090270e  894c2408             mov dword ptr [esp + 8], ecx
// 00902712  ffd2                 call edx
// 00902714  85c0                 test eax, eax
// 00902716  0f841a010000         je 0x902836
// 0090271c  53                   push ebx
// 0090271d  55                   push ebp
// 0090271e  56                   push esi
// 0090271f  8b742428             mov esi, dword ptr [esp + 0x28]
// 00902723  8b4618               mov eax, dword ptr [esi + 0x18]
// 00902726  50                   push eax
// 00902727  e88c9e0c00           call 0x9cc5b8
// 0090272c  8d4e1c               lea ecx, [esi + 0x1c]
// 0090272f  51                   push ecx
// 00902730  8d542418             lea edx, [esp + 0x18]
// 00902734  52                   push edx
// 00902735  8be8                 mov ebp, eax
// 00902737  ff15681ca400         call dword ptr [0xa41c68]
// 0090273d  8b4610               mov eax, dword ptr [esi + 0x10]
// 00902740  8ad8                 mov bl, al
// 00902742  c1e802               shr eax, 2
// 00902745  2401                 and al, 1
// 00902747  8bcf                 mov ecx, edi
// 00902749  80e301               and bl, 1
// 0090274c  8844242c             mov byte ptr [esp + 0x2c], al
// 00902750  be01000000           mov esi, 1
// 00902755  e816fcfeff           call 0x8f2370
// 0090275a  3c01                 cmp al, 1
// 0090275c  7505                 jne 0x902763
// 0090275e  be05000000           mov esi, 5
// 00902763  83bfa000000000       cmp dword ptr [edi + 0xa0], 0
// 0090276a  750b                 jne 0x902777
// 0090276c  ff15381ba400         call dword ptr [0xa41b38]
// 00902772  3b4720               cmp eax, dword ptr [edi + 0x20]
// 00902775  7505                 jne 0x90277c
// 00902777  be02000000           mov esi, 2
// 0090277c  84db                 test bl, bl
// 0090277e  7506                 jne 0x902786
// 00902780  837f7c00             cmp dword ptr [edi + 0x7c], 0
// 00902784  7405                 je 0x90278b
// 00902786  be03000000           mov esi, 3
// 0090278b  807c242c00           cmp byte ptr [esp + 0x2c], 0
// 00902790  7405                 je 0x902797
// 00902792  be04000000           mov esi, 4
// 00902797  8b7f20               mov edi, dword ptr [edi + 0x20]
// 0090279a  85ed                 test ebp, ebp
// 0090279c  7504                 jne 0x9027a2
// 0090279e  33db                 xor ebx, ebx
// 009027a0  eb03                 jmp 0x9027a5
// 009027a2  8b5d04               mov ebx, dword ptr [ebp + 4]
// 009027a5  57                   push edi
// 009027a6  ff15b819a400         call dword ptr [0xa419b8]
// 009027ac  50                   push eax
// 009027ad  e8767bf0ff           call 0x80a328
// 009027b2  8b4020               mov eax, dword ptr [eax + 0x20]
// 009027b5  57                   push edi
// 009027b6  53                   push ebx
// 009027b7  6835010000           push 0x135
// 009027bc  50                   push eax
// 009027bd  ff15c019a400         call dword ptr [0xa419c0]
// 009027c3  85c0                 test eax, eax
// 009027c5  7427                 je 0x9027ee
// 009027c7  85ed                 test ebp, ebp
// 009027c9  7511                 jne 0x9027dc
// 009027cb  50                   push eax
// 009027cc  8d542418             lea edx, [esp + 0x18]
// 009027d0  33c9                 xor ecx, ecx
// 009027d2  52                   push edx
// 009027d3  51                   push ecx
// 009027d4  ff15e81ba400         call dword ptr [0xa41be8]
// 009027da  eb2d                 jmp 0x902809
// 009027dc  8b4d04               mov ecx, dword ptr [ebp + 4]
// 009027df  50                   push eax
// 009027e0  8d542418             lea edx, [esp + 0x18]
// 009027e4  52                   push edx
// 009027e5  51                   push ecx
// 009027e6  ff15e81ba400         call dword ptr [0xa41be8]
// 009027ec  eb1b                 jmp 0x902809
// 009027ee  e8ed2bf4ff           call 0x8453e0
// 009027f3  6a0f                 push 0xf
// 009027f5  8bc8                 mov ecx, eax
// 009027f7  e8b423f4ff           call 0x844bb0
// 009027fc  50                   push eax
// 009027fd  8d442418             lea eax, [esp + 0x18]
// 00902801  50                   push eax
// 00902802  8bcd                 mov ecx, ebp
// 00902804  e81786f0ff           call 0x80ae20
// 00902809  85ed                 test ebp, ebp
// 0090280b  7403                 je 0x902810
// 0090280d  8b6d04               mov ebp, dword ptr [ebp + 4]
// 00902810  6a00                 push 0
// 00902812  8d4c2418             lea ecx, [esp + 0x18]
// 00902816  51                   push ecx
// 00902817  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0090281b  56                   push esi
// 0090281c  6a01                 push 1
// 0090281e  55                   push ebp
// 0090281f  83c174               add ecx, 0x74
// 00902822  e8d9a7f7ff           call 0x87d000
// 00902827  5e                   pop esi
// 00902828  f7d8                 neg eax
// 0090282a  5d                   pop ebp
// 0090282b  1bc0                 sbb eax, eax
// 0090282d  5b                   pop ebx
// 0090282e  40                   inc eax
// 0090282f  5f                   pop edi
// 00902830  83c414               add esp, 0x14
// 00902833  c20800               ret 8
// 00902836  33c0                 xor eax, eax
// 00902838  5f                   pop edi
// 00902839  83c414               add esp, 0x14
// 0090283c  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTButtonTheme.cpp (function ?DrawWinThemeBackground@CXTButtonTheme@@MAEHPAUtagDRAWITEMSTRUCT@@PAVCXTButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTButtonTheme.cpp
