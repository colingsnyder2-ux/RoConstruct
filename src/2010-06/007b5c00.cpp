// from server: 100% by auto
// roc 2010-06 007b5c00  unit: CXTPControlComboBoxList  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007b5c00
//
// 007b5c00  56                   push esi
// 007b5c01  57                   push edi
// 007b5c02  8bf9                 mov edi, ecx
// 007b5c04  e887ffffff           call 0x7b5b90
// 007b5c09  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007b5c0d  8bf0                 mov esi, eax
// 007b5c0f  8b06                 mov eax, dword ptr [esi]
// 007b5c11  8b90dc010000         mov edx, dword ptr [eax + 0x1dc]
// 007b5c17  51                   push ecx
// 007b5c18  57                   push edi
// 007b5c19  8bce                 mov ecx, esi
// 007b5c1b  ffd2                 call edx
// 007b5c1d  5f                   pop edi
// 007b5c1e  8bc6                 mov eax, esi
// 007b5c20  5e                   pop esi
// 007b5c21  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\Ribbon\XTPRibbonPopups.cpp (function ?Clone@CXTPRibbonGroupPopupToolBar@@UAEPAVCXTPCommandBar@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Ribbon/XTPRibbonPopups.cpp
