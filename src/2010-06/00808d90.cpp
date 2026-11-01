// from server: 100% by auto
// roc 2010-06 00808d90  unit: CXTPControlTabWorkspace  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00808d90
//
// 00808d90  8b4988               mov ecx, dword ptr [ecx - 0x78]
// 00808d93  8b01                 mov eax, dword ptr [ecx]
// 00808d95  8b80ac010000         mov eax, dword ptr [eax + 0x1ac]
// 00808d9b  ffe0                 jmp eax
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPTabClientWnd.cpp (function ?RedrawControl@CXTPControlTabWorkspace@@UAEXPBUtagRECT@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPTabClientWnd.cpp
