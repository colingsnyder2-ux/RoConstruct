// from server: 100% by auto
// roc 2009-06 00756700  unit: CXTPColorManager  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00756700
//
// 00756700  8b442404             mov eax, dword ptr [esp + 4]
// 00756704  8b4934               mov ecx, dword ptr [ecx + 0x34]
// 00756707  6a02                 push 2
// 00756709  50                   push eax
// 0075670a  e88b5a0f00           call 0x84c19a
// 0075670f  d1e8                 shr eax, 1
// 00756711  83e001               and eax, 1
// 00756714  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?IsSelected@CXTPTreeBase@@QBEHPAU_TREEITEM@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
