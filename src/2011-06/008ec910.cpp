// from server: 100% by auto
// roc 2011-06 008ec910  unit: CXTPRichRender::XTextHost  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008ec910
//
// 008ec910  83ec10               sub esp, 0x10
// 008ec913  56                   push esi
// 008ec914  8bf1                 mov esi, ecx
// 008ec916  8b46fc               mov eax, dword ptr [esi - 4]
// 008ec919  50                   push eax
// 008ec91a  8d4c2408             lea ecx, [esp + 8]
// 008ec91e  e80bdaf1ff           call 0x80a32e
// 008ec923  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008ec927  8b442408             mov eax, dword ptr [esp + 8]
// 008ec92b  83c608               add esi, 8
// 008ec92e  8931                 mov dword ptr [ecx], esi
// 008ec930  5e                   pop esi
// 008ec931  85c0                 test eax, eax
// 008ec933  7406                 je 0x8ec93b
// 008ec935  8b1424               mov edx, dword ptr [esp]
// 008ec938  895004               mov dword ptr [eax + 4], edx
// 008ec93b  837c240c00           cmp dword ptr [esp + 0xc], 0
// 008ec940  740c                 je 0x8ec94e
// 008ec942  8b442408             mov eax, dword ptr [esp + 8]
// 008ec946  50                   push eax
// 008ec947  6a00                 push 0
// 008ec949  e8d4d9f1ff           call 0x80a322
// 008ec94e  33c0                 xor eax, eax
// 008ec950  83c410               add esp, 0x10
// 008ec953  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\Common\XTPRichRender.cpp (function ?TxGetCharFormat@XTextHost@CXTPRichRender@@UAEJPAPBU_charformatw@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPRichRender.cpp
