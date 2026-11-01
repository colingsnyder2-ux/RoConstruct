// from server: 100% by auto
// roc 2009-06 0042cea0  unit: CClassTreeView  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0042cea0
//
// 0042cea0  8b442404             mov eax, dword ptr [esp + 4]
// 0042cea4  56                   push esi
// 0042cea5  50                   push eax
// 0042cea6  8bf1                 mov esi, ecx
// 0042cea8  e89bc62e00           call 0x719548
// 0042cead  85c0                 test eax, eax
// 0042ceaf  7504                 jne 0x42ceb5
// 0042ceb1  5e                   pop esi
// 0042ceb2  c20400               ret 4
// 0042ceb5  c6869c00000000       mov byte ptr [esi + 0x9c], 0
// 0042cebc  b801000000           mov eax, 1
// 0042cec1  5e                   pop esi
// 0042cec2  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeCtrlView.cpp (function ?PreCreateWindow@CXTPTreeViewBase@@MAEHAAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeCtrlView.cpp
