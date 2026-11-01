// from server: 100% by auto
// roc 2010-06 0084c4b0  unit: CXTPRibbonBar  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0084c4b0
//
// 0084c4b0  56                   push esi
// 0084c4b1  57                   push edi
// 0084c4b2  8bf9                 mov edi, ecx
// 0084c4b4  e887ffffff           call 0x84c440
// 0084c4b9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0084c4bd  8bf0                 mov esi, eax
// 0084c4bf  8b06                 mov eax, dword ptr [esi]
// 0084c4c1  8b90dc010000         mov edx, dword ptr [eax + 0x1dc]
// 0084c4c7  51                   push ecx
// 0084c4c8  57                   push edi
// 0084c4c9  8bce                 mov ecx, esi
// 0084c4cb  ffd2                 call edx
// 0084c4cd  5f                   pop edi
// 0084c4ce  8bc6                 mov eax, esi
// 0084c4d0  5e                   pop esi
// 0084c4d1  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\Ribbon\XTPRibbonPopups.cpp (function ?Clone@CXTPRibbonGroupPopupToolBar@@UAEPAVCXTPCommandBar@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Ribbon/XTPRibbonPopups.cpp
