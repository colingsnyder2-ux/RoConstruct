// from server: 100% by auto
// roc 2009-06 0075a0c0  unit: CXTTreeView  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0075a0c0
//
// 0075a0c0  56                   push esi
// 0075a0c1  8bf1                 mov esi, ecx
// 0075a0c3  e888feffff           call 0x759f50
// 0075a0c8  c70604648f00         mov dword ptr [esi], 0x8f6404
// 0075a0ce  c746547c638f00       mov dword ptr [esi + 0x54], 0x8f637c
// 0075a0d5  89b688000000         mov dword ptr [esi + 0x88], esi
// 0075a0db  8bc6                 mov eax, esi
// 0075a0dd  5e                   pop esi
// 0075a0de  c3                   ret 
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeCtrlView.cpp (function ??0CXTPTreeCtrl@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeCtrlView.cpp
