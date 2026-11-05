// from server: 100% by auto
// roc 2010-06 007f0a60  unit: CXTPControlPopupColor  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007f0a60
//
// 007f0a60  c70184c8a500         mov dword ptr [ecx], 0xa5c884
// 007f0a66  c7412024c8a500       mov dword ptr [ecx + 0x20], 0xa5c824
// 007f0a6d  e93ee2ffff           jmp 0x7eecb0
// library xtp-13.2.1/Source\CommandBars\XTPControlButton.cpp (function ??1CXTPControlButton@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlButton.cpp
