// from server: 100% by auto
// roc 2009-12 00834c60  unit: CXTTreeView  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00834c60
//
// 00834c60  c701ac689f00         mov dword ptr [ecx], 0x9f68ac
// 00834c66  c7415424689f00       mov dword ptr [ecx + 0x54], 0x9f6824
// 00834c6d  e95effffff           jmp 0x834bd0
// library xtp-15.2.1/Source\Controls\Deprecated\XTOutBarCtrl.cpp (function ??1CXTToolBox@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTOutBarCtrl.cpp
