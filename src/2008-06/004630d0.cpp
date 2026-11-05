// from server: 100% by auto
// roc 2008-06 004630d0  unit: Scintilla::CScintillaView  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004630d0
//
// 004630d0  83ec18               sub esp, 0x18
// 004630d3  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004630d7  8b5004               mov edx, dword ptr [eax + 4]
// 004630da  56                   push esi
// 004630db  8bf1                 mov esi, ecx
// 004630dd  8b08                 mov ecx, dword ptr [eax]
// 004630df  8d44240c             lea eax, [esp + 0xc]
// 004630e3  894c2404             mov dword ptr [esp + 4], ecx
// 004630e7  50                   push eax
// 004630e8  8d4c2408             lea ecx, [esp + 8]
// 004630ec  8954240c             mov dword ptr [esp + 0xc], edx
// 004630f0  e8fbe9ffff           call 0x461af0
// 004630f5  84c0                 test al, al
// 004630f7  7420                 je 0x463119
// 004630f9  8d4c240c             lea ecx, [esp + 0xc]
// 004630fd  56                   push esi
// 004630fe  51                   push ecx
// 004630ff  e83ce9ffff           call 0x461a40
// 00463104  83c408               add esp, 8
// 00463107  85c0                 test eax, eax
// 00463109  740e                 je 0x463119
// 0046310b  33c0                 xor eax, eax
// 0046310d  894608               mov dword ptr [esi + 8], eax
// 00463110  8bc6                 mov eax, esi
// 00463112  5e                   pop esi
// 00463113  83c418               add esp, 0x18
// 00463116  c20400               ret 4
// 00463119  b801000000           mov eax, 1
// 0046311e  894608               mov dword ptr [esi + 8], eax
// 00463121  8bc6                 mov eax, esi
// 00463123  5e                   pop esi
// 00463124  83c418               add esp, 0x18
// 00463127  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxshelllistctrl.cpp (function ??4COleDateTime@ATL@@QAEAAV01@AB_J@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxshelllistctrl.cpp
