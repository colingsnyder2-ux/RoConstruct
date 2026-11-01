// from server: 100% by auto
// roc 2007-03 00638b00  unit: seg_00630000  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00638b00
//
// 00638b00  8b01                 mov eax, dword ptr [ecx]
// 00638b02  8b9040010000         mov edx, dword ptr [eax + 0x140]
// 00638b08  6a00                 push 0
// 00638b0a  6a01                 push 1
// 00638b0c  6a00                 push 0
// 00638b0e  ffd2                 call edx
// 00638b10  c3                   ret 
// library xtp-15.2.1/Source\Ribbon\XTPRibbonBackstageView.cpp (function ?OnCancel@CXTPRibbonBackstageView@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonBackstageView.cpp
