// from server: 100% by auto
// roc 2007-08 00463330  unit: CSettingsDialog  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00463330
//
// 00463330  83ec10               sub esp, 0x10
// 00463333  668b54241c           mov dx, word ptr [esp + 0x1c]
// 00463338  33c0                 xor eax, eax
// 0046333a  890424               mov dword ptr [esp], eax
// 0046333d  89442408             mov dword ptr [esp + 8], eax
// 00463341  89442404             mov dword ptr [esp + 4], eax
// 00463345  8944240c             mov dword ptr [esp + 0xc], eax
// 00463349  668b442414           mov ax, word ptr [esp + 0x14]
// 0046334e  56                   push esi
// 0046334f  8bf1                 mov esi, ecx
// 00463351  668b4c241c           mov cx, word ptr [esp + 0x1c]
// 00463356  6689442404           mov word ptr [esp + 4], ax
// 0046335b  668b442424           mov ax, word ptr [esp + 0x24]
// 00463360  668944240c           mov word ptr [esp + 0xc], ax
// 00463365  66894c2406           mov word ptr [esp + 6], cx
// 0046336a  668b4c2428           mov cx, word ptr [esp + 0x28]
// 0046336f  668954240a           mov word ptr [esp + 0xa], dx
// 00463374  668b54242c           mov dx, word ptr [esp + 0x2c]
// 00463379  8d442404             lea eax, [esp + 4]
// 0046337d  56                   push esi
// 0046337e  50                   push eax
// 0046337f  66894c2416           mov word ptr [esp + 0x16], cx
// 00463384  6689542418           mov word ptr [esp + 0x18], dx
// 00463389  e822a5ffff           call 0x45d8b0
// 0046338e  83c408               add esp, 8
// 00463391  f7d8                 neg eax
// 00463393  1bc0                 sbb eax, eax
// 00463395  83c001               add eax, 1
// 00463398  894608               mov dword ptr [esi + 8], eax
// 0046339b  5e                   pop esi
// 0046339c  83c410               add esp, 0x10
// 0046339f  c21800               ret 0x18
// library mfc-8.0/atlmfc\src\mfc\dbrfx.cpp (function ?SetDateTime@COleDateTime@ATL@@QAEHHHHHHH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dbrfx.cpp
