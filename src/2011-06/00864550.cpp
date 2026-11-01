// from server: 100% by auto
// roc 2011-06 00864550  unit: CXTPTabClientWnd  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00864550
//
// 00864550  56                   push esi
// 00864551  57                   push edi
// 00864552  8bf1                 mov esi, ecx
// 00864554  e8d560faff           call 0x80a62e
// 00864559  8bf8                 mov edi, eax
// 0086455b  8b06                 mov eax, dword ptr [esi]
// 0086455d  8b9044010000         mov edx, dword ptr [eax + 0x144]
// 00864563  8bce                 mov ecx, esi
// 00864565  ffd2                 call edx
// 00864567  8bc7                 mov eax, edi
// 00864569  5f                   pop edi
// 0086456a  5e                   pop esi
// 0086456b  c20800               ret 8
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPTabClientWnd.cpp (function ?OnMDINext@CXTPTabClientWnd@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPTabClientWnd.cpp
