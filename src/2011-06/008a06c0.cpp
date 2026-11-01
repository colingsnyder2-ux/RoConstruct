// from server: 100% by auto
// roc 2011-06 008a06c0  unit: UtagACCEL::?$CArray  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008a06c0
//
// 008a06c0  55                   push ebp
// 008a06c1  57                   push edi
// 008a06c2  8bf9                 mov edi, ecx
// 008a06c4  33ed                 xor ebp, ebp
// 008a06c6  396f04               cmp dword ptr [edi + 4], ebp
// 008a06c9  742d                 je 0x8a06f8
// 008a06cb  53                   push ebx
// 008a06cc  33db                 xor ebx, ebx
// 008a06ce  396f08               cmp dword ptr [edi + 8], ebp
// 008a06d1  7624                 jbe 0x8a06f7
// 008a06d3  56                   push esi
// 008a06d4  8b4704               mov eax, dword ptr [edi + 4]
// 008a06d7  8b3498               mov esi, dword ptr [eax + ebx*4]
// 008a06da  3bf5                 cmp esi, ebp
// 008a06dc  7412                 je 0x8a06f0
// 008a06de  8bff                 mov edi, edi
// 008a06e0  8d4e04               lea ecx, [esi + 4]
// 008a06e3  ff15082ea400         call dword ptr [0xa42e08]
// 008a06e9  8b7608               mov esi, dword ptr [esi + 8]
// 008a06ec  3bf5                 cmp esi, ebp
// 008a06ee  75f0                 jne 0x8a06e0
// 008a06f0  43                   inc ebx
// 008a06f1  3b5f08               cmp ebx, dword ptr [edi + 8]
// 008a06f4  72de                 jb 0x8a06d4
// 008a06f6  5e                   pop esi
// 008a06f7  5b                   pop ebx
// 008a06f8  8b4f04               mov ecx, dword ptr [edi + 4]
// 008a06fb  51                   push ecx
// 008a06fc  e8039cf6ff           call 0x80a304
// 008a0701  8b4f14               mov ecx, dword ptr [edi + 0x14]
// 008a0704  83c404               add esp, 4
// 008a0707  896f04               mov dword ptr [edi + 4], ebp
// 008a070a  896f0c               mov dword ptr [edi + 0xc], ebp
// 008a070d  896f10               mov dword ptr [edi + 0x10], ebp
// 008a0710  e8b3a4f6ff           call 0x80abc8
// 008a0715  896f14               mov dword ptr [edi + 0x14], ebp
// 008a0718  5f                   pop edi
// 008a0719  5d                   pop ebp
// 008a071a  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPShortcutManager.cpp (function ?RemoveAll@?$CMap@GGV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPShortcutManager.cpp
