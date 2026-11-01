// from server: 100% by auto
// roc 2007-08 00643750  unit: CXTPCommandBar::CCommandBarCmdUI  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00643750
//
// 00643750  8b01                 mov eax, dword ptr [ecx]
// 00643752  8b9040010000         mov edx, dword ptr [eax + 0x140]
// 00643758  6a00                 push 0
// 0064375a  6a01                 push 1
// 0064375c  6a00                 push 0
// 0064375e  ffd2                 call edx
// 00643760  c3                   ret 
// library xtp-15.2.1/Source\Ribbon\XTPRibbonBackstageView.cpp (function ?OnCancel@CXTPRibbonBackstageView@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonBackstageView.cpp
