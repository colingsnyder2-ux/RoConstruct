// from server: 100% by auto
// roc 2009-12 0044d2a0  unit: CRbxPlayDocTemplate  size: 775 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0044d2a0
//
// 0044d2a0  55                   push ebp
// 0044d2a1  8d6c2494             lea ebp, [esp - 0x6c]
// 0044d2a5  81ec24010000         sub esp, 0x124
// 0044d2ab  53                   push ebx
// 0044d2ac  8b5d78               mov ebx, dword ptr [ebp + 0x78]
// 0044d2af  56                   push esi
// 0044d2b0  57                   push edi
// 0044d2b1  c7456800000000       mov dword ptr [ebp + 0x68], 0
// 0044d2b8  85db                 test ebx, ebx
// 0044d2ba  0f84d3020000         je 0x44d593
// 0044d2c0  8b7d74               mov edi, dword ptr [ebp + 0x74]
// 0044d2c3  8b07                 mov eax, dword ptr [edi]
// 0044d2c5  3b0540179f00         cmp eax, dword ptr [0x9f1740]
// 0044d2cb  7525                 jne 0x44d2f2
// 0044d2cd  8b4f04               mov ecx, dword ptr [edi + 4]
// 0044d2d0  3b0d44179f00         cmp ecx, dword ptr [0x9f1744]
// 0044d2d6  751a                 jne 0x44d2f2
// 0044d2d8  8b5708               mov edx, dword ptr [edi + 8]
// 0044d2db  3b1548179f00         cmp edx, dword ptr [0x9f1748]
// 0044d2e1  750f                 jne 0x44d2f2
// 0044d2e3  8b470c               mov eax, dword ptr [edi + 0xc]
// 0044d2e6  3b054c179f00         cmp eax, dword ptr [0x9f174c]
// 0044d2ec  0f84a1020000         je 0x44d593
// 0044d2f2  8d4d68               lea ecx, [ebp + 0x68]
// 0044d2f5  51                   push ecx
// 0044d2f6  680cb49a00           push 0x9ab40c
// 0044d2fb  6a01                 push 1
// 0044d2fd  6a00                 push 0
// 0044d2ff  6810179f00           push 0x9f1710
// 0044d304  ff15a4e09800         call dword ptr [0x98e0a4]
// 0044d30a  85c0                 test eax, eax
// 0044d30c  7d27                 jge 0x44d335
// 0044d30e  8b4568               mov eax, dword ptr [ebp + 0x68]
// 0044d311  85c0                 test eax, eax
// 0044d313  0f847a020000         je 0x44d593
// 0044d319  8b10                 mov edx, dword ptr [eax]
// 0044d31b  50                   push eax
// 0044d31c  8b4208               mov eax, dword ptr [edx + 8]
// 0044d31f  ffd0                 call eax
// 0044d321  33c0                 xor eax, eax
// 0044d323  8da53cffffff         lea esp, [ebp - 0xc4]
// 0044d329  5f                   pop edi
// 0044d32a  5e                   pop esi
// 0044d32b  5b                   pop ebx
// 0044d32c  83c56c               add ebp, 0x6c
// 0044d32f  8be5                 mov esp, ebp
// 0044d331  5d                   pop ebp
// 0044d332  c20c00               ret 0xc
// 0044d335  833b00               cmp dword ptr [ebx], 0
// 0044d338  747c                 je 0x44d3b6
// 0044d33a  837d7c00             cmp dword ptr [ebp + 0x7c], 0
// 0044d33e  8b4304               mov eax, dword ptr [ebx + 4]
// 0044d341  8b08                 mov ecx, dword ptr [eax]
// 0044d343  894d48               mov dword ptr [ebp + 0x48], ecx
// 0044d346  8b5004               mov edx, dword ptr [eax + 4]
// 0044d349  89554c               mov dword ptr [ebp + 0x4c], edx
// 0044d34c  8b4808               mov ecx, dword ptr [eax + 8]
// 0044d34f  894d50               mov dword ptr [ebp + 0x50], ecx
// 0044d352  8b500c               mov edx, dword ptr [eax + 0xc]
// 0044d355  8b4568               mov eax, dword ptr [ebp + 0x68]
// 0044d358  895554               mov dword ptr [ebp + 0x54], edx
// 0044d35b  8b08                 mov ecx, dword ptr [eax]
// 0044d35d  8d5548               lea edx, [ebp + 0x48]
// 0044d360  52                   push edx
// 0044d361  6a01                 push 1
// 0044d363  57                   push edi
// 0044d364  50                   push eax
// 0044d365  7438                 je 0x44d39f
// 0044d367  833b01               cmp dword ptr [ebx], 1
// 0044d36a  7505                 jne 0x44d371
// 0044d36c  8b4114               mov eax, dword ptr [ecx + 0x14]
// 0044d36f  eb03                 jmp 0x44d374
// 0044d371  8b411c               mov eax, dword ptr [ecx + 0x1c]
// 0044d374  ffd0                 call eax
// 0044d376  8bf0                 mov esi, eax
// 0044d378  85f6                 test esi, esi
// 0044d37a  7d32                 jge 0x44d3ae
// 0044d37c  8b4568               mov eax, dword ptr [ebp + 0x68]
// 0044d37f  85c0                 test eax, eax
// 0044d381  7408                 je 0x44d38b
// 0044d383  8b08                 mov ecx, dword ptr [eax]
// 0044d385  8b5108               mov edx, dword ptr [ecx + 8]
// 0044d388  50                   push eax
// 0044d389  ffd2                 call edx
// 0044d38b  8bc6                 mov eax, esi
// 0044d38d  8da53cffffff         lea esp, [ebp - 0xc4]
// 0044d393  5f                   pop edi
// 0044d394  5e                   pop esi
// 0044d395  5b                   pop ebx
// 0044d396  83c56c               add ebp, 0x6c
// 0044d399  8be5                 mov esp, ebp
// 0044d39b  5d                   pop ebp
// 0044d39c  c20c00               ret 0xc
// 0044d39f  833b01               cmp dword ptr [ebx], 1
// 0044d3a2  7505                 jne 0x44d3a9
// 0044d3a4  8b4118               mov eax, dword ptr [ecx + 0x18]
// 0044d3a7  eb03                 jmp 0x44d3ac
// 0044d3a9  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0044d3ac  ffd0                 call eax
// 0044d3ae  83c308               add ebx, 8
// 0044d3b1  833b00               cmp dword ptr [ebx], 0
// 0044d3b4  7584                 jne 0x44d33a
// 0044d3b6  837d7c00             cmp dword ptr [ebp + 0x7c], 0
// 0044d3ba  0f85c4010000         jne 0x44d584
// 0044d3c0  6a40                 push 0x40
// 0044d3c2  8d8548ffffff         lea eax, [ebp - 0xb8]
// 0044d3c8  50                   push eax
// 0044d3c9  57                   push edi
// 0044d3ca  ff15b4e09800         call dword ptr [0x98e0b4]
// 0044d3d0  8d8d48ffffff         lea ecx, [ebp - 0xb8]
// 0044d3d6  51                   push ecx
// 0044d3d7  c7457800000000       mov dword ptr [ebp + 0x78], 0
// 0044d3de  ff1538b29800         call dword ptr [0x98b238]
// 0044d3e4  40                   inc eax
// 0044d3e5  6a02                 push 2
// 0044d3e7  50                   push eax
// 0044d3e8  8d557c               lea edx, [ebp + 0x7c]
// 0044d3eb  52                   push edx
// 0044d3ec  89457c               mov dword ptr [ebp + 0x7c], eax
// 0044d3ef  e88c56fbff           call 0x402a80
// 0044d3f4  83c40c               add esp, 0xc
// 0044d3f7  85c0                 test eax, eax
// 0044d3f9  0f8c7d010000         jl 0x44d57c
// 0044d3ff  8b757c               mov esi, dword ptr [ebp + 0x7c]
// 0044d402  81fe00040000         cmp esi, 0x400
// 0044d408  7f18                 jg 0x44d422
// 0044d40a  56                   push esi
// 0044d40b  e8e066fbff           call 0x403af0
// 0044d410  83c404               add esp, 4
// 0044d413  84c0                 test al, al
// 0044d415  740b                 je 0x44d422
// 0044d417  8bc6                 mov eax, esi
// 0044d419  e822763a00           call 0x7f4a40
// 0044d41e  8bc4                 mov eax, esp
// 0044d420  eb09                 jmp 0x44d42b
// 0044d422  56                   push esi
// 0044d423  8d4d78               lea ecx, [ebp + 0x78]
// 0044d426  e8656cfbff           call 0x404090
// 0044d42b  6a03                 push 3
// 0044d42d  56                   push esi
// 0044d42e  8d8d48ffffff         lea ecx, [ebp - 0xb8]
// 0044d434  51                   push ecx
// 0044d435  50                   push eax
// 0044d436  e8d556fbff           call 0x402b10
// 0044d43b  8bf0                 mov esi, eax
// 0044d43d  85f6                 test esi, esi
// 0044d43f  0f8437010000         je 0x44d57c
// 0044d445  6804b49a00           push 0x9ab404
// 0044d44a  8d55c8               lea edx, [ebp - 0x38]
// 0044d44d  6880000000           push 0x80
// 0044d452  52                   push edx
// 0044d453  e8f8d9ffff           call 0x44ae50
// 0044d458  56                   push esi
// 0044d459  8d45c8               lea eax, [ebp - 0x38]
// 0044d45c  6880000000           push 0x80
// 0044d461  50                   push eax
// 0044d462  e809daffff           call 0x44ae70
// 0044d467  68ecb39a00           push 0x9ab3ec
// 0044d46c  8d4dc8               lea ecx, [ebp - 0x38]
// 0044d46f  6880000000           push 0x80
// 0044d474  51                   push ecx
// 0044d475  e8f6d9ffff           call 0x44ae70
// 0044d47a  83c424               add esp, 0x24
// 0044d47d  6819000200           push 0x20019
// 0044d482  8d55c8               lea edx, [ebp - 0x38]
// 0044d485  33ff                 xor edi, edi
// 0044d487  52                   push edx
// 0044d488  6800000080           push 0x80000000
// 0044d48d  8d4d60               lea ecx, [ebp + 0x60]
// 0044d490  c7455800000080       mov dword ptr [ebp + 0x58], 0x80000000
// 0044d497  897d5c               mov dword ptr [ebp + 0x5c], edi
// 0044d49a  897d60               mov dword ptr [ebp + 0x60], edi
// 0044d49d  897d64               mov dword ptr [ebp + 0x64], edi
// 0044d4a0  897d7c               mov dword ptr [ebp + 0x7c], edi
// 0044d4a3  e8c859fbff           call 0x402e70
// 0044d4a8  85c0                 test eax, eax
// 0044d4aa  7537                 jne 0x44d4e3
// 0044d4ac  8b4d60               mov ecx, dword ptr [ebp + 0x60]
// 0044d4af  57                   push edi
// 0044d4b0  57                   push edi
// 0044d4b1  57                   push edi
// 0044d4b2  57                   push edi
// 0044d4b3  57                   push edi
// 0044d4b4  57                   push edi
// 0044d4b5  57                   push edi
// 0044d4b6  8d457c               lea eax, [ebp + 0x7c]
// 0044d4b9  50                   push eax
// 0044d4ba  57                   push edi
// 0044d4bb  57                   push edi
// 0044d4bc  57                   push edi
// 0044d4bd  51                   push ecx
// 0044d4be  ff1518b09800         call dword ptr [0x98b018]
// 0044d4c4  8d4d60               lea ecx, [ebp + 0x60]
// 0044d4c7  8bd8                 mov ebx, eax
// 0044d4c9  e87259fbff           call 0x402e40
// 0044d4ce  3bdf                 cmp ebx, edi
// 0044d4d0  7511                 jne 0x44d4e3
// 0044d4d2  397d7c               cmp dword ptr [ebp + 0x7c], edi
// 0044d4d5  750c                 jne 0x44d4e3
// 0044d4d7  8d55c8               lea edx, [ebp - 0x38]
// 0044d4da  52                   push edx
// 0044d4db  8d4d58               lea ecx, [ebp + 0x58]
// 0044d4de  e8fd58fbff           call 0x402de0
// 0044d4e3  6804b49a00           push 0x9ab404
// 0044d4e8  8d45c8               lea eax, [ebp - 0x38]
// 0044d4eb  6880000000           push 0x80
// 0044d4f0  50                   push eax
// 0044d4f1  e85ad9ffff           call 0x44ae50
// 0044d4f6  56                   push esi
// 0044d4f7  8d4dc8               lea ecx, [ebp - 0x38]
// 0044d4fa  6880000000           push 0x80
// 0044d4ff  51                   push ecx
// 0044d500  e86bd9ffff           call 0x44ae70
// 0044d505  68d4b39a00           push 0x9ab3d4
// 0044d50a  8d55c8               lea edx, [ebp - 0x38]
// 0044d50d  6880000000           push 0x80
// 0044d512  52                   push edx
// 0044d513  e858d9ffff           call 0x44ae70
// 0044d518  83c424               add esp, 0x24
// 0044d51b  6819000200           push 0x20019
// 0044d520  8d45c8               lea eax, [ebp - 0x38]
// 0044d523  50                   push eax
// 0044d524  6800000080           push 0x80000000
// 0044d529  8d4d60               lea ecx, [ebp + 0x60]
// 0044d52c  e83f59fbff           call 0x402e70
// 0044d531  85c0                 test eax, eax
// 0044d533  7537                 jne 0x44d56c
// 0044d535  8b5560               mov edx, dword ptr [ebp + 0x60]
// 0044d538  57                   push edi
// 0044d539  57                   push edi
// 0044d53a  57                   push edi
// 0044d53b  57                   push edi
// 0044d53c  57                   push edi
// 0044d53d  57                   push edi
// 0044d53e  57                   push edi
// 0044d53f  8d4d7c               lea ecx, [ebp + 0x7c]
// 0044d542  51                   push ecx
// 0044d543  57                   push edi
// 0044d544  57                   push edi
// 0044d545  57                   push edi
// 0044d546  52                   push edx
// 0044d547  ff1518b09800         call dword ptr [0x98b018]
// 0044d54d  8d4d60               lea ecx, [ebp + 0x60]
// 0044d550  8bf0                 mov esi, eax
// 0044d552  e8e958fbff           call 0x402e40
// 0044d557  3bf7                 cmp esi, edi
// 0044d559  7511                 jne 0x44d56c
// 0044d55b  397d7c               cmp dword ptr [ebp + 0x7c], edi
// 0044d55e  750c                 jne 0x44d56c
// 0044d560  8d45c8               lea eax, [ebp - 0x38]
// 0044d563  50                   push eax
// 0044d564  8d4d58               lea ecx, [ebp + 0x58]
// 0044d567  e87458fbff           call 0x402de0
// 0044d56c  8d4d60               lea ecx, [ebp + 0x60]
// 0044d56f  e82c68fbff           call 0x403da0
// 0044d574  8d4d58               lea ecx, [ebp + 0x58]
// 0044d577  e82468fbff           call 0x403da0
// 0044d57c  8d4d78               lea ecx, [ebp + 0x78]
// 0044d57f  e8fc62fbff           call 0x403880
// 0044d584  8b4568               mov eax, dword ptr [ebp + 0x68]
// 0044d587  85c0                 test eax, eax
// 0044d589  7408                 je 0x44d593
// 0044d58b  8b08                 mov ecx, dword ptr [eax]
// 0044d58d  8b5108               mov edx, dword ptr [ecx + 8]
// 0044d590  50                   push eax
// 0044d591  ffd2                 call edx
// 0044d593  33c0                 xor eax, eax
// 0044d595  8da53cffffff         lea esp, [ebp - 0xc4]
// 0044d59b  5f                   pop edi
// 0044d59c  5e                   pop esi
// 0044d59d  5b                   pop ebx
// 0044d59e  83c56c               add ebp, 0x6c
// 0044d5a1  8be5                 mov esp, ebp
// 0044d5a3  5d                   pop ebp
// 0044d5a4  c20c00               ret 0xc
// library atl-9.0/atl.cpp (function _AtlRegisterClassCategoriesHelper@12)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
