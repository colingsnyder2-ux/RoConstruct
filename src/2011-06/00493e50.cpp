// from server: 100% by auto
// roc 2011-06 00493e50  unit: CSettingsDialog  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00493e50
//
// 00493e50  83ec10               sub esp, 0x10
// 00493e53  668b54241c           mov dx, word ptr [esp + 0x1c]
// 00493e58  33c0                 xor eax, eax
// 00493e5a  890424               mov dword ptr [esp], eax
// 00493e5d  89442408             mov dword ptr [esp + 8], eax
// 00493e61  89442404             mov dword ptr [esp + 4], eax
// 00493e65  8944240c             mov dword ptr [esp + 0xc], eax
// 00493e69  668b442414           mov ax, word ptr [esp + 0x14]
// 00493e6e  56                   push esi
// 00493e6f  8bf1                 mov esi, ecx
// 00493e71  668b4c241c           mov cx, word ptr [esp + 0x1c]
// 00493e76  6689442404           mov word ptr [esp + 4], ax
// 00493e7b  668b442424           mov ax, word ptr [esp + 0x24]
// 00493e80  668944240c           mov word ptr [esp + 0xc], ax
// 00493e85  66894c2406           mov word ptr [esp + 6], cx
// 00493e8a  668b4c2428           mov cx, word ptr [esp + 0x28]
// 00493e8f  668954240a           mov word ptr [esp + 0xa], dx
// 00493e94  668b54242c           mov dx, word ptr [esp + 0x2c]
// 00493e99  8d442404             lea eax, [esp + 4]
// 00493e9d  56                   push esi
// 00493e9e  50                   push eax
// 00493e9f  66894c2416           mov word ptr [esp + 0x16], cx
// 00493ea4  6689542418           mov word ptr [esp + 0x18], dx
// 00493ea9  e8c277ffff           call 0x48b670
// 00493eae  83c408               add esp, 8
// 00493eb1  f7d8                 neg eax
// 00493eb3  1bc0                 sbb eax, eax
// 00493eb5  40                   inc eax
// 00493eb6  894608               mov dword ptr [esi + 8], eax
// 00493eb9  5e                   pop esi
// 00493eba  83c410               add esp, 0x10
// 00493ebd  c21800               ret 0x18
// library mfc-9.0/atlmfc\src\mfc\dbrfx.cpp (function ?SetDateTime@COleDateTime@ATL@@QAEHHHHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dbrfx.cpp
