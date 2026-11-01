// from server: 100% by auto
// roc 2009-12 00834ea0  unit: CXTTreeView  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00834ea0
//
// 00834ea0  c7018c719f00         mov dword ptr [ecx], 0x9f718c
// 00834ea6  c7416004719f00       mov dword ptr [ecx + 0x60], 0x9f7104
// 00834ead  e9befeffff           jmp 0x834d70
// library xtp-15.2.1/Source\Controls\List\XTPListCtrlView.cpp (function ??1CXTPListView@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/List/XTPListCtrlView.cpp
