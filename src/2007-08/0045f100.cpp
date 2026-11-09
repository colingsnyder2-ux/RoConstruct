// from server: 100% by auto
// roc 2007-08 0045f100  unit: Scintilla::CScintillaView  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0045f100
//
// 0045f100  83ec18               sub esp, 0x18
// 0045f103  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0045f107  8b5004               mov edx, dword ptr [eax + 4]
// 0045f10a  56                   push esi
// 0045f10b  8bf1                 mov esi, ecx
// 0045f10d  8b08                 mov ecx, dword ptr [eax]
// 0045f10f  8d44240c             lea eax, [esp + 0xc]
// 0045f113  894c2404             mov dword ptr [esp + 4], ecx
// 0045f117  50                   push eax
// 0045f118  8d4c2408             lea ecx, [esp + 8]
// 0045f11c  8954240c             mov dword ptr [esp + 0xc], edx
// 0045f120  e83be8ffff           call 0x45d960
// 0045f125  84c0                 test al, al
// 0045f127  7420                 je 0x45f149
// 0045f129  8d4c240c             lea ecx, [esp + 0xc]
// 0045f12d  56                   push esi
// 0045f12e  51                   push ecx
// 0045f12f  e87ce7ffff           call 0x45d8b0
// 0045f134  83c408               add esp, 8
// 0045f137  85c0                 test eax, eax
// 0045f139  740e                 je 0x45f149
// 0045f13b  33c0                 xor eax, eax
// 0045f13d  894608               mov dword ptr [esi + 8], eax
// 0045f140  8bc6                 mov eax, esi
// 0045f142  5e                   pop esi
// 0045f143  83c418               add esp, 0x18
// 0045f146  c20400               ret 4
// 0045f149  b801000000           mov eax, 1
// 0045f14e  894608               mov dword ptr [esi + 8], eax
// 0045f151  8bc6                 mov eax, esi
// 0045f153  5e                   pop esi
// 0045f154  83c418               add esp, 0x18
// 0045f157  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxshelllistctrl.cpp (function ??4COleDateTime@ATL@@QAEAAV01@AB_J@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxshelllistctrl.cpp
