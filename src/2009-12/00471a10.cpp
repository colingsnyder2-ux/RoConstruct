// from server: 100% by auto
// roc 2009-12 00471a10  unit: CSettingsDialog  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00471a10
//
// 00471a10  83ec10               sub esp, 0x10
// 00471a13  668b54241c           mov dx, word ptr [esp + 0x1c]
// 00471a18  33c0                 xor eax, eax
// 00471a1a  890424               mov dword ptr [esp], eax
// 00471a1d  89442408             mov dword ptr [esp + 8], eax
// 00471a21  89442404             mov dword ptr [esp + 4], eax
// 00471a25  8944240c             mov dword ptr [esp + 0xc], eax
// 00471a29  668b442414           mov ax, word ptr [esp + 0x14]
// 00471a2e  56                   push esi
// 00471a2f  8bf1                 mov esi, ecx
// 00471a31  668b4c241c           mov cx, word ptr [esp + 0x1c]
// 00471a36  6689442404           mov word ptr [esp + 4], ax
// 00471a3b  668b442424           mov ax, word ptr [esp + 0x24]
// 00471a40  668944240c           mov word ptr [esp + 0xc], ax
// 00471a45  66894c2406           mov word ptr [esp + 6], cx
// 00471a4a  668b4c2428           mov cx, word ptr [esp + 0x28]
// 00471a4f  668954240a           mov word ptr [esp + 0xa], dx
// 00471a54  668b54242c           mov dx, word ptr [esp + 0x2c]
// 00471a59  8d442404             lea eax, [esp + 4]
// 00471a5d  56                   push esi
// 00471a5e  50                   push eax
// 00471a5f  66894c2416           mov word ptr [esp + 0x16], cx
// 00471a64  6689542418           mov word ptr [esp + 0x18], dx
// 00471a69  e8f297ffff           call 0x46b260
// 00471a6e  83c408               add esp, 8
// 00471a71  f7d8                 neg eax
// 00471a73  1bc0                 sbb eax, eax
// 00471a75  40                   inc eax
// 00471a76  894608               mov dword ptr [esi + 8], eax
// 00471a79  5e                   pop esi
// 00471a7a  83c410               add esp, 0x10
// 00471a7d  c21800               ret 0x18
// library mfc-9.0/atlmfc\src\mfc\dbrfx.cpp (function ?SetDateTime@COleDateTime@ATL@@QAEHHHHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dbrfx.cpp
