// from server: 100% by auto
// roc 2010-06 0081af00  unit: CPropertyGridItemBrickColor  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0081af00
//
// 0081af00  c7017c2fa600         mov dword ptr [ecx], 0xa62f7c
// 0081af06  c741201c2fa600       mov dword ptr [ecx + 0x20], 0xa62f1c
// 0081af0d  e9befeffff           jmp 0x81add0
// library xtp-13.2.1/Source\CommandBars\XTPControlButton.cpp (function ??1CXTPControlButton@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlButton.cpp
