// from server: 100% by auto
// roc 2007-08 005cafb0  unit: seg_005c0000  size: 349 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005cafb0
//
// 005cafb0  81ec2c030000         sub esp, 0x32c
// 005cafb6  53                   push ebx
// 005cafb7  8b9c2434030000       mov ebx, dword ptr [esp + 0x334]
// 005cafbe  55                   push ebp
// 005cafbf  56                   push esi
// 005cafc0  57                   push edi
// 005cafc1  8d44241c             lea eax, [esp + 0x1c]
// 005cafc5  50                   push eax
// 005cafc6  6a01                 push 1
// 005cafc8  53                   push ebx
// 005cafc9  e88243ffff           call 0x5bf350
// 005cafce  33ed                 xor ebp, ebp
// 005cafd0  55                   push ebp
// 005cafd1  6a02                 push 2
// 005cafd3  53                   push ebx
// 005cafd4  8bf0                 mov esi, eax
// 005cafd6  e87543ffff           call 0x5bf350
// 005cafdb  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 005cafdf  83c101               add ecx, 1
// 005cafe2  51                   push ecx
// 005cafe3  6a04                 push 4
// 005cafe5  53                   push ebx
// 005cafe6  8bf8                 mov edi, eax
// 005cafe8  8944243c             mov dword ptr [esp + 0x3c], eax
// 005cafec  e80f45ffff           call 0x5bf500
// 005caff1  83c424               add esp, 0x24
// 005caff4  803f5e               cmp byte ptr [edi], 0x5e
// 005caff7  89442414             mov dword ptr [esp + 0x14], eax
// 005caffb  7511                 jne 0x5cb00e
// 005caffd  83c701               add edi, 1
// 005cb000  897c2418             mov dword ptr [esp + 0x18], edi
// 005cb004  c744241001000000     mov dword ptr [esp + 0x10], 1
// 005cb00c  eb04                 jmp 0x5cb012
// 005cb00e  896c2410             mov dword ptr [esp + 0x10], ebp
// 005cb012  8d942430010000       lea edx, [esp + 0x130]
// 005cb019  52                   push edx
// 005cb01a  53                   push ebx
// 005cb01b  e8203dffff           call 0x5bed40
// 005cb020  8b442424             mov eax, dword ptr [esp + 0x24]
// 005cb024  03c6                 add eax, esi
// 005cb026  83c408               add esp, 8
// 005cb029  396c2414             cmp dword ptr [esp + 0x14], ebp
// 005cb02d  895c2428             mov dword ptr [esp + 0x28], ebx
// 005cb031  89742420             mov dword ptr [esp + 0x20], esi
// 005cb035  89442424             mov dword ptr [esp + 0x24], eax
// 005cb039  0f8e96000000         jle 0x5cb0d5
// 005cb03f  eb04                 jmp 0x5cb045
// 005cb041  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 005cb045  57                   push edi
// 005cb046  8d4c2424             lea ecx, [esp + 0x24]
// 005cb04a  56                   push esi
// 005cb04b  51                   push ecx
// 005cb04c  c744243800000000     mov dword ptr [esp + 0x38], 0
// 005cb054  e847f5ffff           call 0x5ca5a0
// 005cb059  8bf8                 mov edi, eax
// 005cb05b  83c40c               add esp, 0xc
// 005cb05e  85ff                 test edi, edi
// 005cb060  7420                 je 0x5cb082
// 005cb062  8d942430010000       lea edx, [esp + 0x130]
// 005cb069  56                   push esi
// 005cb06a  52                   push edx
// 005cb06b  8d4c2428             lea ecx, [esp + 0x28]
// 005cb06f  83c501               add ebp, 1
// 005cb072  e819feffff           call 0x5cae90
// 005cb077  83c408               add esp, 8
// 005cb07a  3bfe                 cmp edi, esi
// 005cb07c  7604                 jbe 0x5cb082
// 005cb07e  8bf7                 mov esi, edi
// 005cb080  eb3e                 jmp 0x5cb0c0
// 005cb082  8b442424             mov eax, dword ptr [esp + 0x24]
// 005cb086  3bf0                 cmp esi, eax
// 005cb088  734b                 jae 0x5cb0d5
// 005cb08a  8d84243c030000       lea eax, [esp + 0x33c]
// 005cb091  39842430010000       cmp dword ptr [esp + 0x130], eax
// 005cb098  7210                 jb 0x5cb0aa
// 005cb09a  8d8c2430010000       lea ecx, [esp + 0x130]
// 005cb0a1  51                   push ecx
// 005cb0a2  e8293bffff           call 0x5bebd0
// 005cb0a7  83c404               add esp, 4
// 005cb0aa  8a16                 mov dl, byte ptr [esi]
// 005cb0ac  8b842430010000       mov eax, dword ptr [esp + 0x130]
// 005cb0b3  8810                 mov byte ptr [eax], dl
// 005cb0b5  8384243001000001     add dword ptr [esp + 0x130], 1
// 005cb0bd  83c601               add esi, 1
// 005cb0c0  837c241000           cmp dword ptr [esp + 0x10], 0
// 005cb0c5  750a                 jne 0x5cb0d1
// 005cb0c7  3b6c2414             cmp ebp, dword ptr [esp + 0x14]
// 005cb0cb  0f8c70ffffff         jl 0x5cb041
// 005cb0d1  8b442424             mov eax, dword ptr [esp + 0x24]
// 005cb0d5  2bc6                 sub eax, esi
// 005cb0d7  50                   push eax
// 005cb0d8  8d8c2434010000       lea ecx, [esp + 0x134]
// 005cb0df  56                   push esi
// 005cb0e0  51                   push ecx
// 005cb0e1  e82a3bffff           call 0x5bec10
// 005cb0e6  8d94243c010000       lea edx, [esp + 0x13c]
// 005cb0ed  52                   push edx
// 005cb0ee  e87d3bffff           call 0x5bec70
// 005cb0f3  55                   push ebp
// 005cb0f4  53                   push ebx
// 005cb0f5  e8962affff           call 0x5bdb90
// 005cb0fa  83c418               add esp, 0x18
// 005cb0fd  5f                   pop edi
// 005cb0fe  5e                   pop esi
// 005cb0ff  5d                   pop ebp
// 005cb100  b802000000           mov eax, 2
// 005cb105  5b                   pop ebx
// 005cb106  81c42c030000         add esp, 0x32c
// 005cb10c  c3                   ret 
// library lua-5.1.2/lstrlib.c (function _str_gsub)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 lstrlib.c
