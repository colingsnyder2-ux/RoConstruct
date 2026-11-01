// from server: 100% by auto
// roc 2009-06 0041efd0  unit: CXTTreeCtrl  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0041efd0
//
// 0041efd0  56                   push esi
// 0041efd1  8bf1                 mov esi, ecx
// 0041efd3  e8c69a2f00           call 0x718a9e
// 0041efd8  80be9000000000       cmp byte ptr [esi + 0x90], 0
// 0041efdf  740c                 je 0x41efed
// 0041efe1  8b4654               mov eax, dword ptr [esi + 0x54]
// 0041efe4  8b5048               mov edx, dword ptr [eax + 0x48]
// 0041efe7  8d4e54               lea ecx, [esi + 0x54]
// 0041efea  5e                   pop esi
// 0041efeb  ffe2                 jmp edx
// 0041efed  5e                   pop esi
// 0041efee  c3                   ret 
// library xtp-15.2.1/Source\Controls\Tree\XTPMarkupTreeCtrl.cpp (function ?PreSubclassWindow@CXTPTreeCtrlBase@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPMarkupTreeCtrl.cpp
