// from server: 100% by auto
// roc 2010-06 007ba540  unit: CXTPCommandBar  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ba540
//
// 007ba540  56                   push esi
// 007ba541  57                   push edi
// 007ba542  8bf9                 mov edi, ecx
// 007ba544  e887ffffff           call 0x7ba4d0
// 007ba549  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007ba54d  8bf0                 mov esi, eax
// 007ba54f  8b06                 mov eax, dword ptr [esi]
// 007ba551  8b90dc010000         mov edx, dword ptr [eax + 0x1dc]
// 007ba557  51                   push ecx
// 007ba558  57                   push edi
// 007ba559  8bce                 mov ecx, esi
// 007ba55b  ffd2                 call edx
// 007ba55d  5f                   pop edi
// 007ba55e  8bc6                 mov eax, esi
// 007ba560  5e                   pop esi
// 007ba561  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\Ribbon\XTPRibbonPopups.cpp (function ?Clone@CXTPRibbonGroupPopupToolBar@@UAEPAVCXTPCommandBar@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Ribbon/XTPRibbonPopups.cpp
