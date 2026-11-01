// from server: 100% by auto
// roc 2011-06 00864280  unit: CXTPControlTabWorkspace  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00864280
//
// 00864280  8b4988               mov ecx, dword ptr [ecx - 0x78]
// 00864283  8b01                 mov eax, dword ptr [ecx]
// 00864285  8b80ac010000         mov eax, dword ptr [eax + 0x1ac]
// 0086428b  ffe0                 jmp eax
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPTabClientWnd.cpp (function ?RedrawControl@CXTPControlTabWorkspace@@UAEXPBUtagRECT@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPTabClientWnd.cpp
