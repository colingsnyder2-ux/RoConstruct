// from server: 100% by auto
// roc 2011-06 008862d0  unit: CXTPControlComboBoxGalleryPopupBar  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008862d0
//
// 008862d0  56                   push esi
// 008862d1  57                   push edi
// 008862d2  8bf9                 mov edi, ecx
// 008862d4  e887ffffff           call 0x886260
// 008862d9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008862dd  8bf0                 mov esi, eax
// 008862df  8b06                 mov eax, dword ptr [esi]
// 008862e1  8b90dc010000         mov edx, dword ptr [eax + 0x1dc]
// 008862e7  51                   push ecx
// 008862e8  57                   push edi
// 008862e9  8bce                 mov ecx, esi
// 008862eb  ffd2                 call edx
// 008862ed  5f                   pop edi
// 008862ee  8bc6                 mov eax, esi
// 008862f0  5e                   pop esi
// 008862f1  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPCustomizeMenusPage.cpp (function ?Clone@CXTPFloatingPopupBar@@UAEPAVCXTPCommandBar@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPCustomizeMenusPage.cpp
