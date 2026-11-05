// roc 2012-06 009fa6e0  unit: CXTPControlGallery::UGALLERYITEM_POSITION::?$CArray  size: 165 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009fa6e0
//
// 009fa6e0  53                   push ebx
// 009fa6e1  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 009fa6e5  55                   push ebp
// 009fa6e6  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 009fa6ea  85db                 test ebx, ebx
// 009fa6ec  7409                 je 0x9fa6f7
// 009fa6ee  85ed                 test ebp, ebp
// 009fa6f0  7505                 jne 0x9fa6f7
// 009fa6f2  e8c97cf8ff           call 0x9823c0
// 009fa6f7  8b44240c             mov eax, dword ptr [esp + 0xc]
// 009fa6fb  8b4818               mov ecx, dword ptr [eax + 0x18]
// 009fa6fe  f7d1                 not ecx
// 009fa700  56                   push esi
// 009fa701  57                   push edi
// 009fa702  f6c101               test cl, 1
// 009fa705  743b                 je 0x9fa742
// 009fa707  85db                 test ebx, ebx
// 009fa709  7630                 jbe 0x9fa73b
// 009fa70b  eb03                 jmp 0x9fa710
// 009fa70d  8d4900               lea ecx, [ecx]
// 009fa710  8bfb                 mov edi, ebx
// 009fa712  81fb55555505         cmp ebx, 0x5555555
// 009fa718  7205                 jb 0x9fa71f
// 009fa71a  bf55555505           mov edi, 0x5555555
// 009fa71f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 009fa723  8d347f               lea esi, [edi + edi*2]
// 009fa726  03f6                 add esi, esi
// 009fa728  03f6                 add esi, esi
// 009fa72a  03f6                 add esi, esi
// 009fa72c  56                   push esi
// 009fa72d  55                   push ebp
// 009fa72e  e83385f8ff           call 0x982c66
// 009fa733  2bdf                 sub ebx, edi
// 009fa735  03ee                 add ebp, esi
// 009fa737  85db                 test ebx, ebx
// 009fa739  77d5                 ja 0x9fa710
// 009fa73b  5f                   pop edi
// 009fa73c  5e                   pop esi
// 009fa73d  5d                   pop ebp
// 009fa73e  5b                   pop ebx
// 009fa73f  c20c00               ret 0xc
// 009fa742  85db                 test ebx, ebx
// 009fa744  76f5                 jbe 0x9fa73b
// 009fa746  8bfb                 mov edi, ebx
// 009fa748  81fb55555505         cmp ebx, 0x5555555
// 009fa74e  7205                 jb 0x9fa755
// 009fa750  bf55555505           mov edi, 0x5555555
// 009fa755  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 009fa759  8d347f               lea esi, [edi + edi*2]
// 009fa75c  03f6                 add esi, esi
// 009fa75e  03f6                 add esi, esi
// 009fa760  03f6                 add esi, esi
// 009fa762  56                   push esi
// 009fa763  55                   push ebp
// 009fa764  e8f784f8ff           call 0x982c60
// 009fa769  3bc6                 cmp eax, esi
// 009fa76b  750f                 jne 0x9fa77c
// 009fa76d  2bdf                 sub ebx, edi
// 009fa76f  03ee                 add ebp, esi
// 009fa771  85db                 test ebx, ebx
// 009fa773  77d1                 ja 0x9fa746
// 009fa775  5f                   pop edi
// 009fa776  5e                   pop esi
// 009fa777  5d                   pop ebp
// 009fa778  5b                   pop ebx
// 009fa779  c20c00               ret 0xc
// 009fa77c  6a00                 push 0
// 009fa77e  6a03                 push 3
// 009fa780  e8d584f8ff           call 0x982c5a
// copied from an identical function in another client (function ??$SerializeElements@UCMFCRestoredTabInfo@@@@YGXAAVCArchive@@PAUCMFCRestoredTabInfo@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp