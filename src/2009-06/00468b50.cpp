// from server: 100% by auto
// roc 2009-06 00468b50  unit: CSettingsDialog  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00468b50
//
// 00468b50  83ec10               sub esp, 0x10
// 00468b53  668b54241c           mov dx, word ptr [esp + 0x1c]
// 00468b58  33c0                 xor eax, eax
// 00468b5a  890424               mov dword ptr [esp], eax
// 00468b5d  89442408             mov dword ptr [esp + 8], eax
// 00468b61  89442404             mov dword ptr [esp + 4], eax
// 00468b65  8944240c             mov dword ptr [esp + 0xc], eax
// 00468b69  668b442414           mov ax, word ptr [esp + 0x14]
// 00468b6e  56                   push esi
// 00468b6f  8bf1                 mov esi, ecx
// 00468b71  668b4c241c           mov cx, word ptr [esp + 0x1c]
// 00468b76  6689442404           mov word ptr [esp + 4], ax
// 00468b7b  668b442424           mov ax, word ptr [esp + 0x24]
// 00468b80  668944240c           mov word ptr [esp + 0xc], ax
// 00468b85  66894c2406           mov word ptr [esp + 6], cx
// 00468b8a  668b4c2428           mov cx, word ptr [esp + 0x28]
// 00468b8f  668954240a           mov word ptr [esp + 0xa], dx
// 00468b94  668b54242c           mov dx, word ptr [esp + 0x2c]
// 00468b99  8d442404             lea eax, [esp + 4]
// 00468b9d  56                   push esi
// 00468b9e  50                   push eax
// 00468b9f  66894c2416           mov word ptr [esp + 0x16], cx
// 00468ba4  6689542418           mov word ptr [esp + 0x18], dx
// 00468ba9  e8029bffff           call 0x4626b0
// 00468bae  83c408               add esp, 8
// 00468bb1  f7d8                 neg eax
// 00468bb3  1bc0                 sbb eax, eax
// 00468bb5  40                   inc eax
// 00468bb6  894608               mov dword ptr [esi + 8], eax
// 00468bb9  5e                   pop esi
// 00468bba  83c410               add esp, 0x10
// 00468bbd  c21800               ret 0x18
// library mfc-9.0/atlmfc\src\mfc\dbrfx.cpp (function ?SetDateTime@COleDateTime@ATL@@QAEHHHHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dbrfx.cpp
