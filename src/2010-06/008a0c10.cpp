// from server: 100% by auto
// roc 2010-06 008a0c10  unit: CXTPDialogBar  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a0c10
//
// 008a0c10  56                   push esi
// 008a0c11  57                   push edi
// 008a0c12  8bf9                 mov edi, ecx
// 008a0c14  e887ffffff           call 0x8a0ba0
// 008a0c19  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008a0c1d  8bf0                 mov esi, eax
// 008a0c1f  8b06                 mov eax, dword ptr [esi]
// 008a0c21  8b90dc010000         mov edx, dword ptr [eax + 0x1dc]
// 008a0c27  51                   push ecx
// 008a0c28  57                   push edi
// 008a0c29  8bce                 mov ecx, esi
// 008a0c2b  ffd2                 call edx
// 008a0c2d  5f                   pop edi
// 008a0c2e  8bc6                 mov eax, esi
// 008a0c30  5e                   pop esi
// 008a0c31  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\Ribbon\XTPRibbonPopups.cpp (function ?Clone@CXTPRibbonGroupPopupToolBar@@UAEPAVCXTPCommandBar@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Ribbon/XTPRibbonPopups.cpp
