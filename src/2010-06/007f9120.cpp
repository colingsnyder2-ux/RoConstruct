// from server: 100% by auto
// roc 2010-06 007f9120  unit: CXTPPopupToolBar  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007f9120
//
// 007f9120  56                   push esi
// 007f9121  57                   push edi
// 007f9122  8bf9                 mov edi, ecx
// 007f9124  e887ffffff           call 0x7f90b0
// 007f9129  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007f912d  8bf0                 mov esi, eax
// 007f912f  8b06                 mov eax, dword ptr [esi]
// 007f9131  8b90dc010000         mov edx, dword ptr [eax + 0x1dc]
// 007f9137  51                   push ecx
// 007f9138  57                   push edi
// 007f9139  8bce                 mov ecx, esi
// 007f913b  ffd2                 call edx
// 007f913d  5f                   pop edi
// 007f913e  8bc6                 mov eax, esi
// 007f9140  5e                   pop esi
// 007f9141  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\Ribbon\XTPRibbonPopups.cpp (function ?Clone@CXTPRibbonGroupPopupToolBar@@UAEPAVCXTPCommandBar@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Ribbon/XTPRibbonPopups.cpp
