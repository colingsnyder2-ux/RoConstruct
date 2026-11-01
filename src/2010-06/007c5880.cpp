// from server: 100% by auto
// roc 2010-06 007c5880  unit: CXTPToolBar  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c5880
//
// 007c5880  56                   push esi
// 007c5881  57                   push edi
// 007c5882  8bf9                 mov edi, ecx
// 007c5884  e887ffffff           call 0x7c5810
// 007c5889  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007c588d  8bf0                 mov esi, eax
// 007c588f  8b06                 mov eax, dword ptr [esi]
// 007c5891  8b90dc010000         mov edx, dword ptr [eax + 0x1dc]
// 007c5897  51                   push ecx
// 007c5898  57                   push edi
// 007c5899  8bce                 mov ecx, esi
// 007c589b  ffd2                 call edx
// 007c589d  5f                   pop edi
// 007c589e  8bc6                 mov eax, esi
// 007c58a0  5e                   pop esi
// 007c58a1  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\Ribbon\XTPRibbonPopups.cpp (function ?Clone@CXTPRibbonGroupPopupToolBar@@UAEPAVCXTPCommandBar@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Ribbon/XTPRibbonPopups.cpp
