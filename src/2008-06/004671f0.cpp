// from server: 100% by auto
// roc 2008-06 004671f0  unit: CSettingsDialog  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004671f0
//
// 004671f0  83ec10               sub esp, 0x10
// 004671f3  668b54241c           mov dx, word ptr [esp + 0x1c]
// 004671f8  33c0                 xor eax, eax
// 004671fa  890424               mov dword ptr [esp], eax
// 004671fd  89442408             mov dword ptr [esp + 8], eax
// 00467201  89442404             mov dword ptr [esp + 4], eax
// 00467205  8944240c             mov dword ptr [esp + 0xc], eax
// 00467209  668b442414           mov ax, word ptr [esp + 0x14]
// 0046720e  56                   push esi
// 0046720f  8bf1                 mov esi, ecx
// 00467211  668b4c241c           mov cx, word ptr [esp + 0x1c]
// 00467216  6689442404           mov word ptr [esp + 4], ax
// 0046721b  668b442424           mov ax, word ptr [esp + 0x24]
// 00467220  668944240c           mov word ptr [esp + 0xc], ax
// 00467225  66894c2406           mov word ptr [esp + 6], cx
// 0046722a  668b4c2428           mov cx, word ptr [esp + 0x28]
// 0046722f  668954240a           mov word ptr [esp + 0xa], dx
// 00467234  668b54242c           mov dx, word ptr [esp + 0x2c]
// 00467239  8d442404             lea eax, [esp + 4]
// 0046723d  56                   push esi
// 0046723e  50                   push eax
// 0046723f  66894c2416           mov word ptr [esp + 0x16], cx
// 00467244  6689542418           mov word ptr [esp + 0x18], dx
// 00467249  e8f2a7ffff           call 0x461a40
// 0046724e  83c408               add esp, 8
// 00467251  f7d8                 neg eax
// 00467253  1bc0                 sbb eax, eax
// 00467255  40                   inc eax
// 00467256  894608               mov dword ptr [esi + 8], eax
// 00467259  5e                   pop esi
// 0046725a  83c410               add esp, 0x10
// 0046725d  c21800               ret 0x18
// library mfc-9.0/atlmfc\src\mfc\dbrfx.cpp (function ?SetDateTime@COleDateTime@ATL@@QAEHHHHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dbrfx.cpp
