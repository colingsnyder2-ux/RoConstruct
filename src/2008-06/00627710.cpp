// from server: 100% by auto
// roc 2008-06 00627710  unit: seg_00620000  size: 343 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00627710
//
// 00627710  81ec2c030000         sub esp, 0x32c
// 00627716  53                   push ebx
// 00627717  8b9c2434030000       mov ebx, dword ptr [esp + 0x334]
// 0062771e  55                   push ebp
// 0062771f  56                   push esi
// 00627720  57                   push edi
// 00627721  8d44241c             lea eax, [esp + 0x1c]
// 00627725  50                   push eax
// 00627726  6a01                 push 1
// 00627728  53                   push ebx
// 00627729  e8929ffeff           call 0x6116c0
// 0062772e  33ed                 xor ebp, ebp
// 00627730  55                   push ebp
// 00627731  6a02                 push 2
// 00627733  53                   push ebx
// 00627734  8bf0                 mov esi, eax
// 00627736  e8859ffeff           call 0x6116c0
// 0062773b  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0062773f  41                   inc ecx
// 00627740  51                   push ecx
// 00627741  6a04                 push 4
// 00627743  53                   push ebx
// 00627744  8bf8                 mov edi, eax
// 00627746  8944243c             mov dword ptr [esp + 0x3c], eax
// 0062774a  e821a1feff           call 0x611870
// 0062774f  83c424               add esp, 0x24
// 00627752  803f5e               cmp byte ptr [edi], 0x5e
// 00627755  89442414             mov dword ptr [esp + 0x14], eax
// 00627759  750f                 jne 0x62776a
// 0062775b  47                   inc edi
// 0062775c  897c2418             mov dword ptr [esp + 0x18], edi
// 00627760  c744241001000000     mov dword ptr [esp + 0x10], 1
// 00627768  eb04                 jmp 0x62776e
// 0062776a  896c2410             mov dword ptr [esp + 0x10], ebp
// 0062776e  8d942430010000       lea edx, [esp + 0x130]
// 00627775  52                   push edx
// 00627776  53                   push ebx
// 00627777  e82499feff           call 0x6110a0
// 0062777c  8b442424             mov eax, dword ptr [esp + 0x24]
// 00627780  03c6                 add eax, esi
// 00627782  83c408               add esp, 8
// 00627785  396c2414             cmp dword ptr [esp + 0x14], ebp
// 00627789  895c2428             mov dword ptr [esp + 0x28], ebx
// 0062778d  89742420             mov dword ptr [esp + 0x20], esi
// 00627791  89442424             mov dword ptr [esp + 0x24], eax
// 00627795  0f8e94000000         jle 0x62782f
// 0062779b  eb07                 jmp 0x6277a4
// 0062779d  8d4900               lea ecx, [ecx]
// 006277a0  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 006277a4  57                   push edi
// 006277a5  8d4c2424             lea ecx, [esp + 0x24]
// 006277a9  56                   push esi
// 006277aa  51                   push ecx
// 006277ab  c744243800000000     mov dword ptr [esp + 0x38], 0
// 006277b3  e868f5ffff           call 0x626d20
// 006277b8  8bf8                 mov edi, eax
// 006277ba  83c40c               add esp, 0xc
// 006277bd  85ff                 test edi, edi
// 006277bf  741e                 je 0x6277df
// 006277c1  8d942430010000       lea edx, [esp + 0x130]
// 006277c8  56                   push esi
// 006277c9  52                   push edx
// 006277ca  8d4c2428             lea ecx, [esp + 0x28]
// 006277ce  45                   inc ebp
// 006277cf  e81cfeffff           call 0x6275f0
// 006277d4  83c408               add esp, 8
// 006277d7  3bfe                 cmp edi, esi
// 006277d9  7604                 jbe 0x6277df
// 006277db  8bf7                 mov esi, edi
// 006277dd  eb3b                 jmp 0x62781a
// 006277df  8b442424             mov eax, dword ptr [esp + 0x24]
// 006277e3  3bf0                 cmp esi, eax
// 006277e5  7348                 jae 0x62782f
// 006277e7  8d84243c030000       lea eax, [esp + 0x33c]
// 006277ee  39842430010000       cmp dword ptr [esp + 0x130], eax
// 006277f5  7210                 jb 0x627807
// 006277f7  8d8c2430010000       lea ecx, [esp + 0x130]
// 006277fe  51                   push ecx
// 006277ff  e83c97feff           call 0x610f40
// 00627804  83c404               add esp, 4
// 00627807  8a16                 mov dl, byte ptr [esi]
// 00627809  8b842430010000       mov eax, dword ptr [esp + 0x130]
// 00627810  8810                 mov byte ptr [eax], dl
// 00627812  ff842430010000       inc dword ptr [esp + 0x130]
// 00627819  46                   inc esi
// 0062781a  837c241000           cmp dword ptr [esp + 0x10], 0
// 0062781f  750a                 jne 0x62782b
// 00627821  3b6c2414             cmp ebp, dword ptr [esp + 0x14]
// 00627825  0f8c75ffffff         jl 0x6277a0
// 0062782b  8b442424             mov eax, dword ptr [esp + 0x24]
// 0062782f  2bc6                 sub eax, esi
// 00627831  50                   push eax
// 00627832  8d8c2434010000       lea ecx, [esp + 0x134]
// 00627839  56                   push esi
// 0062783a  51                   push ecx
// 0062783b  e84097feff           call 0x610f80
// 00627840  8d94243c010000       lea edx, [esp + 0x13c]
// 00627847  52                   push edx
// 00627848  e89397feff           call 0x610fe0
// 0062784d  55                   push ebp
// 0062784e  53                   push ebx
// 0062784f  e8cca9feff           call 0x612220
// 00627854  83c418               add esp, 0x18
// 00627857  5f                   pop edi
// 00627858  5e                   pop esi
// 00627859  5d                   pop ebp
// 0062785a  b802000000           mov eax, 2
// 0062785f  5b                   pop ebx
// 00627860  81c42c030000         add esp, 0x32c
// 00627866  c3                   ret 
// library lua-5.1.2/lstrlib.c (function _str_gsub)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 lstrlib.c
