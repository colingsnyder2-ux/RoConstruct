// from server: 100% by auto
// roc 2010-06 00893d30  unit: CXTPRichRender::XTextHost  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00893d30
//
// 00893d30  83ec10               sub esp, 0x10
// 00893d33  56                   push esi
// 00893d34  8bf1                 mov esi, ecx
// 00893d36  8b46fc               mov eax, dword ptr [esi - 4]
// 00893d39  50                   push eax
// 00893d3a  8d4c2408             lea ecx, [esp + 8]
// 00893d3e  e82d3ff1ff           call 0x7a7c70
// 00893d43  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00893d47  8b442408             mov eax, dword ptr [esp + 8]
// 00893d4b  83c608               add esi, 8
// 00893d4e  8931                 mov dword ptr [ecx], esi
// 00893d50  5e                   pop esi
// 00893d51  85c0                 test eax, eax
// 00893d53  7406                 je 0x893d5b
// 00893d55  8b1424               mov edx, dword ptr [esp]
// 00893d58  895004               mov dword ptr [eax + 4], edx
// 00893d5b  837c240c00           cmp dword ptr [esp + 0xc], 0
// 00893d60  740c                 je 0x893d6e
// 00893d62  8b442408             mov eax, dword ptr [esp + 8]
// 00893d66  50                   push eax
// 00893d67  6a00                 push 0
// 00893d69  e8f63ef1ff           call 0x7a7c64
// 00893d6e  33c0                 xor eax, eax
// 00893d70  83c410               add esp, 0x10
// 00893d73  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\Common\XTPRichRender.cpp (function ?TxGetCharFormat@XTextHost@CXTPRichRender@@UAEJPAPBU_charformatw@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPRichRender.cpp
