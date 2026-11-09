// from server: 100% by auto
// roc 2010-06 00849790  unit: CXTPRibbonBar  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00849790
//
// 00849790  8b01                 mov eax, dword ptr [ecx]
// 00849792  8b80dc010000         mov eax, dword ptr [eax + 0x1dc]
// 00849798  c744240800000000     mov dword ptr [esp + 8], 0
// 008497a0  ffe0                 jmp eax
// library xtp-13.2.1-shared-mfc/Source\Ribbon\XTPRibbonBar.cpp (function ?MergeToolBar@CXTPRibbonBar@@MAEXPAVCXTPCommandBar@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Ribbon/XTPRibbonBar.cpp
