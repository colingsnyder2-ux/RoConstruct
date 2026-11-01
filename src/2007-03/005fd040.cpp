// from server: 100% by auto
// roc 2007-03 005fd040  unit: seg_005f0000  size: 328 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fd040
//
// 005fd040  51                   push ecx
// 005fd041  53                   push ebx
// 005fd042  55                   push ebp
// 005fd043  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 005fd047  56                   push esi
// 005fd048  8bf0                 mov esi, eax
// 005fd04a  837e0c00             cmp dword ptr [esi + 0xc], 0
// 005fd04e  57                   push edi
// 005fd04f  7404                 je 0x5fd055
// 005fd051  33ff                 xor edi, edi
// 005fd053  eb03                 jmp 0x5fd058
// 005fd055  8b7d30               mov edi, dword ptr [ebp + 0x30]
// 005fd058  837e1000             cmp dword ptr [esi + 0x10], 0
// 005fd05c  8b5d14               mov ebx, dword ptr [ebp + 0x14]
// 005fd05f  897c2418             mov dword ptr [esp + 0x18], edi
// 005fd063  7538                 jne 0x5fd09d
// 005fd065  8b4608               mov eax, dword ptr [esi + 8]
// 005fd068  8b16                 mov edx, dword ptr [esi]
// 005fd06a  50                   push eax
// 005fd06b  8b4604               mov eax, dword ptr [esi + 4]
// 005fd06e  6a04                 push 4
// 005fd070  8d4c2420             lea ecx, [esp + 0x20]
// 005fd074  51                   push ecx
// 005fd075  52                   push edx
// 005fd076  ffd0                 call eax
// 005fd078  83c410               add esp, 0x10
// 005fd07b  85c0                 test eax, eax
// 005fd07d  894610               mov dword ptr [esi + 0x10], eax
// 005fd080  751b                 jne 0x5fd09d
// 005fd082  8b4e08               mov ecx, dword ptr [esi + 8]
// 005fd085  8b06                 mov eax, dword ptr [esi]
// 005fd087  51                   push ecx
// 005fd088  8b4e04               mov ecx, dword ptr [esi + 4]
// 005fd08b  8d14bd00000000       lea edx, [edi*4]
// 005fd092  52                   push edx
// 005fd093  53                   push ebx
// 005fd094  50                   push eax
// 005fd095  ffd1                 call ecx
// 005fd097  83c410               add esp, 0x10
// 005fd09a  894610               mov dword ptr [esi + 0x10], eax
// 005fd09d  837e0c00             cmp dword ptr [esi + 0xc], 0
// 005fd0a1  7404                 je 0x5fd0a7
// 005fd0a3  33db                 xor ebx, ebx
// 005fd0a5  eb03                 jmp 0x5fd0aa
// 005fd0a7  8b5d38               mov ebx, dword ptr [ebp + 0x38]
// 005fd0aa  837e1000             cmp dword ptr [esi + 0x10], 0
// 005fd0ae  895c2418             mov dword ptr [esp + 0x18], ebx
// 005fd0b2  7519                 jne 0x5fd0cd
// 005fd0b4  8b5608               mov edx, dword ptr [esi + 8]
// 005fd0b7  8b0e                 mov ecx, dword ptr [esi]
// 005fd0b9  52                   push edx
// 005fd0ba  8b5604               mov edx, dword ptr [esi + 4]
// 005fd0bd  6a04                 push 4
// 005fd0bf  8d442420             lea eax, [esp + 0x20]
// 005fd0c3  50                   push eax
// 005fd0c4  51                   push ecx
// 005fd0c5  ffd2                 call edx
// 005fd0c7  83c410               add esp, 0x10
// 005fd0ca  894610               mov dword ptr [esi + 0x10], eax
// 005fd0cd  85db                 test ebx, ebx
// 005fd0cf  7e69                 jle 0x5fd13a
// 005fd0d1  33ff                 xor edi, edi
// 005fd0d3  8b4518               mov eax, dword ptr [ebp + 0x18]
// 005fd0d6  8b0407               mov eax, dword ptr [edi + eax]
// 005fd0d9  e892fdffff           call 0x5fce70
// 005fd0de  837e1000             cmp dword ptr [esi + 0x10], 0
// 005fd0e2  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 005fd0e5  8b540f04             mov edx, dword ptr [edi + ecx + 4]
// 005fd0e9  89542418             mov dword ptr [esp + 0x18], edx
// 005fd0ed  7519                 jne 0x5fd108
// 005fd0ef  8b4608               mov eax, dword ptr [esi + 8]
// 005fd0f2  8b16                 mov edx, dword ptr [esi]
// 005fd0f4  50                   push eax
// 005fd0f5  8b4604               mov eax, dword ptr [esi + 4]
// 005fd0f8  6a04                 push 4
// 005fd0fa  8d4c2420             lea ecx, [esp + 0x20]
// 005fd0fe  51                   push ecx
// 005fd0ff  52                   push edx
// 005fd100  ffd0                 call eax
// 005fd102  83c410               add esp, 0x10
// 005fd105  894610               mov dword ptr [esi + 0x10], eax
// 005fd108  837e1000             cmp dword ptr [esi + 0x10], 0
// 005fd10c  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 005fd10f  8b540f08             mov edx, dword ptr [edi + ecx + 8]
// 005fd113  89542410             mov dword ptr [esp + 0x10], edx
// 005fd117  7519                 jne 0x5fd132
// 005fd119  8b4608               mov eax, dword ptr [esi + 8]
// 005fd11c  8b16                 mov edx, dword ptr [esi]
// 005fd11e  50                   push eax
// 005fd11f  8b4604               mov eax, dword ptr [esi + 4]
// 005fd122  6a04                 push 4
// 005fd124  8d4c2418             lea ecx, [esp + 0x18]
// 005fd128  51                   push ecx
// 005fd129  52                   push edx
// 005fd12a  ffd0                 call eax
// 005fd12c  83c410               add esp, 0x10
// 005fd12f  894610               mov dword ptr [esi + 0x10], eax
// 005fd132  83c70c               add edi, 0xc
// 005fd135  83eb01               sub ebx, 1
// 005fd138  7599                 jne 0x5fd0d3
// 005fd13a  837e0c00             cmp dword ptr [esi + 0xc], 0
// 005fd13e  7404                 je 0x5fd144
// 005fd140  33db                 xor ebx, ebx
// 005fd142  eb03                 jmp 0x5fd147
// 005fd144  8b5d24               mov ebx, dword ptr [ebp + 0x24]
// 005fd147  837e1000             cmp dword ptr [esi + 0x10], 0
// 005fd14b  895c2418             mov dword ptr [esp + 0x18], ebx
// 005fd14f  7519                 jne 0x5fd16a
// 005fd151  8b4e08               mov ecx, dword ptr [esi + 8]
// 005fd154  8b06                 mov eax, dword ptr [esi]
// 005fd156  51                   push ecx
// 005fd157  8b4e04               mov ecx, dword ptr [esi + 4]
// 005fd15a  6a04                 push 4
// 005fd15c  8d542420             lea edx, [esp + 0x20]
// 005fd160  52                   push edx
// 005fd161  50                   push eax
// 005fd162  ffd1                 call ecx
// 005fd164  83c410               add esp, 0x10
// 005fd167  894610               mov dword ptr [esi + 0x10], eax
// 005fd16a  33ff                 xor edi, edi
// 005fd16c  85db                 test ebx, ebx
// 005fd16e  7e12                 jle 0x5fd182
// 005fd170  8b551c               mov edx, dword ptr [ebp + 0x1c]
// 005fd173  8b04ba               mov eax, dword ptr [edx + edi*4]
// 005fd176  e8f5fcffff           call 0x5fce70
// 005fd17b  83c701               add edi, 1
// 005fd17e  3bfb                 cmp edi, ebx
// 005fd180  7cee                 jl 0x5fd170
// 005fd182  5f                   pop edi
// 005fd183  5e                   pop esi
// 005fd184  5d                   pop ebp
// 005fd185  5b                   pop ebx
// 005fd186  59                   pop ecx
// 005fd187  c3                   ret 
// library lua-5.1.1/ldump.c (function _DumpDebug)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ldump.c
