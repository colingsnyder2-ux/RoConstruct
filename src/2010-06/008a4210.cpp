// from server: 100% by auto
// roc 2010-06 008a4210  unit: CXTPRibbonGroupPopupToolBar  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a4210
//
// 008a4210  56                   push esi
// 008a4211  57                   push edi
// 008a4212  8bf9                 mov edi, ecx
// 008a4214  e887ffffff           call 0x8a41a0
// 008a4219  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008a421d  8bf0                 mov esi, eax
// 008a421f  8b06                 mov eax, dword ptr [esi]
// 008a4221  8b90dc010000         mov edx, dword ptr [eax + 0x1dc]
// 008a4227  51                   push ecx
// 008a4228  57                   push edi
// 008a4229  8bce                 mov ecx, esi
// 008a422b  ffd2                 call edx
// 008a422d  5f                   pop edi
// 008a422e  8bc6                 mov eax, esi
// 008a4230  5e                   pop esi
// 008a4231  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\Ribbon\XTPRibbonPopups.cpp (function ?Clone@CXTPRibbonGroupPopupToolBar@@UAEPAVCXTPCommandBar@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Ribbon/XTPRibbonPopups.cpp
