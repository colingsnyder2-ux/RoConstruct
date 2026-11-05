// from server: 100% by auto
// roc 2010-06 0042e4a0  unit: CClassTreeView  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0042e4a0
//
// 0042e4a0  56                   push esi
// 0042e4a1  8bf1                 mov esi, ecx
// 0042e4a3  e85e953700           call 0x7a7a06
// 0042e4a8  80be9c00000000       cmp byte ptr [esi + 0x9c], 0
// 0042e4af  740c                 je 0x42e4bd
// 0042e4b1  8b4660               mov eax, dword ptr [esi + 0x60]
// 0042e4b4  8b5048               mov edx, dword ptr [eax + 0x48]
// 0042e4b7  8d4e60               lea ecx, [esi + 0x60]
// 0042e4ba  5e                   pop esi
// 0042e4bb  ffe2                 jmp edx
// 0042e4bd  5e                   pop esi
// 0042e4be  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTTreeCtrlView.cpp (function ?PreSubclassWindow@CXTTreeViewBase@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeCtrlView.cpp
