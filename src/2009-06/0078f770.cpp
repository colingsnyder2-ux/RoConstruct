// from server: 100% by auto
// roc 2009-06 0078f770  unit: CXTPPropertyGridView  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0078f770
//
// 0078f770  c701dcf08f00         mov dword ptr [ecx], 0x8ff0dc
// 0078f776  c74154ccf08f00       mov dword ptr [ecx + 0x54], 0x8ff0cc
// 0078f77d  e92e7f0700           jmp 0x8076b0
// library xtp-15.2.1/Source\Controls\Deprecated\XTOutBarCtrl.cpp (function ??1CXTToolBox@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTOutBarCtrl.cpp
