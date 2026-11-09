// from server: 100% by auto
// roc 2010-06 0075cc50  unit: RBX::RotateJoint  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0075cc50
//
// 0075cc50  c7013420a500         mov dword ptr [ecx], 0xa52034
// 0075cc56  c741201420a500       mov dword ptr [ecx + 0x20], 0xa52014
// 0075cc5d  e97e100000           jmp 0x75dce0
// library xtp-13.2.1/Source\CommandBars\XTPControlButton.cpp (function ??1CXTPControlButton@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlButton.cpp
