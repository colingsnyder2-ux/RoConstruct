// from server: 100% by auto
// roc 2011-06 008ff8f0  unit: CXTPRibbonSystemPopupBar  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008ff8f0
//
// 008ff8f0  56                   push esi
// 008ff8f1  57                   push edi
// 008ff8f2  8bf9                 mov edi, ecx
// 008ff8f4  e887ffffff           call 0x8ff880
// 008ff8f9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008ff8fd  8bf0                 mov esi, eax
// 008ff8ff  8b06                 mov eax, dword ptr [esi]
// 008ff901  8b90dc010000         mov edx, dword ptr [eax + 0x1dc]
// 008ff907  51                   push ecx
// 008ff908  57                   push edi
// 008ff909  8bce                 mov ecx, esi
// 008ff90b  ffd2                 call edx
// 008ff90d  5f                   pop edi
// 008ff90e  8bc6                 mov eax, esi
// 008ff910  5e                   pop esi
// 008ff911  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPCustomizeMenusPage.cpp (function ?Clone@CXTPFloatingPopupBar@@UAEPAVCXTPCommandBar@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPCustomizeMenusPage.cpp
