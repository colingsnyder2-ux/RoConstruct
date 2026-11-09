// from server: 100% by auto
// roc 2010-06 004773e0  unit: CSettingsDialog  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004773e0
//
// 004773e0  83ec10               sub esp, 0x10
// 004773e3  668b54241c           mov dx, word ptr [esp + 0x1c]
// 004773e8  33c0                 xor eax, eax
// 004773ea  890424               mov dword ptr [esp], eax
// 004773ed  89442408             mov dword ptr [esp + 8], eax
// 004773f1  89442404             mov dword ptr [esp + 4], eax
// 004773f5  8944240c             mov dword ptr [esp + 0xc], eax
// 004773f9  668b442414           mov ax, word ptr [esp + 0x14]
// 004773fe  56                   push esi
// 004773ff  8bf1                 mov esi, ecx
// 00477401  668b4c241c           mov cx, word ptr [esp + 0x1c]
// 00477406  6689442404           mov word ptr [esp + 4], ax
// 0047740b  668b442424           mov ax, word ptr [esp + 0x24]
// 00477410  668944240c           mov word ptr [esp + 0xc], ax
// 00477415  66894c2406           mov word ptr [esp + 6], cx
// 0047741a  668b4c2428           mov cx, word ptr [esp + 0x28]
// 0047741f  668954240a           mov word ptr [esp + 0xa], dx
// 00477424  668b54242c           mov dx, word ptr [esp + 0x2c]
// 00477429  8d442404             lea eax, [esp + 4]
// 0047742d  56                   push esi
// 0047742e  50                   push eax
// 0047742f  66894c2416           mov word ptr [esp + 0x16], cx
// 00477434  6689542418           mov word ptr [esp + 0x18], dx
// 00477439  e82279ffff           call 0x46ed60
// 0047743e  83c408               add esp, 8
// 00477441  f7d8                 neg eax
// 00477443  1bc0                 sbb eax, eax
// 00477445  40                   inc eax
// 00477446  894608               mov dword ptr [esi + 8], eax
// 00477449  5e                   pop esi
// 0047744a  83c410               add esp, 0x10
// 0047744d  c21800               ret 0x18
// library mfc-9.0/atlmfc\src\mfc\dbrfx.cpp (function ?SetDateTime@COleDateTime@ATL@@QAEHHHHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dbrfx.cpp
