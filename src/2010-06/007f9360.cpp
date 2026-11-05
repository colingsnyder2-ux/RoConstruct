// from server: 100% by auto
// roc 2010-06 007f9360  unit: CXTPControls  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007f9360
//
// 007f9360  83792c00             cmp dword ptr [ecx + 0x2c], 0
// 007f9364  8b442404             mov eax, dword ptr [esp + 4]
// 007f9368  894120               mov dword ptr [ecx + 0x20], eax
// 007f936b  7e07                 jle 0x7f9374
// 007f936d  8b11                 mov edx, dword ptr [ecx]
// 007f936f  8b4274               mov eax, dword ptr [edx + 0x74]
// 007f9372  ffd0                 call eax
// 007f9374  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPControls.cpp (function ?SetParent@CXTPControls@@QAEXPAVCXTPCommandBar@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPControls.cpp
