// from server: 100% by auto
// roc 2009-12 004af460  unit: Ogre::VRbxTextureCompositorSceneManager::?$sp_counted_impl_p  size: 343 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004af460
//
// 004af460  56                   push esi
// 004af461  57                   push edi
// 004af462  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004af466  8bf1                 mov esi, ecx
// 004af468  3bf7                 cmp esi, edi
// 004af46a  0f8440010000         je 0x4af5b0
// 004af470  8b470c               mov eax, dword ptr [edi + 0xc]
// 004af473  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 004af476  2bc8                 sub ecx, eax
// 004af478  b8310cc330           mov eax, 0x30c30c31
// 004af47d  f7e9                 imul ecx
// 004af47f  55                   push ebp
// 004af480  c1fa04               sar edx, 4
// 004af483  8bea                 mov ebp, edx
// 004af485  c1ed1f               shr ebp, 0x1f
// 004af488  03ea                 add ebp, edx
// 004af48a  750f                 jne 0x4af49b
// 004af48c  8bce                 mov ecx, esi
// 004af48e  e80dfeffff           call 0x4af2a0
// 004af493  5d                   pop ebp
// 004af494  5f                   pop edi
// 004af495  8bc6                 mov eax, esi
// 004af497  5e                   pop esi
// 004af498  c20400               ret 4
// 004af49b  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 004af49e  53                   push ebx
// 004af49f  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 004af4a2  2bcb                 sub ecx, ebx
// 004af4a4  b8310cc330           mov eax, 0x30c30c31
// 004af4a9  f7e9                 imul ecx
// 004af4ab  c1fa04               sar edx, 4
// 004af4ae  8bca                 mov ecx, edx
// 004af4b0  c1e91f               shr ecx, 0x1f
// 004af4b3  03ca                 add ecx, edx
// 004af4b5  3be9                 cmp ebp, ecx
// 004af4b7  774d                 ja 0x4af506
// 004af4b9  8b4710               mov eax, dword ptr [edi + 0x10]
// 004af4bc  53                   push ebx
// 004af4bd  50                   push eax
// 004af4be  8b470c               mov eax, dword ptr [edi + 0xc]
// 004af4c1  50                   push eax
// 004af4c2  e8a9f9ffff           call 0x4aee70
// 004af4c7  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004af4cb  51                   push ecx
// 004af4cc  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 004af4cf  8d5608               lea edx, [esi + 8]
// 004af4d2  52                   push edx
// 004af4d3  51                   push ecx
// 004af4d4  50                   push eax
// 004af4d5  e836f9ffff           call 0x4aee10
// 004af4da  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 004af4dd  2b4f0c               sub ecx, dword ptr [edi + 0xc]
// 004af4e0  b8310cc330           mov eax, 0x30c30c31
// 004af4e5  f7e9                 imul ecx
// 004af4e7  c1fa04               sar edx, 4
// 004af4ea  8bc2                 mov eax, edx
// 004af4ec  c1e81f               shr eax, 0x1f
// 004af4ef  03c2                 add eax, edx
// 004af4f1  6bc054               imul eax, eax, 0x54
// 004af4f4  83c41c               add esp, 0x1c
// 004af4f7  03460c               add eax, dword ptr [esi + 0xc]
// 004af4fa  5b                   pop ebx
// 004af4fb  5d                   pop ebp
// 004af4fc  894610               mov dword ptr [esi + 0x10], eax
// 004af4ff  5f                   pop edi
// 004af500  8bc6                 mov eax, esi
// 004af502  5e                   pop esi
// 004af503  c20400               ret 4
// 004af506  85db                 test ebx, ebx
// 004af508  7504                 jne 0x4af50e
// 004af50a  33c0                 xor eax, eax
// 004af50c  eb16                 jmp 0x4af524
// 004af50e  8b5614               mov edx, dword ptr [esi + 0x14]
// 004af511  2bd3                 sub edx, ebx
// 004af513  b8310cc330           mov eax, 0x30c30c31
// 004af518  f7ea                 imul edx
// 004af51a  c1fa04               sar edx, 4
// 004af51d  8bc2                 mov eax, edx
// 004af51f  c1e81f               shr eax, 0x1f
// 004af522  03c2                 add eax, edx
// 004af524  3be8                 cmp ebp, eax
// 004af526  7731                 ja 0x4af559
// 004af528  8b470c               mov eax, dword ptr [edi + 0xc]
// 004af52b  6bc954               imul ecx, ecx, 0x54
// 004af52e  03c8                 add ecx, eax
// 004af530  8be9                 mov ebp, ecx
// 004af532  53                   push ebx
// 004af533  55                   push ebp
// 004af534  50                   push eax
// 004af535  e836f9ffff           call 0x4aee70
// 004af53a  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 004af53d  8b5710               mov edx, dword ptr [edi + 0x10]
// 004af540  83c40c               add esp, 0xc
// 004af543  51                   push ecx
// 004af544  52                   push edx
// 004af545  55                   push ebp
// 004af546  8bce                 mov ecx, esi
// 004af548  e8c35d0000           call 0x4b5310
// 004af54d  5b                   pop ebx
// 004af54e  5d                   pop ebp
// 004af54f  894610               mov dword ptr [esi + 0x10], eax
// 004af552  5f                   pop edi
// 004af553  8bc6                 mov eax, esi
// 004af555  5e                   pop esi
// 004af556  c20400               ret 4
// 004af559  85db                 test ebx, ebx
// 004af55b  7418                 je 0x4af575
// 004af55d  8b4610               mov eax, dword ptr [esi + 0x10]
// 004af560  50                   push eax
// 004af561  53                   push ebx
// 004af562  8bce                 mov ecx, esi
// 004af564  e8c7fbffff           call 0x4af130
// 004af569  8b460c               mov eax, dword ptr [esi + 0xc]
// 004af56c  50                   push eax
// 004af56d  e8e8423400           call 0x7f385a
// 004af572  83c404               add esp, 4
// 004af575  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 004af578  2b4f0c               sub ecx, dword ptr [edi + 0xc]
// 004af57b  b8310cc330           mov eax, 0x30c30c31
// 004af580  f7e9                 imul ecx
// 004af582  c1fa04               sar edx, 4
// 004af585  8bc2                 mov eax, edx
// 004af587  c1e81f               shr eax, 0x1f
// 004af58a  03c2                 add eax, edx
// 004af58c  50                   push eax
// 004af58d  8bce                 mov ecx, esi
// 004af58f  e89cf4ffff           call 0x4aea30
// 004af594  84c0                 test al, al
// 004af596  7416                 je 0x4af5ae
// 004af598  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004af59b  8b5710               mov edx, dword ptr [edi + 0x10]
// 004af59e  8b470c               mov eax, dword ptr [edi + 0xc]
// 004af5a1  51                   push ecx
// 004af5a2  52                   push edx
// 004af5a3  50                   push eax
// 004af5a4  8bce                 mov ecx, esi
// 004af5a6  e8655d0000           call 0x4b5310
// 004af5ab  894610               mov dword ptr [esi + 0x10], eax
// 004af5ae  5b                   pop ebx
// 004af5af  5d                   pop ebp
// 004af5b0  5f                   pop edi
// 004af5b1  8bc6                 mov eax, esi
// 004af5b3  5e                   pop esi
// 004af5b4  c20400               ret 4
// library boost-1.40.0/libs\program_options\src\cmdline.cpp (function ??4?$vector@V?$basic_option@D@program_options@boost@@V?$allocator@V?$basic_option@D@program_options@boost@@@std@@@std@@QAEAAV01@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/program_options/src/cmdline.cpp
