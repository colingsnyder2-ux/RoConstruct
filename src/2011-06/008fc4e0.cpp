// from server: 100% by auto
// roc 2011-06 008fc4e0  unit: CXTPRibbonTabPopupToolBar  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008fc4e0
//
// 008fc4e0  83ec10               sub esp, 0x10
// 008fc4e3  56                   push esi
// 008fc4e4  8bf1                 mov esi, ecx
// 008fc4e6  8b4614               mov eax, dword ptr [esi + 0x14]
// 008fc4e9  85c0                 test eax, eax
// 008fc4eb  7437                 je 0x8fc524
// 008fc4ed  8b4834               mov ecx, dword ptr [eax + 0x34]
// 008fc4f0  894c2404             mov dword ptr [esp + 4], ecx
// 008fc4f4  8b5038               mov edx, dword ptr [eax + 0x38]
// 008fc4f7  89542408             mov dword ptr [esp + 8], edx
// 008fc4fb  8b483c               mov ecx, dword ptr [eax + 0x3c]
// 008fc4fe  894c240c             mov dword ptr [esp + 0xc], ecx
// 008fc502  8b5040               mov edx, dword ptr [eax + 0x40]
// 008fc505  8b4e08               mov ecx, dword ptr [esi + 8]
// 008fc508  89542410             mov dword ptr [esp + 0x10], edx
// 008fc50c  c7461400000000       mov dword ptr [esi + 0x14], 0
// 008fc513  8b01                 mov eax, dword ptr [ecx]
// 008fc515  8b80ac010000         mov eax, dword ptr [eax + 0x1ac]
// 008fc51b  6a01                 push 1
// 008fc51d  8d542408             lea edx, [esp + 8]
// 008fc521  52                   push edx
// 008fc522  ffd0                 call eax
// 008fc524  8b442418             mov eax, dword ptr [esp + 0x18]
// 008fc528  894614               mov dword ptr [esi + 0x14], eax
// 008fc52b  85c0                 test eax, eax
// 008fc52d  7430                 je 0x8fc55f
// 008fc52f  8b4834               mov ecx, dword ptr [eax + 0x34]
// 008fc532  894c2404             mov dword ptr [esp + 4], ecx
// 008fc536  8b5038               mov edx, dword ptr [eax + 0x38]
// 008fc539  89542408             mov dword ptr [esp + 8], edx
// 008fc53d  8b483c               mov ecx, dword ptr [eax + 0x3c]
// 008fc540  894c240c             mov dword ptr [esp + 0xc], ecx
// 008fc544  8b5040               mov edx, dword ptr [eax + 0x40]
// 008fc547  8b4e08               mov ecx, dword ptr [esi + 8]
// 008fc54a  89542410             mov dword ptr [esp + 0x10], edx
// 008fc54e  8b01                 mov eax, dword ptr [ecx]
// 008fc550  8b80ac010000         mov eax, dword ptr [eax + 0x1ac]
// 008fc556  6a01                 push 1
// 008fc558  8d542408             lea edx, [esp + 8]
// 008fc55c  52                   push edx
// 008fc55d  ffd0                 call eax
// 008fc55f  5e                   pop esi
// 008fc560  83c410               add esp, 0x10
// 008fc563  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\Ribbon\XTPRibbonPopups.cpp (function ?HighlightGroup@CXTPRibbonScrollableBar@@QAEXPAVCXTPRibbonGroup@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Ribbon/XTPRibbonPopups.cpp
