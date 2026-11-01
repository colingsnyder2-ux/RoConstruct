// from server: 100% by auto
// roc 2011-06 008ff7b0  unit: CXTPRibbonSystemPopupBarPage  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008ff7b0
//
// 008ff7b0  56                   push esi
// 008ff7b1  57                   push edi
// 008ff7b2  8bf9                 mov edi, ecx
// 008ff7b4  e887ffffff           call 0x8ff740
// 008ff7b9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008ff7bd  8bf0                 mov esi, eax
// 008ff7bf  8b06                 mov eax, dword ptr [esi]
// 008ff7c1  8b90dc010000         mov edx, dword ptr [eax + 0x1dc]
// 008ff7c7  51                   push ecx
// 008ff7c8  57                   push edi
// 008ff7c9  8bce                 mov ecx, esi
// 008ff7cb  ffd2                 call edx
// 008ff7cd  5f                   pop edi
// 008ff7ce  8bc6                 mov eax, esi
// 008ff7d0  5e                   pop esi
// 008ff7d1  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPCustomizeMenusPage.cpp (function ?Clone@CXTPFloatingPopupBar@@UAEPAVCXTPCommandBar@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPCustomizeMenusPage.cpp
