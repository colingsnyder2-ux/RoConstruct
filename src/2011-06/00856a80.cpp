// from server: 100% by auto
// roc 2011-06 00856a80  unit: CXTPPopupToolBar  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00856a80
//
// 00856a80  56                   push esi
// 00856a81  57                   push edi
// 00856a82  8bf9                 mov edi, ecx
// 00856a84  e887ffffff           call 0x856a10
// 00856a89  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00856a8d  8bf0                 mov esi, eax
// 00856a8f  8b06                 mov eax, dword ptr [esi]
// 00856a91  8b90dc010000         mov edx, dword ptr [eax + 0x1dc]
// 00856a97  51                   push ecx
// 00856a98  57                   push edi
// 00856a99  8bce                 mov ecx, esi
// 00856a9b  ffd2                 call edx
// 00856a9d  5f                   pop edi
// 00856a9e  8bc6                 mov eax, esi
// 00856aa0  5e                   pop esi
// 00856aa1  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPCustomizeMenusPage.cpp (function ?Clone@CXTPFloatingPopupBar@@UAEPAVCXTPCommandBar@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPCustomizeMenusPage.cpp
