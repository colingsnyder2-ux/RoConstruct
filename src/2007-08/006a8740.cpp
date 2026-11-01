// from server: 100% by auto
// roc 2007-08 006a8740  unit: CXTPRibbonBar::CMorePopupToolBar  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006a8740
//
// 006a8740  8b8948020000         mov ecx, dword ptr [ecx + 0x248]
// 006a8746  8b01                 mov eax, dword ptr [ecx]
// 006a8748  8b9050010000         mov edx, dword ptr [eax + 0x150]
// 006a874e  56                   push esi
// 006a874f  8b742408             mov esi, dword ptr [esp + 8]
// 006a8753  56                   push esi
// 006a8754  ffd2                 call edx
// 006a8756  8bc6                 mov eax, esi
// 006a8758  5e                   pop esi
// 006a8759  c20400               ret 4
// library xtp-13.2.1/Source\Ribbon\XTPRibbonPopups.cpp (function ?GetIconSize@CXTPRibbonTabPopupToolBar@@UBE?AVCSize@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Ribbon/XTPRibbonPopups.cpp
