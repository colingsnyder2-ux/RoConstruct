// from server: 100% by auto
// roc 2010-06 0041fa20  unit: CXTTreeCtrl  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0041fa20
//
// 0041fa20  56                   push esi
// 0041fa21  8bf1                 mov esi, ecx
// 0041fa23  e8de7f3800           call 0x7a7a06
// 0041fa28  80be9000000000       cmp byte ptr [esi + 0x90], 0
// 0041fa2f  740c                 je 0x41fa3d
// 0041fa31  8b4654               mov eax, dword ptr [esi + 0x54]
// 0041fa34  8b5048               mov edx, dword ptr [eax + 0x48]
// 0041fa37  8d4e54               lea ecx, [esi + 0x54]
// 0041fa3a  5e                   pop esi
// 0041fa3b  ffe2                 jmp edx
// 0041fa3d  5e                   pop esi
// 0041fa3e  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTTreeCtrlView.cpp (function ?PreSubclassWindow@CXTTreeCtrlBase@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeCtrlView.cpp
