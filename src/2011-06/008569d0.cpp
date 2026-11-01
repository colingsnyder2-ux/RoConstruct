// from server: 100% by auto
// roc 2011-06 008569d0  unit: CXTPPopupBar  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008569d0
//
// 008569d0  56                   push esi
// 008569d1  57                   push edi
// 008569d2  8bf9                 mov edi, ecx
// 008569d4  e887ffffff           call 0x856960
// 008569d9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008569dd  8bf0                 mov esi, eax
// 008569df  8b06                 mov eax, dword ptr [esi]
// 008569e1  8b90dc010000         mov edx, dword ptr [eax + 0x1dc]
// 008569e7  51                   push ecx
// 008569e8  57                   push edi
// 008569e9  8bce                 mov ecx, esi
// 008569eb  ffd2                 call edx
// 008569ed  5f                   pop edi
// 008569ee  8bc6                 mov eax, esi
// 008569f0  5e                   pop esi
// 008569f1  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPCustomizeMenusPage.cpp (function ?Clone@CXTPFloatingPopupBar@@UAEPAVCXTPCommandBar@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPCustomizeMenusPage.cpp
