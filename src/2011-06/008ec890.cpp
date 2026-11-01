// from server: 100% by auto
// roc 2011-06 008ec890  unit: CXTPRichRender::XTextHost  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008ec890
//
// 008ec890  83ec10               sub esp, 0x10
// 008ec893  56                   push esi
// 008ec894  8b742418             mov esi, dword ptr [esp + 0x18]
// 008ec898  8b46fc               mov eax, dword ptr [esi - 4]
// 008ec89b  83c6e0               add esi, -0x20
// 008ec89e  50                   push eax
// 008ec89f  8d4c2408             lea ecx, [esp + 8]
// 008ec8a3  e886daf1ff           call 0x80a32e
// 008ec8a8  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008ec8ac  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 008ec8b0  51                   push ecx
// 008ec8b1  52                   push edx
// 008ec8b2  8bce                 mov ecx, esi
// 008ec8b4  e831040e00           call 0x9cccea
// 008ec8b9  8bf0                 mov esi, eax
// 008ec8bb  8b442408             mov eax, dword ptr [esp + 8]
// 008ec8bf  85c0                 test eax, eax
// 008ec8c1  7407                 je 0x8ec8ca
// 008ec8c3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008ec8c7  894804               mov dword ptr [eax + 4], ecx
// 008ec8ca  837c241000           cmp dword ptr [esp + 0x10], 0
// 008ec8cf  740c                 je 0x8ec8dd
// 008ec8d1  8b54240c             mov edx, dword ptr [esp + 0xc]
// 008ec8d5  52                   push edx
// 008ec8d6  6a00                 push 0
// 008ec8d8  e845daf1ff           call 0x80a322
// 008ec8dd  8bc6                 mov eax, esi
// 008ec8df  5e                   pop esi
// 008ec8e0  83c410               add esp, 0x10
// 008ec8e3  c20c00               ret 0xc
// library xtp-15.2.1-shared-mfc/Source\Common\XTPRichRender.cpp (function ?QueryInterface@XTextHost@CXTPRichRender@@UAGJABU_GUID@@PAPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPRichRender.cpp
