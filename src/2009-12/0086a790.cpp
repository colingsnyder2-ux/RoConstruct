// from server: 100% by auto
// roc 2009-12 0086a790  unit: CXTPPropertyGridView  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086a790
//
// 0086a790  c70164f59f00         mov dword ptr [ecx], 0x9ff564
// 0086a796  c7415454f59f00       mov dword ptr [ecx + 0x54], 0x9ff554
// 0086a79d  e90e7a0700           jmp 0x8e21b0
// library xtp-15.2.1/Source\Controls\Deprecated\XTOutBarCtrl.cpp (function ??1CXTToolBox@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTOutBarCtrl.cpp
