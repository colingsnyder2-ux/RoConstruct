// from server: 100% by auto
// roc 2011-06 008ec9b0  unit: CXTPRichRender::XTextHost  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008ec9b0
//
// 008ec9b0  83ec10               sub esp, 0x10
// 008ec9b3  56                   push esi
// 008ec9b4  8bf1                 mov esi, ecx
// 008ec9b6  8b46fc               mov eax, dword ptr [esi - 4]
// 008ec9b9  50                   push eax
// 008ec9ba  8d4c2408             lea ecx, [esp + 8]
// 008ec9be  e86bd9f1ff           call 0x80a32e
// 008ec9c3  817c241801070000     cmp dword ptr [esp + 0x18], 0x701
// 008ec9cb  751c                 jne 0x8ec9e9
// 008ec9cd  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008ec9d1  8b4814               mov ecx, dword ptr [eax + 0x14]
// 008ec9d4  2b480c               sub ecx, dword ptr [eax + 0xc]
// 008ec9d7  898e04010000         mov dword ptr [esi + 0x104], ecx
// 008ec9dd  8b5018               mov edx, dword ptr [eax + 0x18]
// 008ec9e0  2b5010               sub edx, dword ptr [eax + 0x10]
// 008ec9e3  899608010000         mov dword ptr [esi + 0x108], edx
// 008ec9e9  8b442408             mov eax, dword ptr [esp + 8]
// 008ec9ed  5e                   pop esi
// 008ec9ee  85c0                 test eax, eax
// 008ec9f0  7406                 je 0x8ec9f8
// 008ec9f2  8b0c24               mov ecx, dword ptr [esp]
// 008ec9f5  894804               mov dword ptr [eax + 4], ecx
// 008ec9f8  837c240c00           cmp dword ptr [esp + 0xc], 0
// 008ec9fd  740c                 je 0x8eca0b
// 008ec9ff  8b542408             mov edx, dword ptr [esp + 8]
// 008eca03  52                   push edx
// 008eca04  6a00                 push 0
// 008eca06  e817d9f1ff           call 0x80a322
// 008eca0b  33c0                 xor eax, eax
// 008eca0d  83c410               add esp, 0x10
// 008eca10  c20800               ret 8
// library xtp-15.2.1-shared-mfc/Source\Common\XTPRichRender.cpp (function ?TxNotify@XTextHost@CXTPRichRender@@UAEJKPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPRichRender.cpp
