// from server: 100% by auto
// roc 2010-06 00848320  unit: CXTPMenuBar  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00848320
//
// 00848320  56                   push esi
// 00848321  57                   push edi
// 00848322  8bf9                 mov edi, ecx
// 00848324  e887ffffff           call 0x8482b0
// 00848329  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0084832d  8bf0                 mov esi, eax
// 0084832f  8b06                 mov eax, dword ptr [esi]
// 00848331  8b90dc010000         mov edx, dword ptr [eax + 0x1dc]
// 00848337  51                   push ecx
// 00848338  57                   push edi
// 00848339  8bce                 mov ecx, esi
// 0084833b  ffd2                 call edx
// 0084833d  5f                   pop edi
// 0084833e  8bc6                 mov eax, esi
// 00848340  5e                   pop esi
// 00848341  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\Ribbon\XTPRibbonPopups.cpp (function ?Clone@CXTPRibbonGroupPopupToolBar@@UAEPAVCXTPCommandBar@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Ribbon/XTPRibbonPopups.cpp
