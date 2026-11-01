// from server: 100% by auto
// roc 2011-06 00882e80  unit: CXTPControlGallery  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00882e80
//
// 00882e80  8b41fc               mov eax, dword ptr [ecx - 4]
// 00882e83  83ec10               sub esp, 0x10
// 00882e86  50                   push eax
// 00882e87  8d4c2404             lea ecx, [esp + 4]
// 00882e8b  e89e74f8ff           call 0x80a32e
// 00882e90  8b442404             mov eax, dword ptr [esp + 4]
// 00882e94  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00882e98  c70100000000         mov dword ptr [ecx], 0
// 00882e9e  85c0                 test eax, eax
// 00882ea0  7406                 je 0x882ea8
// 00882ea2  8b1424               mov edx, dword ptr [esp]
// 00882ea5  895004               mov dword ptr [eax + 4], edx
// 00882ea8  837c240c00           cmp dword ptr [esp + 0xc], 0
// 00882ead  740c                 je 0x882ebb
// 00882eaf  8b442408             mov eax, dword ptr [esp + 8]
// 00882eb3  50                   push eax
// 00882eb4  6a00                 push 0
// 00882eb6  e86774f8ff           call 0x80a322
// 00882ebb  b801000000           mov eax, 1
// 00882ec0  83c410               add esp, 0x10
// 00882ec3  c21400               ret 0x14
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPControlGallery.cpp (function ?GetAccessibleChild@CXTPControlGallery@@MAEJUtagVARIANT@@PAPAUIDispatch@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPControlGallery.cpp
