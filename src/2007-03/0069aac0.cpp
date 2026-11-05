// from server: 100% by auto
// roc 2007-03 0069aac0  unit: seg_00690000  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0069aac0
//
// 0069aac0  8b8948020000         mov ecx, dword ptr [ecx + 0x248]
// 0069aac6  8b01                 mov eax, dword ptr [ecx]
// 0069aac8  8b9054010000         mov edx, dword ptr [eax + 0x154]
// 0069aace  56                   push esi
// 0069aacf  8b742408             mov esi, dword ptr [esp + 8]
// 0069aad3  56                   push esi
// 0069aad4  ffd2                 call edx
// 0069aad6  8bc6                 mov eax, esi
// 0069aad8  5e                   pop esi
// 0069aad9  c20400               ret 4
// library xtp-13.2.1/Source\Ribbon\XTPRibbonPopups.cpp (function ?GetButtonSize@CXTPRibbonTabPopupToolBar@@UBE?AVCSize@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Ribbon/XTPRibbonPopups.cpp
