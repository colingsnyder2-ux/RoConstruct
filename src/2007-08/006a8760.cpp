// from server: 100% by auto
// roc 2007-08 006a8760  unit: CXTPRibbonBar::CMorePopupToolBar  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006a8760
//
// 006a8760  8b8948020000         mov ecx, dword ptr [ecx + 0x248]
// 006a8766  8b01                 mov eax, dword ptr [ecx]
// 006a8768  8b9054010000         mov edx, dword ptr [eax + 0x154]
// 006a876e  56                   push esi
// 006a876f  8b742408             mov esi, dword ptr [esp + 8]
// 006a8773  56                   push esi
// 006a8774  ffd2                 call edx
// 006a8776  8bc6                 mov eax, esi
// 006a8778  5e                   pop esi
// 006a8779  c20400               ret 4
// library xtp-13.2.1/Source\Ribbon\XTPRibbonPopups.cpp (function ?GetButtonSize@CXTPRibbonTabPopupToolBar@@UBE?AVCSize@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Ribbon/XTPRibbonPopups.cpp
