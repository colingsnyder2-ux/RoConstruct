// from server: 100% by auto
// roc 2010-06 00893d80  unit: CXTPRichRender::XTextHost  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00893d80
//
// 00893d80  83ec10               sub esp, 0x10
// 00893d83  56                   push esi
// 00893d84  8bf1                 mov esi, ecx
// 00893d86  8b46fc               mov eax, dword ptr [esi - 4]
// 00893d89  50                   push eax
// 00893d8a  8d4c2408             lea ecx, [esp + 8]
// 00893d8e  e8dd3ef1ff           call 0x7a7c70
// 00893d93  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00893d97  8b442408             mov eax, dword ptr [esp + 8]
// 00893d9b  83c664               add esi, 0x64
// 00893d9e  8931                 mov dword ptr [ecx], esi
// 00893da0  5e                   pop esi
// 00893da1  85c0                 test eax, eax
// 00893da3  7406                 je 0x893dab
// 00893da5  8b1424               mov edx, dword ptr [esp]
// 00893da8  895004               mov dword ptr [eax + 4], edx
// 00893dab  837c240c00           cmp dword ptr [esp + 0xc], 0
// 00893db0  740c                 je 0x893dbe
// 00893db2  8b442408             mov eax, dword ptr [esp + 8]
// 00893db6  50                   push eax
// 00893db7  6a00                 push 0
// 00893db9  e8a63ef1ff           call 0x7a7c64
// 00893dbe  33c0                 xor eax, eax
// 00893dc0  83c410               add esp, 0x10
// 00893dc3  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\Common\XTPRichRender.cpp (function ?TxGetParaFormat@XTextHost@CXTPRichRender@@UAEJPAPBU_paraformat@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPRichRender.cpp
