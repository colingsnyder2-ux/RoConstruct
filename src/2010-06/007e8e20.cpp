// from server: 100% by auto
// roc 2010-06 007e8e20  unit: CXTTreeView  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e8e20
//
// 007e8e20  c70194aba500         mov dword ptr [ecx], 0xa5ab94
// 007e8e26  c741540caba500       mov dword ptr [ecx + 0x54], 0xa5ab0c
// 007e8e2d  e95effffff           jmp 0x7e8d90
// library xtp-13.2.1/Source\Controls\XTColorPicker.cpp (function ??1CXTColorPicker@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPicker.cpp
