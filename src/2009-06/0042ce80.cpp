// from server: 100% by auto
// roc 2009-06 0042ce80  unit: CClassTreeView  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0042ce80
//
// 0042ce80  56                   push esi
// 0042ce81  8bf1                 mov esi, ecx
// 0042ce83  e816bc2e00           call 0x718a9e
// 0042ce88  80be9c00000000       cmp byte ptr [esi + 0x9c], 0
// 0042ce8f  740c                 je 0x42ce9d
// 0042ce91  8b4660               mov eax, dword ptr [esi + 0x60]
// 0042ce94  8b5048               mov edx, dword ptr [eax + 0x48]
// 0042ce97  8d4e60               lea ecx, [esi + 0x60]
// 0042ce9a  5e                   pop esi
// 0042ce9b  ffe2                 jmp edx
// 0042ce9d  5e                   pop esi
// 0042ce9e  c3                   ret 
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeCtrlView.cpp (function ?PreSubclassWindow@CXTPTreeViewBase@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeCtrlView.cpp
