// from server: 100% by auto
// roc 2010-06 00829240  unit: CXTPControlComboBoxGalleryPopupBar  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00829240
//
// 00829240  56                   push esi
// 00829241  57                   push edi
// 00829242  8bf9                 mov edi, ecx
// 00829244  e887ffffff           call 0x8291d0
// 00829249  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0082924d  8bf0                 mov esi, eax
// 0082924f  8b06                 mov eax, dword ptr [esi]
// 00829251  8b90dc010000         mov edx, dword ptr [eax + 0x1dc]
// 00829257  51                   push ecx
// 00829258  57                   push edi
// 00829259  8bce                 mov ecx, esi
// 0082925b  ffd2                 call edx
// 0082925d  5f                   pop edi
// 0082925e  8bc6                 mov eax, esi
// 00829260  5e                   pop esi
// 00829261  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\Ribbon\XTPRibbonPopups.cpp (function ?Clone@CXTPRibbonGroupPopupToolBar@@UAEPAVCXTPCommandBar@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Ribbon/XTPRibbonPopups.cpp
