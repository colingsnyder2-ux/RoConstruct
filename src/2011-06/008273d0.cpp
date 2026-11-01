// from server: 100% by auto
// roc 2011-06 008273d0  unit: CXTPToolBar  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008273d0
//
// 008273d0  56                   push esi
// 008273d1  57                   push edi
// 008273d2  8bf9                 mov edi, ecx
// 008273d4  e887ffffff           call 0x827360
// 008273d9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008273dd  8bf0                 mov esi, eax
// 008273df  8b06                 mov eax, dword ptr [esi]
// 008273e1  8b90dc010000         mov edx, dword ptr [eax + 0x1dc]
// 008273e7  51                   push ecx
// 008273e8  57                   push edi
// 008273e9  8bce                 mov ecx, esi
// 008273eb  ffd2                 call edx
// 008273ed  5f                   pop edi
// 008273ee  8bc6                 mov eax, esi
// 008273f0  5e                   pop esi
// 008273f1  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPCustomizeMenusPage.cpp (function ?Clone@CXTPFloatingPopupBar@@UAEPAVCXTPCommandBar@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPCustomizeMenusPage.cpp
