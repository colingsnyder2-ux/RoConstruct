// from server: 100% by auto
// roc 2011-06 00817f00  unit: CXTPControlComboBoxPopupBar  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00817f00
//
// 00817f00  56                   push esi
// 00817f01  57                   push edi
// 00817f02  8bf9                 mov edi, ecx
// 00817f04  e887ffffff           call 0x817e90
// 00817f09  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00817f0d  8bf0                 mov esi, eax
// 00817f0f  8b06                 mov eax, dword ptr [esi]
// 00817f11  8b90dc010000         mov edx, dword ptr [eax + 0x1dc]
// 00817f17  51                   push ecx
// 00817f18  57                   push edi
// 00817f19  8bce                 mov ecx, esi
// 00817f1b  ffd2                 call edx
// 00817f1d  5f                   pop edi
// 00817f1e  8bc6                 mov eax, esi
// 00817f20  5e                   pop esi
// 00817f21  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPCustomizeMenusPage.cpp (function ?Clone@CXTPFloatingPopupBar@@UAEPAVCXTPCommandBar@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPCustomizeMenusPage.cpp
