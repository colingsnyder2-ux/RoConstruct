// from server: 100% by auto
// roc 2009-12 00834e70  unit: CXTTreeCtrlBase  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00834e70
//
// 00834e70  56                   push esi
// 00834e71  8bf1                 mov esi, ecx
// 00834e73  e868feffff           call 0x834ce0
// 00834e78  c7068c719f00         mov dword ptr [esi], 0x9f718c
// 00834e7e  c7466004719f00       mov dword ptr [esi + 0x60], 0x9f7104
// 00834e85  89b694000000         mov dword ptr [esi + 0x94], esi
// 00834e8b  8bc6                 mov eax, esi
// 00834e8d  5e                   pop esi
// 00834e8e  c3                   ret 
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeCtrlView.cpp (function ??0CXTPTreeView@@IAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeCtrlView.cpp
