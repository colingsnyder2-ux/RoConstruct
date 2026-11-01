// from server: 100% by auto
// roc 2007-03 00460a20  unit: seg_00460000  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00460a20
//
// 00460a20  83ec10               sub esp, 0x10
// 00460a23  668b54241c           mov dx, word ptr [esp + 0x1c]
// 00460a28  33c0                 xor eax, eax
// 00460a2a  890424               mov dword ptr [esp], eax
// 00460a2d  89442408             mov dword ptr [esp + 8], eax
// 00460a31  89442404             mov dword ptr [esp + 4], eax
// 00460a35  8944240c             mov dword ptr [esp + 0xc], eax
// 00460a39  668b442414           mov ax, word ptr [esp + 0x14]
// 00460a3e  56                   push esi
// 00460a3f  8bf1                 mov esi, ecx
// 00460a41  668b4c241c           mov cx, word ptr [esp + 0x1c]
// 00460a46  6689442404           mov word ptr [esp + 4], ax
// 00460a4b  668b442424           mov ax, word ptr [esp + 0x24]
// 00460a50  668944240c           mov word ptr [esp + 0xc], ax
// 00460a55  66894c2406           mov word ptr [esp + 6], cx
// 00460a5a  668b4c2428           mov cx, word ptr [esp + 0x28]
// 00460a5f  668954240a           mov word ptr [esp + 0xa], dx
// 00460a64  668b54242c           mov dx, word ptr [esp + 0x2c]
// 00460a69  8d442404             lea eax, [esp + 4]
// 00460a6d  56                   push esi
// 00460a6e  50                   push eax
// 00460a6f  66894c2416           mov word ptr [esp + 0x16], cx
// 00460a74  6689542418           mov word ptr [esp + 0x18], dx
// 00460a79  e8a2a5ffff           call 0x45b020
// 00460a7e  83c408               add esp, 8
// 00460a81  f7d8                 neg eax
// 00460a83  1bc0                 sbb eax, eax
// 00460a85  83c001               add eax, 1
// 00460a88  894608               mov dword ptr [esi + 8], eax
// 00460a8b  5e                   pop esi
// 00460a8c  83c410               add esp, 0x10
// 00460a8f  c21800               ret 0x18
// library mfc-8.0/atlmfc\src\mfc\dbrfx.cpp (function ?SetDateTime@COleDateTime@ATL@@QAEHHHHHHH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dbrfx.cpp
