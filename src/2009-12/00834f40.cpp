// from server: 100% by auto
// roc 2009-12 00834f40  unit: CXTTreeView  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00834f40
//
// 00834f40  56                   push esi
// 00834f41  8bf1                 mov esi, ecx
// 00834f43  e888feffff           call 0x834dd0
// 00834f48  c706ac689f00         mov dword ptr [esi], 0x9f68ac
// 00834f4e  c7465424689f00       mov dword ptr [esi + 0x54], 0x9f6824
// 00834f55  89b688000000         mov dword ptr [esi + 0x88], esi
// 00834f5b  8bc6                 mov eax, esi
// 00834f5d  5e                   pop esi
// 00834f5e  c3                   ret 
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeCtrlView.cpp (function ??0CXTPTreeCtrl@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeCtrlView.cpp
