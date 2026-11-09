// from server: 100% by auto
// roc 2010-06 007e9060  unit: CXTTreeView  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e9060
//
// 007e9060  c70174b4a500         mov dword ptr [ecx], 0xa5b474
// 007e9066  c74160ecb3a500       mov dword ptr [ecx + 0x60], 0xa5b3ec
// 007e906d  e9befeffff           jmp 0x7e8f30
// library xtp-13.2.1/Source\Controls\XTListCtrlView.cpp (function ??1CXTListView@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTListCtrlView.cpp
