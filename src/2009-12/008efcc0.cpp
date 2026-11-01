// from server: 100% by auto
// roc 2009-12 008efcc0  unit: CXTPRibbonGroupPopupToolBar  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008efcc0
//
// 008efcc0  83ec10               sub esp, 0x10
// 008efcc3  56                   push esi
// 008efcc4  8bf1                 mov esi, ecx
// 008efcc6  8b4618               mov eax, dword ptr [esi + 0x18]
// 008efcc9  85c0                 test eax, eax
// 008efccb  743f                 je 0x8efd0c
// 008efccd  8b4834               mov ecx, dword ptr [eax + 0x34]
// 008efcd0  894c2404             mov dword ptr [esp + 4], ecx
// 008efcd4  8b5038               mov edx, dword ptr [eax + 0x38]
// 008efcd7  89542408             mov dword ptr [esp + 8], edx
// 008efcdb  8b483c               mov ecx, dword ptr [eax + 0x3c]
// 008efcde  894c240c             mov dword ptr [esp + 0xc], ecx
// 008efce2  8b5040               mov edx, dword ptr [eax + 0x40]
// 008efce5  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008efce9  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008efced  50                   push eax
// 008efcee  89542414             mov dword ptr [esp + 0x14], edx
// 008efcf2  51                   push ecx
// 008efcf3  8d54240c             lea edx, [esp + 0xc]
// 008efcf7  52                   push edx
// 008efcf8  ff155cca9800         call dword ptr [0x98ca5c]
// 008efcfe  85c0                 test eax, eax
// 008efd00  740a                 je 0x8efd0c
// 008efd02  8b4618               mov eax, dword ptr [esi + 0x18]
// 008efd05  5e                   pop esi
// 008efd06  83c410               add esp, 0x10
// 008efd09  c20800               ret 8
// 008efd0c  33c0                 xor eax, eax
// 008efd0e  5e                   pop esi
// 008efd0f  83c410               add esp, 0x10
// 008efd12  c20800               ret 8
// library xtp-15.2.1/Source\Ribbon\XTPRibbonPopups.cpp (function ?HitTestGroup@CXTPRibbonGroupPopupToolBar@@UBEPAVCXTPRibbonGroup@@VCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonPopups.cpp
