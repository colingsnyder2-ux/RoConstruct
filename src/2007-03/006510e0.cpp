// from server: 100% by auto
// roc 2007-03 006510e0  unit: seg_00650000  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006510e0
//
// 006510e0  56                   push esi
// 006510e1  8bf1                 mov esi, ecx
// 006510e3  e888feffff           call 0x650f70
// 006510e8  c7064c6a7c00         mov dword ptr [esi], 0x7c6a4c
// 006510ee  c74654cc697c00       mov dword ptr [esi + 0x54], 0x7c69cc
// 006510f5  89b688000000         mov dword ptr [esi + 0x88], esi
// 006510fb  8bc6                 mov eax, esi
// 006510fd  5e                   pop esi
// 006510fe  c3                   ret 
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeCtrlView.cpp (function ??0CXTPTreeCtrl@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeCtrlView.cpp
