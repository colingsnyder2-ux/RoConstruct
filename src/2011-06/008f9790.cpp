// from server: 100% by auto
// roc 2011-06 008f9790  unit: CXTPDialogBar  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008f9790
//
// 008f9790  56                   push esi
// 008f9791  57                   push edi
// 008f9792  8bf9                 mov edi, ecx
// 008f9794  e887ffffff           call 0x8f9720
// 008f9799  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008f979d  8bf0                 mov esi, eax
// 008f979f  8b06                 mov eax, dword ptr [esi]
// 008f97a1  8b90dc010000         mov edx, dword ptr [eax + 0x1dc]
// 008f97a7  51                   push ecx
// 008f97a8  57                   push edi
// 008f97a9  8bce                 mov ecx, esi
// 008f97ab  ffd2                 call edx
// 008f97ad  5f                   pop edi
// 008f97ae  8bc6                 mov eax, esi
// 008f97b0  5e                   pop esi
// 008f97b1  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPCustomizeMenusPage.cpp (function ?Clone@CXTPFloatingPopupBar@@UAEPAVCXTPCommandBar@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPCustomizeMenusPage.cpp
