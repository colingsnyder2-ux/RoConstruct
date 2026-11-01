// from server: 100% by auto
// roc 2011-06 008a5460  unit: CXTPMenuBar  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008a5460
//
// 008a5460  56                   push esi
// 008a5461  57                   push edi
// 008a5462  8bf9                 mov edi, ecx
// 008a5464  e887ffffff           call 0x8a53f0
// 008a5469  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008a546d  8bf0                 mov esi, eax
// 008a546f  8b06                 mov eax, dword ptr [esi]
// 008a5471  8b90dc010000         mov edx, dword ptr [eax + 0x1dc]
// 008a5477  51                   push ecx
// 008a5478  57                   push edi
// 008a5479  8bce                 mov ecx, esi
// 008a547b  ffd2                 call edx
// 008a547d  5f                   pop edi
// 008a547e  8bc6                 mov eax, esi
// 008a5480  5e                   pop esi
// 008a5481  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPCustomizeMenusPage.cpp (function ?Clone@CXTPFloatingPopupBar@@UAEPAVCXTPCommandBar@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPCustomizeMenusPage.cpp
