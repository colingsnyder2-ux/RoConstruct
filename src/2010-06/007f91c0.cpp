// from server: 100% by auto
// roc 2010-06 007f91c0  unit: CXTPControls  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007f91c0
//
// 007f91c0  8b01                 mov eax, dword ptr [ecx]
// 007f91c2  8b5074               mov edx, dword ptr [eax + 0x74]
// 007f91c5  ffd2                 call edx
// 007f91c7  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPControls.cpp (function ?OnControlAdded@CXTPControls@@MAEXPAVCXTPControl@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPControls.cpp
