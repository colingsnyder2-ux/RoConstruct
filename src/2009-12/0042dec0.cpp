// from server: 100% by auto
// roc 2009-12 0042dec0  unit: CClassTreeView  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0042dec0
//
// 0042dec0  56                   push esi
// 0042dec1  8bf1                 mov esi, ecx
// 0042dec3  e8fe593c00           call 0x7f38c6
// 0042dec8  80be9c00000000       cmp byte ptr [esi + 0x9c], 0
// 0042decf  740c                 je 0x42dedd
// 0042ded1  8b4660               mov eax, dword ptr [esi + 0x60]
// 0042ded4  8b5048               mov edx, dword ptr [eax + 0x48]
// 0042ded7  8d4e60               lea ecx, [esi + 0x60]
// 0042deda  5e                   pop esi
// 0042dedb  ffe2                 jmp edx
// 0042dedd  5e                   pop esi
// 0042dede  c3                   ret 
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeCtrlView.cpp (function ?PreSubclassWindow@CXTPTreeViewBase@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeCtrlView.cpp
