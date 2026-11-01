// from server: 100% by auto
// roc 2009-12 0041fb90  unit: CXTTreeCtrl  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0041fb90
//
// 0041fb90  56                   push esi
// 0041fb91  8bf1                 mov esi, ecx
// 0041fb93  e82e3d3d00           call 0x7f38c6
// 0041fb98  80be9000000000       cmp byte ptr [esi + 0x90], 0
// 0041fb9f  740c                 je 0x41fbad
// 0041fba1  8b4654               mov eax, dword ptr [esi + 0x54]
// 0041fba4  8b5048               mov edx, dword ptr [eax + 0x48]
// 0041fba7  8d4e54               lea ecx, [esi + 0x54]
// 0041fbaa  5e                   pop esi
// 0041fbab  ffe2                 jmp edx
// 0041fbad  5e                   pop esi
// 0041fbae  c3                   ret 
// library xtp-15.2.1/Source\Controls\Tree\XTPMarkupTreeCtrl.cpp (function ?PreSubclassWindow@CXTPTreeCtrlBase@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPMarkupTreeCtrl.cpp
