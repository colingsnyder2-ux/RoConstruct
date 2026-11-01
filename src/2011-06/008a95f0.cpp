// from server: 100% by auto
// roc 2011-06 008a95f0  unit: CXTPRibbonBar  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008a95f0
//
// 008a95f0  56                   push esi
// 008a95f1  57                   push edi
// 008a95f2  8bf9                 mov edi, ecx
// 008a95f4  e887ffffff           call 0x8a9580
// 008a95f9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008a95fd  8bf0                 mov esi, eax
// 008a95ff  8b06                 mov eax, dword ptr [esi]
// 008a9601  8b90dc010000         mov edx, dword ptr [eax + 0x1dc]
// 008a9607  51                   push ecx
// 008a9608  57                   push edi
// 008a9609  8bce                 mov ecx, esi
// 008a960b  ffd2                 call edx
// 008a960d  5f                   pop edi
// 008a960e  8bc6                 mov eax, esi
// 008a9610  5e                   pop esi
// 008a9611  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPCustomizeMenusPage.cpp (function ?Clone@CXTPFloatingPopupBar@@UAEPAVCXTPCommandBar@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPCustomizeMenusPage.cpp
