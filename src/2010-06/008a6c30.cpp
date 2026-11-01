// from server: 100% by auto
// roc 2010-06 008a6c30  unit: CXTPRibbonSystemPopupBarPage  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a6c30
//
// 008a6c30  56                   push esi
// 008a6c31  57                   push edi
// 008a6c32  8bf9                 mov edi, ecx
// 008a6c34  e887ffffff           call 0x8a6bc0
// 008a6c39  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008a6c3d  8bf0                 mov esi, eax
// 008a6c3f  8b06                 mov eax, dword ptr [esi]
// 008a6c41  8b90dc010000         mov edx, dword ptr [eax + 0x1dc]
// 008a6c47  51                   push ecx
// 008a6c48  57                   push edi
// 008a6c49  8bce                 mov ecx, esi
// 008a6c4b  ffd2                 call edx
// 008a6c4d  5f                   pop edi
// 008a6c4e  8bc6                 mov eax, esi
// 008a6c50  5e                   pop esi
// 008a6c51  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\Ribbon\XTPRibbonPopups.cpp (function ?Clone@CXTPRibbonGroupPopupToolBar@@UAEPAVCXTPCommandBar@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Ribbon/XTPRibbonPopups.cpp
