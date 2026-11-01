// from server: 100% by auto
// roc 2011-06 008fcdc0  unit: CXTPRibbonGroupPopupToolBar  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008fcdc0
//
// 008fcdc0  56                   push esi
// 008fcdc1  57                   push edi
// 008fcdc2  8bf9                 mov edi, ecx
// 008fcdc4  e887ffffff           call 0x8fcd50
// 008fcdc9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008fcdcd  8bf0                 mov esi, eax
// 008fcdcf  8b06                 mov eax, dword ptr [esi]
// 008fcdd1  8b90dc010000         mov edx, dword ptr [eax + 0x1dc]
// 008fcdd7  51                   push ecx
// 008fcdd8  57                   push edi
// 008fcdd9  8bce                 mov ecx, esi
// 008fcddb  ffd2                 call edx
// 008fcddd  5f                   pop edi
// 008fcdde  8bc6                 mov eax, esi
// 008fcde0  5e                   pop esi
// 008fcde1  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPCustomizeMenusPage.cpp (function ?Clone@CXTPFloatingPopupBar@@UAEPAVCXTPCommandBar@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPCustomizeMenusPage.cpp
