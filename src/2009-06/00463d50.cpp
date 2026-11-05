// from server: 100% by auto
// roc 2009-06 00463d50  unit: Scintilla::CScintillaView  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00463d50
//
// 00463d50  83ec18               sub esp, 0x18
// 00463d53  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00463d57  8b5004               mov edx, dword ptr [eax + 4]
// 00463d5a  56                   push esi
// 00463d5b  8bf1                 mov esi, ecx
// 00463d5d  8b08                 mov ecx, dword ptr [eax]
// 00463d5f  8d44240c             lea eax, [esp + 0xc]
// 00463d63  894c2404             mov dword ptr [esp + 4], ecx
// 00463d67  50                   push eax
// 00463d68  8d4c2408             lea ecx, [esp + 8]
// 00463d6c  8954240c             mov dword ptr [esp + 0xc], edx
// 00463d70  e8ebe9ffff           call 0x462760
// 00463d75  84c0                 test al, al
// 00463d77  7420                 je 0x463d99
// 00463d79  8d4c240c             lea ecx, [esp + 0xc]
// 00463d7d  56                   push esi
// 00463d7e  51                   push ecx
// 00463d7f  e82ce9ffff           call 0x4626b0
// 00463d84  83c408               add esp, 8
// 00463d87  85c0                 test eax, eax
// 00463d89  740e                 je 0x463d99
// 00463d8b  33c0                 xor eax, eax
// 00463d8d  894608               mov dword ptr [esi + 8], eax
// 00463d90  8bc6                 mov eax, esi
// 00463d92  5e                   pop esi
// 00463d93  83c418               add esp, 0x18
// 00463d96  c20400               ret 4
// 00463d99  b801000000           mov eax, 1
// 00463d9e  894608               mov dword ptr [esi + 8], eax
// 00463da1  8bc6                 mov eax, esi
// 00463da3  5e                   pop esi
// 00463da4  83c418               add esp, 0x18
// 00463da7  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxshelllistctrl.cpp (function ??4COleDateTime@ATL@@QAEAAV01@AB_J@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxshelllistctrl.cpp
