// from server: 100% by auto
// roc 2010-06 008a3930  unit: CXTPRibbonTabPopupToolBar  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a3930
//
// 008a3930  83ec10               sub esp, 0x10
// 008a3933  56                   push esi
// 008a3934  8bf1                 mov esi, ecx
// 008a3936  8b4614               mov eax, dword ptr [esi + 0x14]
// 008a3939  85c0                 test eax, eax
// 008a393b  7437                 je 0x8a3974
// 008a393d  8b4834               mov ecx, dword ptr [eax + 0x34]
// 008a3940  894c2404             mov dword ptr [esp + 4], ecx
// 008a3944  8b5038               mov edx, dword ptr [eax + 0x38]
// 008a3947  89542408             mov dword ptr [esp + 8], edx
// 008a394b  8b483c               mov ecx, dword ptr [eax + 0x3c]
// 008a394e  894c240c             mov dword ptr [esp + 0xc], ecx
// 008a3952  8b5040               mov edx, dword ptr [eax + 0x40]
// 008a3955  8b4e08               mov ecx, dword ptr [esi + 8]
// 008a3958  89542410             mov dword ptr [esp + 0x10], edx
// 008a395c  c7461400000000       mov dword ptr [esi + 0x14], 0
// 008a3963  8b01                 mov eax, dword ptr [ecx]
// 008a3965  8b80ac010000         mov eax, dword ptr [eax + 0x1ac]
// 008a396b  6a01                 push 1
// 008a396d  8d542408             lea edx, [esp + 8]
// 008a3971  52                   push edx
// 008a3972  ffd0                 call eax
// 008a3974  8b442418             mov eax, dword ptr [esp + 0x18]
// 008a3978  894614               mov dword ptr [esi + 0x14], eax
// 008a397b  85c0                 test eax, eax
// 008a397d  7430                 je 0x8a39af
// 008a397f  8b4834               mov ecx, dword ptr [eax + 0x34]
// 008a3982  894c2404             mov dword ptr [esp + 4], ecx
// 008a3986  8b5038               mov edx, dword ptr [eax + 0x38]
// 008a3989  89542408             mov dword ptr [esp + 8], edx
// 008a398d  8b483c               mov ecx, dword ptr [eax + 0x3c]
// 008a3990  894c240c             mov dword ptr [esp + 0xc], ecx
// 008a3994  8b5040               mov edx, dword ptr [eax + 0x40]
// 008a3997  8b4e08               mov ecx, dword ptr [esi + 8]
// 008a399a  89542410             mov dword ptr [esp + 0x10], edx
// 008a399e  8b01                 mov eax, dword ptr [ecx]
// 008a39a0  8b80ac010000         mov eax, dword ptr [eax + 0x1ac]
// 008a39a6  6a01                 push 1
// 008a39a8  8d542408             lea edx, [esp + 8]
// 008a39ac  52                   push edx
// 008a39ad  ffd0                 call eax
// 008a39af  5e                   pop esi
// 008a39b0  83c410               add esp, 0x10
// 008a39b3  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\Ribbon\XTPRibbonPopups.cpp (function ?HighlightGroup@CXTPRibbonScrollableBar@@QAEXPAVCXTPRibbonGroup@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Ribbon/XTPRibbonPopups.cpp
