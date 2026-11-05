// from server: 100% by auto
// roc 2010-06 0081e790  unit: CXTPPropertyGridView  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0081e790
//
// 0081e790  c7015c38a600         mov dword ptr [ecx], 0xa6385c
// 0081e796  c741544c38a600       mov dword ptr [ecx + 0x54], 0xa6384c
// 0081e79d  e99e7c0700           jmp 0x896440
// library xtp-13.2.1/Source\Controls\XTColorPicker.cpp (function ??1CXTColorPicker@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPicker.cpp
