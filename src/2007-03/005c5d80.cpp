// from server: 100% by auto
// roc 2007-03 005c5d80  unit: seg_005c0000  size: 349 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c5d80
//
// 005c5d80  81ec2c030000         sub esp, 0x32c
// 005c5d86  53                   push ebx
// 005c5d87  8b9c2434030000       mov ebx, dword ptr [esp + 0x334]
// 005c5d8e  55                   push ebp
// 005c5d8f  56                   push esi
// 005c5d90  57                   push edi
// 005c5d91  8d44241c             lea eax, [esp + 0x1c]
// 005c5d95  50                   push eax
// 005c5d96  6a01                 push 1
// 005c5d98  53                   push ebx
// 005c5d99  e82248ffff           call 0x5ba5c0
// 005c5d9e  33ed                 xor ebp, ebp
// 005c5da0  55                   push ebp
// 005c5da1  6a02                 push 2
// 005c5da3  53                   push ebx
// 005c5da4  8bf0                 mov esi, eax
// 005c5da6  e81548ffff           call 0x5ba5c0
// 005c5dab  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 005c5daf  83c101               add ecx, 1
// 005c5db2  51                   push ecx
// 005c5db3  6a04                 push 4
// 005c5db5  53                   push ebx
// 005c5db6  8bf8                 mov edi, eax
// 005c5db8  8944243c             mov dword ptr [esp + 0x3c], eax
// 005c5dbc  e8af49ffff           call 0x5ba770
// 005c5dc1  83c424               add esp, 0x24
// 005c5dc4  803f5e               cmp byte ptr [edi], 0x5e
// 005c5dc7  89442414             mov dword ptr [esp + 0x14], eax
// 005c5dcb  7511                 jne 0x5c5dde
// 005c5dcd  83c701               add edi, 1
// 005c5dd0  897c2418             mov dword ptr [esp + 0x18], edi
// 005c5dd4  c744241001000000     mov dword ptr [esp + 0x10], 1
// 005c5ddc  eb04                 jmp 0x5c5de2
// 005c5dde  896c2410             mov dword ptr [esp + 0x10], ebp
// 005c5de2  8d942430010000       lea edx, [esp + 0x130]
// 005c5de9  52                   push edx
// 005c5dea  53                   push ebx
// 005c5deb  e8c041ffff           call 0x5b9fb0
// 005c5df0  8b442424             mov eax, dword ptr [esp + 0x24]
// 005c5df4  03c6                 add eax, esi
// 005c5df6  83c408               add esp, 8
// 005c5df9  396c2414             cmp dword ptr [esp + 0x14], ebp
// 005c5dfd  895c2428             mov dword ptr [esp + 0x28], ebx
// 005c5e01  89742420             mov dword ptr [esp + 0x20], esi
// 005c5e05  89442424             mov dword ptr [esp + 0x24], eax
// 005c5e09  0f8e96000000         jle 0x5c5ea5
// 005c5e0f  eb04                 jmp 0x5c5e15
// 005c5e11  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 005c5e15  57                   push edi
// 005c5e16  8d4c2424             lea ecx, [esp + 0x24]
// 005c5e1a  56                   push esi
// 005c5e1b  51                   push ecx
// 005c5e1c  c744243800000000     mov dword ptr [esp + 0x38], 0
// 005c5e24  e847f5ffff           call 0x5c5370
// 005c5e29  8bf8                 mov edi, eax
// 005c5e2b  83c40c               add esp, 0xc
// 005c5e2e  85ff                 test edi, edi
// 005c5e30  7420                 je 0x5c5e52
// 005c5e32  8d942430010000       lea edx, [esp + 0x130]
// 005c5e39  56                   push esi
// 005c5e3a  52                   push edx
// 005c5e3b  8d4c2428             lea ecx, [esp + 0x28]
// 005c5e3f  83c501               add ebp, 1
// 005c5e42  e819feffff           call 0x5c5c60
// 005c5e47  83c408               add esp, 8
// 005c5e4a  3bfe                 cmp edi, esi
// 005c5e4c  7604                 jbe 0x5c5e52
// 005c5e4e  8bf7                 mov esi, edi
// 005c5e50  eb3e                 jmp 0x5c5e90
// 005c5e52  8b442424             mov eax, dword ptr [esp + 0x24]
// 005c5e56  3bf0                 cmp esi, eax
// 005c5e58  734b                 jae 0x5c5ea5
// 005c5e5a  8d84243c030000       lea eax, [esp + 0x33c]
// 005c5e61  39842430010000       cmp dword ptr [esp + 0x130], eax
// 005c5e68  7210                 jb 0x5c5e7a
// 005c5e6a  8d8c2430010000       lea ecx, [esp + 0x130]
// 005c5e71  51                   push ecx
// 005c5e72  e8c93fffff           call 0x5b9e40
// 005c5e77  83c404               add esp, 4
// 005c5e7a  8a16                 mov dl, byte ptr [esi]
// 005c5e7c  8b842430010000       mov eax, dword ptr [esp + 0x130]
// 005c5e83  8810                 mov byte ptr [eax], dl
// 005c5e85  8384243001000001     add dword ptr [esp + 0x130], 1
// 005c5e8d  83c601               add esi, 1
// 005c5e90  837c241000           cmp dword ptr [esp + 0x10], 0
// 005c5e95  750a                 jne 0x5c5ea1
// 005c5e97  3b6c2414             cmp ebp, dword ptr [esp + 0x14]
// 005c5e9b  0f8c70ffffff         jl 0x5c5e11
// 005c5ea1  8b442424             mov eax, dword ptr [esp + 0x24]
// 005c5ea5  2bc6                 sub eax, esi
// 005c5ea7  50                   push eax
// 005c5ea8  8d8c2434010000       lea ecx, [esp + 0x134]
// 005c5eaf  56                   push esi
// 005c5eb0  51                   push ecx
// 005c5eb1  e8ca3fffff           call 0x5b9e80
// 005c5eb6  8d94243c010000       lea edx, [esp + 0x13c]
// 005c5ebd  52                   push edx
// 005c5ebe  e81d40ffff           call 0x5b9ee0
// 005c5ec3  55                   push ebp
// 005c5ec4  53                   push ebx
// 005c5ec5  e89631ffff           call 0x5b9060
// 005c5eca  83c418               add esp, 0x18
// 005c5ecd  5f                   pop edi
// 005c5ece  5e                   pop esi
// 005c5ecf  5d                   pop ebp
// 005c5ed0  b802000000           mov eax, 2
// 005c5ed5  5b                   pop ebx
// 005c5ed6  81c42c030000         add esp, 0x32c
// 005c5edc  c3                   ret 
// library lua-5.1.1/lstrlib.c (function _str_gsub)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lstrlib.c
