// from server: 100% by auto
// roc 2011-06 0081c9b0  unit: CXTPCommandBar  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0081c9b0
//
// 0081c9b0  56                   push esi
// 0081c9b1  57                   push edi
// 0081c9b2  8bf9                 mov edi, ecx
// 0081c9b4  e887ffffff           call 0x81c940
// 0081c9b9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0081c9bd  8bf0                 mov esi, eax
// 0081c9bf  8b06                 mov eax, dword ptr [esi]
// 0081c9c1  8b90dc010000         mov edx, dword ptr [eax + 0x1dc]
// 0081c9c7  51                   push ecx
// 0081c9c8  57                   push edi
// 0081c9c9  8bce                 mov ecx, esi
// 0081c9cb  ffd2                 call edx
// 0081c9cd  5f                   pop edi
// 0081c9ce  8bc6                 mov eax, esi
// 0081c9d0  5e                   pop esi
// 0081c9d1  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPCustomizeMenusPage.cpp (function ?Clone@CXTPFloatingPopupBar@@UAEPAVCXTPCommandBar@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPCustomizeMenusPage.cpp
