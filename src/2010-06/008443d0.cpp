// from server: 100% by auto
// roc 2010-06 008443d0  unit: CXTPToolBar::CControlButtonHide  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008443d0
//
// 008443d0  c701947ba600         mov dword ptr [ecx], 0xa67b94
// 008443d6  c74120347ba600       mov dword ptr [ecx + 0x20], 0xa67b34
// 008443dd  e9de7df6ff           jmp 0x7ac1c0
// library xtp-13.2.1/Source\CommandBars\XTPControlButton.cpp (function ??1CXTPControlButton@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlButton.cpp
