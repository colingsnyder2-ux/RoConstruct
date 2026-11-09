// from server: 100% by auto
// roc 2010-06 007e5700  unit: CXTPColorManager  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e5700
//
// 007e5700  8b442404             mov eax, dword ptr [esp + 4]
// 007e5704  8b4934               mov ecx, dword ptr [ecx + 0x34]
// 007e5707  6a02                 push 2
// 007e5709  50                   push eax
// 007e570a  e833791900           call 0x97d042
// 007e570f  d1e8                 shr eax, 1
// 007e5711  83e001               and eax, 1
// 007e5714  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ?IsSelected@CXTTreeBase@@QBEHPAU_TREEITEM@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp
