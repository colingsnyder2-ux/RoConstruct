// from server: 100% by auto
// roc 2007-03 0045b020  unit: seg_00450000  size: 164 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0045b020
//
// 0045b020  83ec10               sub esp, 0x10
// 0045b023  57                   push edi
// 0045b024  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0045b028  85ff                 test edi, edi
// 0045b02a  750a                 jne 0x45b036
// 0045b02c  6805400080           push 0x80004005
// 0045b031  e8ca5ffaff           call 0x401000
// 0045b036  56                   push esi
// 0045b037  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0045b03b  57                   push edi
// 0045b03c  56                   push esi
// 0045b03d  ff15e8ea7700         call dword ptr [0x77eae8]
// 0045b043  33c9                 xor ecx, ecx
// 0045b045  85c0                 test eax, eax
// 0045b047  894c2408             mov dword ptr [esp + 8], ecx
// 0045b04b  894c240c             mov dword ptr [esp + 0xc], ecx
// 0045b04f  894c2410             mov dword ptr [esp + 0x10], ecx
// 0045b053  894c2414             mov dword ptr [esp + 0x14], ecx
// 0045b057  7463                 je 0x45b0bc
// 0045b059  dd07                 fld qword ptr [edi]
// 0045b05b  8d442408             lea eax, [esp + 8]
// 0045b05f  50                   push eax
// 0045b060  83ec08               sub esp, 8
// 0045b063  dd1c24               fstp qword ptr [esp]
// 0045b066  ff15e4ea7700         call dword ptr [0x77eae4]
// 0045b06c  85c0                 test eax, eax
// 0045b06e  744c                 je 0x45b0bc
// 0045b070  668b0e               mov cx, word ptr [esi]
// 0045b073  663b4c2408           cmp cx, word ptr [esp + 8]
// 0045b078  7542                 jne 0x45b0bc
// 0045b07a  668b5602             mov dx, word ptr [esi + 2]
// 0045b07e  663b54240a           cmp dx, word ptr [esp + 0xa]
// 0045b083  7537                 jne 0x45b0bc
// 0045b085  668b4606             mov ax, word ptr [esi + 6]
// 0045b089  663b44240e           cmp ax, word ptr [esp + 0xe]
// 0045b08e  752c                 jne 0x45b0bc
// 0045b090  668b4e08             mov cx, word ptr [esi + 8]
// 0045b094  663b4c2410           cmp cx, word ptr [esp + 0x10]
// 0045b099  7521                 jne 0x45b0bc
// 0045b09b  668b560a             mov dx, word ptr [esi + 0xa]
// 0045b09f  663b542412           cmp dx, word ptr [esp + 0x12]
// 0045b0a4  7516                 jne 0x45b0bc
// 0045b0a6  668b460c             mov ax, word ptr [esi + 0xc]
// 0045b0aa  663b442414           cmp ax, word ptr [esp + 0x14]
// 0045b0af  750b                 jne 0x45b0bc
// 0045b0b1  5e                   pop esi
// 0045b0b2  b801000000           mov eax, 1
// 0045b0b7  5f                   pop edi
// 0045b0b8  83c410               add esp, 0x10
// 0045b0bb  c3                   ret 
// 0045b0bc  5e                   pop esi
// 0045b0bd  33c0                 xor eax, eax
// 0045b0bf  5f                   pop edi
// 0045b0c0  83c410               add esp, 0x10
// 0045b0c3  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\dbrfx.cpp (function ?AtlConvertSystemTimeToVariantTime@ATL@@YAHABU_SYSTEMTIME@@PAN@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dbrfx.cpp
