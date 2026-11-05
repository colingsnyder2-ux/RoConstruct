// from server: 100% by auto
// roc 2010-06 007f9070  unit: CXTPPopupBar  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007f9070
//
// 007f9070  56                   push esi
// 007f9071  57                   push edi
// 007f9072  8bf9                 mov edi, ecx
// 007f9074  e887ffffff           call 0x7f9000
// 007f9079  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007f907d  8bf0                 mov esi, eax
// 007f907f  8b06                 mov eax, dword ptr [esi]
// 007f9081  8b90dc010000         mov edx, dword ptr [eax + 0x1dc]
// 007f9087  51                   push ecx
// 007f9088  57                   push edi
// 007f9089  8bce                 mov ecx, esi
// 007f908b  ffd2                 call edx
// 007f908d  5f                   pop edi
// 007f908e  8bc6                 mov eax, esi
// 007f9090  5e                   pop esi
// 007f9091  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\Ribbon\XTPRibbonPopups.cpp (function ?Clone@CXTPRibbonGroupPopupToolBar@@UAEPAVCXTPCommandBar@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Ribbon/XTPRibbonPopups.cpp
