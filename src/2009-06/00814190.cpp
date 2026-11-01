// from server: 100% by auto
// roc 2009-06 00814190  unit: CXTPRibbonGroupPopupToolBar  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00814190
//
// 00814190  83ec10               sub esp, 0x10
// 00814193  56                   push esi
// 00814194  8bf1                 mov esi, ecx
// 00814196  8b4618               mov eax, dword ptr [esi + 0x18]
// 00814199  85c0                 test eax, eax
// 0081419b  743f                 je 0x8141dc
// 0081419d  8b4834               mov ecx, dword ptr [eax + 0x34]
// 008141a0  894c2404             mov dword ptr [esp + 4], ecx
// 008141a4  8b5038               mov edx, dword ptr [eax + 0x38]
// 008141a7  89542408             mov dword ptr [esp + 8], edx
// 008141ab  8b483c               mov ecx, dword ptr [eax + 0x3c]
// 008141ae  894c240c             mov dword ptr [esp + 0xc], ecx
// 008141b2  8b5040               mov edx, dword ptr [eax + 0x40]
// 008141b5  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008141b9  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008141bd  50                   push eax
// 008141be  89542414             mov dword ptr [esp + 0x14], edx
// 008141c2  51                   push ecx
// 008141c3  8d54240c             lea edx, [esp + 0xc]
// 008141c7  52                   push edx
// 008141c8  ff15c0ed8900         call dword ptr [0x89edc0]
// 008141ce  85c0                 test eax, eax
// 008141d0  740a                 je 0x8141dc
// 008141d2  8b4618               mov eax, dword ptr [esi + 0x18]
// 008141d5  5e                   pop esi
// 008141d6  83c410               add esp, 0x10
// 008141d9  c20800               ret 8
// 008141dc  33c0                 xor eax, eax
// 008141de  5e                   pop esi
// 008141df  83c410               add esp, 0x10
// 008141e2  c20800               ret 8
// library xtp-15.2.1/Source\Ribbon\XTPRibbonPopups.cpp (function ?HitTestGroup@CXTPRibbonGroupPopupToolBar@@UBEPAVCXTPRibbonGroup@@VCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonPopups.cpp
