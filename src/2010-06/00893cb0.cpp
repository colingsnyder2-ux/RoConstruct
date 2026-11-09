// from server: 100% by auto
// roc 2010-06 00893cb0  unit: CXTPRichRender::XTextHost  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00893cb0
//
// 00893cb0  83ec10               sub esp, 0x10
// 00893cb3  56                   push esi
// 00893cb4  8b742418             mov esi, dword ptr [esp + 0x18]
// 00893cb8  8b46fc               mov eax, dword ptr [esi - 4]
// 00893cbb  83c6e0               add esi, -0x20
// 00893cbe  50                   push eax
// 00893cbf  8d4c2408             lea ecx, [esp + 8]
// 00893cc3  e8a83ff1ff           call 0x7a7c70
// 00893cc8  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00893ccc  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00893cd0  51                   push ecx
// 00893cd1  52                   push edx
// 00893cd2  8bce                 mov ecx, esi
// 00893cd4  e8cd980e00           call 0x97d5a6
// 00893cd9  8bf0                 mov esi, eax
// 00893cdb  8b442408             mov eax, dword ptr [esp + 8]
// 00893cdf  85c0                 test eax, eax
// 00893ce1  7407                 je 0x893cea
// 00893ce3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00893ce7  894804               mov dword ptr [eax + 4], ecx
// 00893cea  837c241000           cmp dword ptr [esp + 0x10], 0
// 00893cef  740c                 je 0x893cfd
// 00893cf1  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00893cf5  52                   push edx
// 00893cf6  6a00                 push 0
// 00893cf8  e8673ff1ff           call 0x7a7c64
// 00893cfd  8bc6                 mov eax, esi
// 00893cff  5e                   pop esi
// 00893d00  83c410               add esp, 0x10
// 00893d03  c20c00               ret 0xc
// library xtp-13.2.1-shared-mfc/Source\Common\XTPRichRender.cpp (function ?QueryInterface@XTextHost@CXTPRichRender@@UAGJABU_GUID@@PAPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPRichRender.cpp
