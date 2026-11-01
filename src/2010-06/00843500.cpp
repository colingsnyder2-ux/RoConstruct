// from server: 100% by auto
// roc 2010-06 00843500  unit: UtagACCEL::?$CArray  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00843500
//
// 00843500  55                   push ebp
// 00843501  57                   push edi
// 00843502  8bf9                 mov edi, ecx
// 00843504  33ed                 xor ebp, ebp
// 00843506  396f04               cmp dword ptr [edi + 4], ebp
// 00843509  742d                 je 0x843538
// 0084350b  53                   push ebx
// 0084350c  33db                 xor ebx, ebx
// 0084350e  396f08               cmp dword ptr [edi + 8], ebp
// 00843511  7624                 jbe 0x843537
// 00843513  56                   push esi
// 00843514  8b4704               mov eax, dword ptr [edi + 4]
// 00843517  8b3498               mov esi, dword ptr [eax + ebx*4]
// 0084351a  3bf5                 cmp esi, ebp
// 0084351c  7412                 je 0x843530
// 0084351e  8bff                 mov edi, edi
// 00843520  8d4e04               lea ecx, [esi + 4]
// 00843523  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 00843529  8b7608               mov esi, dword ptr [esi + 8]
// 0084352c  3bf5                 cmp esi, ebp
// 0084352e  75f0                 jne 0x843520
// 00843530  43                   inc ebx
// 00843531  3b5f08               cmp ebx, dword ptr [edi + 8]
// 00843534  72de                 jb 0x843514
// 00843536  5e                   pop esi
// 00843537  5b                   pop ebx
// 00843538  8b4f04               mov ecx, dword ptr [edi + 4]
// 0084353b  51                   push ecx
// 0084353c  e80547f6ff           call 0x7a7c46
// 00843541  8b4f14               mov ecx, dword ptr [edi + 0x14]
// 00843544  83c404               add esp, 4
// 00843547  896f04               mov dword ptr [edi + 4], ebp
// 0084354a  896f0c               mov dword ptr [edi + 0xc], ebp
// 0084354d  896f10               mov dword ptr [edi + 0x10], ebp
// 00843550  e8af4ff6ff           call 0x7a8504
// 00843555  896f14               mov dword ptr [edi + 0x14], ebp
// 00843558  5f                   pop edi
// 00843559  5d                   pop ebp
// 0084355a  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPShortcutManager.cpp (function ?RemoveAll@?$CMap@GGV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPShortcutManager.cpp
