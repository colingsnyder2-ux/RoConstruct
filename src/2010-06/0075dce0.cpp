// from server: 100% by auto
// roc 2010-06 0075dce0  unit: RBX::RotatePJoint  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0075dce0
//
// 0075dce0  c701a420a500         mov dword ptr [ecx], 0xa520a4
// 0075dce6  c741208420a500       mov dword ptr [ecx + 0x20], 0xa52084
// 0075dced  e97eb5faff           jmp 0x709270
// library xtp-13.2.1/Source\CommandBars\XTPControlButton.cpp (function ??1CXTPControlButton@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlButton.cpp
