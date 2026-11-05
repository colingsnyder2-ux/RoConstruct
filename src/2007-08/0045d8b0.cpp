// from server: 100% by auto
// roc 2007-08 0045d8b0  unit: Scintilla::CScintillaView  size: 164 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0045d8b0
//
// 0045d8b0  83ec10               sub esp, 0x10
// 0045d8b3  57                   push edi
// 0045d8b4  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0045d8b8  85ff                 test edi, edi
// 0045d8ba  750a                 jne 0x45d8c6
// 0045d8bc  6805400080           push 0x80004005
// 0045d8c1  e83a37faff           call 0x401000
// 0045d8c6  56                   push esi
// 0045d8c7  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0045d8cb  57                   push edi
// 0045d8cc  56                   push esi
// 0045d8cd  ff1524ea7700         call dword ptr [0x77ea24]
// 0045d8d3  33c9                 xor ecx, ecx
// 0045d8d5  85c0                 test eax, eax
// 0045d8d7  894c2408             mov dword ptr [esp + 8], ecx
// 0045d8db  894c240c             mov dword ptr [esp + 0xc], ecx
// 0045d8df  894c2410             mov dword ptr [esp + 0x10], ecx
// 0045d8e3  894c2414             mov dword ptr [esp + 0x14], ecx
// 0045d8e7  7463                 je 0x45d94c
// 0045d8e9  dd07                 fld qword ptr [edi]
// 0045d8eb  8d442408             lea eax, [esp + 8]
// 0045d8ef  50                   push eax
// 0045d8f0  83ec08               sub esp, 8
// 0045d8f3  dd1c24               fstp qword ptr [esp]
// 0045d8f6  ff15ace97700         call dword ptr [0x77e9ac]
// 0045d8fc  85c0                 test eax, eax
// 0045d8fe  744c                 je 0x45d94c
// 0045d900  668b0e               mov cx, word ptr [esi]
// 0045d903  663b4c2408           cmp cx, word ptr [esp + 8]
// 0045d908  7542                 jne 0x45d94c
// 0045d90a  668b5602             mov dx, word ptr [esi + 2]
// 0045d90e  663b54240a           cmp dx, word ptr [esp + 0xa]
// 0045d913  7537                 jne 0x45d94c
// 0045d915  668b4606             mov ax, word ptr [esi + 6]
// 0045d919  663b44240e           cmp ax, word ptr [esp + 0xe]
// 0045d91e  752c                 jne 0x45d94c
// 0045d920  668b4e08             mov cx, word ptr [esi + 8]
// 0045d924  663b4c2410           cmp cx, word ptr [esp + 0x10]
// 0045d929  7521                 jne 0x45d94c
// 0045d92b  668b560a             mov dx, word ptr [esi + 0xa]
// 0045d92f  663b542412           cmp dx, word ptr [esp + 0x12]
// 0045d934  7516                 jne 0x45d94c
// 0045d936  668b460c             mov ax, word ptr [esi + 0xc]
// 0045d93a  663b442414           cmp ax, word ptr [esp + 0x14]
// 0045d93f  750b                 jne 0x45d94c
// 0045d941  5e                   pop esi
// 0045d942  b801000000           mov eax, 1
// 0045d947  5f                   pop edi
// 0045d948  83c410               add esp, 0x10
// 0045d94b  c3                   ret 
// 0045d94c  5e                   pop esi
// 0045d94d  33c0                 xor eax, eax
// 0045d94f  5f                   pop edi
// 0045d950  83c410               add esp, 0x10
// 0045d953  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\dbrfx.cpp (function ?AtlConvertSystemTimeToVariantTime@ATL@@YAHABU_SYSTEMTIME@@PAN@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dbrfx.cpp
