// from server: 100% by auto
// roc 2009-12 008315b0  unit: CXTPColorManager  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008315b0
//
// 008315b0  8b442404             mov eax, dword ptr [esp + 4]
// 008315b4  8b4934               mov ecx, dword ptr [ecx + 0x34]
// 008315b7  6a02                 push 2
// 008315b9  50                   push eax
// 008315ba  e847510f00           call 0x926706
// 008315bf  d1e8                 shr eax, 1
// 008315c1  83e001               and eax, 1
// 008315c4  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?IsSelected@CXTPTreeBase@@QBEHPAU_TREEITEM@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
