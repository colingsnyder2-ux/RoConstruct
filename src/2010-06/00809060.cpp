// from server: 100% by auto
// roc 2010-06 00809060  unit: CXTPTabClientWnd  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00809060
//
// 00809060  56                   push esi
// 00809061  57                   push edi
// 00809062  8bf1                 mov esi, ecx
// 00809064  e807eff9ff           call 0x7a7f70
// 00809069  8bf8                 mov edi, eax
// 0080906b  8b06                 mov eax, dword ptr [esi]
// 0080906d  8b9044010000         mov edx, dword ptr [eax + 0x144]
// 00809073  8bce                 mov ecx, esi
// 00809075  ffd2                 call edx
// 00809077  8bc7                 mov eax, edi
// 00809079  5f                   pop edi
// 0080907a  5e                   pop esi
// 0080907b  c20800               ret 8
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPTabClientWnd.cpp (function ?OnMDINext@CXTPTabClientWnd@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPTabClientWnd.cpp
