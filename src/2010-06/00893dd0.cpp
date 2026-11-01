// from server: 100% by auto
// roc 2010-06 00893dd0  unit: CXTPRichRender::XTextHost  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00893dd0
//
// 00893dd0  83ec10               sub esp, 0x10
// 00893dd3  56                   push esi
// 00893dd4  8bf1                 mov esi, ecx
// 00893dd6  8b46fc               mov eax, dword ptr [esi - 4]
// 00893dd9  50                   push eax
// 00893dda  8d4c2408             lea ecx, [esp + 8]
// 00893dde  e88d3ef1ff           call 0x7a7c70
// 00893de3  817c241801070000     cmp dword ptr [esp + 0x18], 0x701
// 00893deb  751c                 jne 0x893e09
// 00893ded  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00893df1  8b4814               mov ecx, dword ptr [eax + 0x14]
// 00893df4  2b480c               sub ecx, dword ptr [eax + 0xc]
// 00893df7  898e04010000         mov dword ptr [esi + 0x104], ecx
// 00893dfd  8b5018               mov edx, dword ptr [eax + 0x18]
// 00893e00  2b5010               sub edx, dword ptr [eax + 0x10]
// 00893e03  899608010000         mov dword ptr [esi + 0x108], edx
// 00893e09  8b442408             mov eax, dword ptr [esp + 8]
// 00893e0d  5e                   pop esi
// 00893e0e  85c0                 test eax, eax
// 00893e10  7406                 je 0x893e18
// 00893e12  8b0c24               mov ecx, dword ptr [esp]
// 00893e15  894804               mov dword ptr [eax + 4], ecx
// 00893e18  837c240c00           cmp dword ptr [esp + 0xc], 0
// 00893e1d  740c                 je 0x893e2b
// 00893e1f  8b542408             mov edx, dword ptr [esp + 8]
// 00893e23  52                   push edx
// 00893e24  6a00                 push 0
// 00893e26  e8393ef1ff           call 0x7a7c64
// 00893e2b  33c0                 xor eax, eax
// 00893e2d  83c410               add esp, 0x10
// 00893e30  c20800               ret 8
// library xtp-13.2.1-shared-mfc/Source\Common\XTPRichRender.cpp (function ?TxNotify@XTextHost@CXTPRichRender@@UAEJKPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPRichRender.cpp
