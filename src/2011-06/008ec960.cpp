// from server: 100% by auto
// roc 2011-06 008ec960  unit: CXTPRichRender::XTextHost  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008ec960
//
// 008ec960  83ec10               sub esp, 0x10
// 008ec963  56                   push esi
// 008ec964  8bf1                 mov esi, ecx
// 008ec966  8b46fc               mov eax, dword ptr [esi - 4]
// 008ec969  50                   push eax
// 008ec96a  8d4c2408             lea ecx, [esp + 8]
// 008ec96e  e8bbd9f1ff           call 0x80a32e
// 008ec973  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008ec977  8b442408             mov eax, dword ptr [esp + 8]
// 008ec97b  83c664               add esi, 0x64
// 008ec97e  8931                 mov dword ptr [ecx], esi
// 008ec980  5e                   pop esi
// 008ec981  85c0                 test eax, eax
// 008ec983  7406                 je 0x8ec98b
// 008ec985  8b1424               mov edx, dword ptr [esp]
// 008ec988  895004               mov dword ptr [eax + 4], edx
// 008ec98b  837c240c00           cmp dword ptr [esp + 0xc], 0
// 008ec990  740c                 je 0x8ec99e
// 008ec992  8b442408             mov eax, dword ptr [esp + 8]
// 008ec996  50                   push eax
// 008ec997  6a00                 push 0
// 008ec999  e884d9f1ff           call 0x80a322
// 008ec99e  33c0                 xor eax, eax
// 008ec9a0  83c410               add esp, 0x10
// 008ec9a3  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\Common\XTPRichRender.cpp (function ?TxGetParaFormat@XTextHost@CXTPRichRender@@UAEJPAPBU_paraformat@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPRichRender.cpp
