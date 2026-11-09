// from server: 100% by auto
// roc 2010-06 008a3ec0  unit: CXTPRibbonGroupPopupToolBar  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a3ec0
//
// 008a3ec0  83ec10               sub esp, 0x10
// 008a3ec3  56                   push esi
// 008a3ec4  8bf1                 mov esi, ecx
// 008a3ec6  8b4618               mov eax, dword ptr [esi + 0x18]
// 008a3ec9  85c0                 test eax, eax
// 008a3ecb  743f                 je 0x8a3f0c
// 008a3ecd  8b4834               mov ecx, dword ptr [eax + 0x34]
// 008a3ed0  894c2404             mov dword ptr [esp + 4], ecx
// 008a3ed4  8b5038               mov edx, dword ptr [eax + 0x38]
// 008a3ed7  89542408             mov dword ptr [esp + 8], edx
// 008a3edb  8b483c               mov ecx, dword ptr [eax + 0x3c]
// 008a3ede  894c240c             mov dword ptr [esp + 0xc], ecx
// 008a3ee2  8b5040               mov edx, dword ptr [eax + 0x40]
// 008a3ee5  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008a3ee9  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008a3eed  50                   push eax
// 008a3eee  89542414             mov dword ptr [esp + 0x14], edx
// 008a3ef2  51                   push ecx
// 008a3ef3  8d54240c             lea edx, [esp + 0xc]
// 008a3ef7  52                   push edx
// 008a3ef8  ff15e0bb9e00         call dword ptr [0x9ebbe0]
// 008a3efe  85c0                 test eax, eax
// 008a3f00  740a                 je 0x8a3f0c
// 008a3f02  8b4618               mov eax, dword ptr [esi + 0x18]
// 008a3f05  5e                   pop esi
// 008a3f06  83c410               add esp, 0x10
// 008a3f09  c20800               ret 8
// 008a3f0c  33c0                 xor eax, eax
// 008a3f0e  5e                   pop esi
// 008a3f0f  83c410               add esp, 0x10
// 008a3f12  c20800               ret 8
// library xtp-13.2.1/Source\Ribbon\XTPRibbonPopups.cpp (function ?HitTestGroup@CXTPRibbonGroupPopupToolBar@@UBEPAVCXTPRibbonGroup@@VCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Ribbon/XTPRibbonPopups.cpp
