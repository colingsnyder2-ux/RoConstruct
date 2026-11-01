// from server: 100% by auto
// roc 2010-06 008a6d70  unit: CXTPRibbonSystemPopupBar  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a6d70
//
// 008a6d70  56                   push esi
// 008a6d71  57                   push edi
// 008a6d72  8bf9                 mov edi, ecx
// 008a6d74  e887ffffff           call 0x8a6d00
// 008a6d79  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008a6d7d  8bf0                 mov esi, eax
// 008a6d7f  8b06                 mov eax, dword ptr [esi]
// 008a6d81  8b90dc010000         mov edx, dword ptr [eax + 0x1dc]
// 008a6d87  51                   push ecx
// 008a6d88  57                   push edi
// 008a6d89  8bce                 mov ecx, esi
// 008a6d8b  ffd2                 call edx
// 008a6d8d  5f                   pop edi
// 008a6d8e  8bc6                 mov eax, esi
// 008a6d90  5e                   pop esi
// 008a6d91  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\Ribbon\XTPRibbonPopups.cpp (function ?Clone@CXTPRibbonGroupPopupToolBar@@UAEPAVCXTPCommandBar@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Ribbon/XTPRibbonPopups.cpp
