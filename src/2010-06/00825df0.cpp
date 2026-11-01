// from server: 100% by auto
// roc 2010-06 00825df0  unit: CXTPControlGallery  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00825df0
//
// 00825df0  8b41fc               mov eax, dword ptr [ecx - 4]
// 00825df3  83ec10               sub esp, 0x10
// 00825df6  50                   push eax
// 00825df7  8d4c2404             lea ecx, [esp + 4]
// 00825dfb  e8701ef8ff           call 0x7a7c70
// 00825e00  8b442404             mov eax, dword ptr [esp + 4]
// 00825e04  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00825e08  c70100000000         mov dword ptr [ecx], 0
// 00825e0e  85c0                 test eax, eax
// 00825e10  7406                 je 0x825e18
// 00825e12  8b1424               mov edx, dword ptr [esp]
// 00825e15  895004               mov dword ptr [eax + 4], edx
// 00825e18  837c240c00           cmp dword ptr [esp + 0xc], 0
// 00825e1d  740c                 je 0x825e2b
// 00825e1f  8b442408             mov eax, dword ptr [esp + 8]
// 00825e23  50                   push eax
// 00825e24  6a00                 push 0
// 00825e26  e8391ef8ff           call 0x7a7c64
// 00825e2b  b801000000           mov eax, 1
// 00825e30  83c410               add esp, 0x10
// 00825e33  c21400               ret 0x14
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPControlGallery.cpp (function ?GetAccessibleChild@CXTPControlGallery@@MAEJUtagVARIANT@@PAPAUIDispatch@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPControlGallery.cpp
