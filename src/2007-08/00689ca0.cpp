// from server: 100% by auto
// roc 2007-08 00689ca0  unit: CXTPTabClientWnd  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00689ca0
//
// 00689ca0  56                   push esi
// 00689ca1  57                   push edi
// 00689ca2  8bf1                 mov esi, ecx
// 00689ca4  e89565faff           call 0x63023e
// 00689ca9  8bf8                 mov edi, eax
// 00689cab  8b06                 mov eax, dword ptr [esi]
// 00689cad  8b903c010000         mov edx, dword ptr [eax + 0x13c]
// 00689cb3  8bce                 mov ecx, esi
// 00689cb5  ffd2                 call edx
// 00689cb7  8bc7                 mov eax, edi
// 00689cb9  5f                   pop edi
// 00689cba  5e                   pop esi
// 00689cbb  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?OnMDINext@CXTPTabClientWnd@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
