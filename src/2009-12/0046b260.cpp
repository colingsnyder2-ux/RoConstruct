// from server: 100% by auto
// roc 2009-12 0046b260  unit: Scintilla::CScintillaView  size: 164 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0046b260
//
// 0046b260  83ec10               sub esp, 0x10
// 0046b263  57                   push edi
// 0046b264  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0046b268  85ff                 test edi, edi
// 0046b26a  750a                 jne 0x46b276
// 0046b26c  6805400080           push 0x80004005
// 0046b271  e80a79f9ff           call 0x402b80
// 0046b276  56                   push esi
// 0046b277  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0046b27b  57                   push edi
// 0046b27c  56                   push esi
// 0046b27d  ff1570ba9800         call dword ptr [0x98ba70]
// 0046b283  33c9                 xor ecx, ecx
// 0046b285  894c2408             mov dword ptr [esp + 8], ecx
// 0046b289  894c240c             mov dword ptr [esp + 0xc], ecx
// 0046b28d  894c2410             mov dword ptr [esp + 0x10], ecx
// 0046b291  894c2414             mov dword ptr [esp + 0x14], ecx
// 0046b295  85c0                 test eax, eax
// 0046b297  7463                 je 0x46b2fc
// 0046b299  dd07                 fld qword ptr [edi]
// 0046b29b  8d442408             lea eax, [esp + 8]
// 0046b29f  50                   push eax
// 0046b2a0  83ec08               sub esp, 8
// 0046b2a3  dd1c24               fstp qword ptr [esp]
// 0046b2a6  ff156cba9800         call dword ptr [0x98ba6c]
// 0046b2ac  85c0                 test eax, eax
// 0046b2ae  744c                 je 0x46b2fc
// 0046b2b0  668b0e               mov cx, word ptr [esi]
// 0046b2b3  663b4c2408           cmp cx, word ptr [esp + 8]
// 0046b2b8  7542                 jne 0x46b2fc
// 0046b2ba  668b5602             mov dx, word ptr [esi + 2]
// 0046b2be  663b54240a           cmp dx, word ptr [esp + 0xa]
// 0046b2c3  7537                 jne 0x46b2fc
// 0046b2c5  668b4606             mov ax, word ptr [esi + 6]
// 0046b2c9  663b44240e           cmp ax, word ptr [esp + 0xe]
// 0046b2ce  752c                 jne 0x46b2fc
// 0046b2d0  668b4e08             mov cx, word ptr [esi + 8]
// 0046b2d4  663b4c2410           cmp cx, word ptr [esp + 0x10]
// 0046b2d9  7521                 jne 0x46b2fc
// 0046b2db  668b560a             mov dx, word ptr [esi + 0xa]
// 0046b2df  663b542412           cmp dx, word ptr [esp + 0x12]
// 0046b2e4  7516                 jne 0x46b2fc
// 0046b2e6  668b460c             mov ax, word ptr [esi + 0xc]
// 0046b2ea  663b442414           cmp ax, word ptr [esp + 0x14]
// 0046b2ef  750b                 jne 0x46b2fc
// 0046b2f1  5e                   pop esi
// 0046b2f2  b801000000           mov eax, 1
// 0046b2f7  5f                   pop edi
// 0046b2f8  83c410               add esp, 0x10
// 0046b2fb  c3                   ret 
// 0046b2fc  5e                   pop esi
// 0046b2fd  33c0                 xor eax, eax
// 0046b2ff  5f                   pop edi
// 0046b300  83c410               add esp, 0x10
// 0046b303  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxshelllistctrl.cpp (function ?AtlConvertSystemTimeToVariantTime@ATL@@YAHABU_SYSTEMTIME@@PAN@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxshelllistctrl.cpp
