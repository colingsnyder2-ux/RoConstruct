// from server: 100% by auto
// roc 2011-06 00818090  unit: CXTPControlComboBoxList  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00818090
//
// 00818090  56                   push esi
// 00818091  57                   push edi
// 00818092  8bf9                 mov edi, ecx
// 00818094  e887ffffff           call 0x818020
// 00818099  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0081809d  8bf0                 mov esi, eax
// 0081809f  8b06                 mov eax, dword ptr [esi]
// 008180a1  8b90dc010000         mov edx, dword ptr [eax + 0x1dc]
// 008180a7  51                   push ecx
// 008180a8  57                   push edi
// 008180a9  8bce                 mov ecx, esi
// 008180ab  ffd2                 call edx
// 008180ad  5f                   pop edi
// 008180ae  8bc6                 mov eax, esi
// 008180b0  5e                   pop esi
// 008180b1  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPCustomizeMenusPage.cpp (function ?Clone@CXTPFloatingPopupBar@@UAEPAVCXTPCommandBar@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPCustomizeMenusPage.cpp
