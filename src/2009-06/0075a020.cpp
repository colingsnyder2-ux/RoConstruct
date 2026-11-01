// from server: 100% by auto
// roc 2009-06 0075a020  unit: CXTTreeView  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0075a020
//
// 0075a020  c701e46c8f00         mov dword ptr [ecx], 0x8f6ce4
// 0075a026  c741605c6c8f00       mov dword ptr [ecx + 0x60], 0x8f6c5c
// 0075a02d  e9befeffff           jmp 0x759ef0
// library xtp-15.2.1/Source\Controls\List\XTPListCtrlView.cpp (function ??1CXTPListView@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/List/XTPListCtrlView.cpp
