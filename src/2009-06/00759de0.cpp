// from server: 100% by auto
// roc 2009-06 00759de0  unit: CXTTreeView  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00759de0
//
// 00759de0  c70104648f00         mov dword ptr [ecx], 0x8f6404
// 00759de6  c741547c638f00       mov dword ptr [ecx + 0x54], 0x8f637c
// 00759ded  e95effffff           jmp 0x759d50
// library xtp-15.2.1/Source\Controls\Deprecated\XTOutBarCtrl.cpp (function ??1CXTToolBox@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTOutBarCtrl.cpp
