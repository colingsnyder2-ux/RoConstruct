// from server: 100% by auto
// roc 2011-06 0081a860  unit: CXTPCommandBar  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0081a860
//
// 0081a860  8b01                 mov eax, dword ptr [ecx]
// 0081a862  8b9048010000         mov edx, dword ptr [eax + 0x148]
// 0081a868  6a00                 push 0
// 0081a86a  6a01                 push 1
// 0081a86c  6a00                 push 0
// 0081a86e  ffd2                 call edx
// 0081a870  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\Ribbon\XTPRibbonBackstageView.cpp (function ?OnCancel@CXTPRibbonBackstageView@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Ribbon/XTPRibbonBackstageView.cpp
