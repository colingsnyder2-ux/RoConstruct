// from server: 100% by auto
// roc 2011-06 00856b00  unit: CXTPControls  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00856b00
//
// 00856b00  8b01                 mov eax, dword ptr [ecx]
// 00856b02  8b5074               mov edx, dword ptr [eax + 0x74]
// 00856b05  ffd2                 call edx
// 00856b07  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPControls.cpp (function ?OnControlAdded@CXTPControls@@MAEXPAVCXTPControl@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPControls.cpp
