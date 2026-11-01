// from server: 100% by auto
// roc 2007-03 00650e00  unit: seg_00650000  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00650e00
//
// 00650e00  c7014c6a7c00         mov dword ptr [ecx], 0x7c6a4c
// 00650e06  c74154cc697c00       mov dword ptr [ecx + 0x54], 0x7c69cc
// 00650e0d  e95effffff           jmp 0x650d70
// library xtp-15.2.1/Source\Controls\Deprecated\XTOutBarCtrl.cpp (function ??1CXTToolBox@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTOutBarCtrl.cpp
