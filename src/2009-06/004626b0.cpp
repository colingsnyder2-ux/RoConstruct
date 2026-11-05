// from server: 100% by auto
// roc 2009-06 004626b0  unit: Scintilla::CScintillaView  size: 164 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004626b0
//
// 004626b0  83ec10               sub esp, 0x10
// 004626b3  57                   push edi
// 004626b4  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 004626b8  85ff                 test edi, edi
// 004626ba  750a                 jne 0x4626c6
// 004626bc  6805400080           push 0x80004005
// 004626c1  e8ea07faff           call 0x402eb0
// 004626c6  56                   push esi
// 004626c7  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 004626cb  57                   push edi
// 004626cc  56                   push esi
// 004626cd  ff15d4e98900         call dword ptr [0x89e9d4]
// 004626d3  33c9                 xor ecx, ecx
// 004626d5  894c2408             mov dword ptr [esp + 8], ecx
// 004626d9  894c240c             mov dword ptr [esp + 0xc], ecx
// 004626dd  894c2410             mov dword ptr [esp + 0x10], ecx
// 004626e1  894c2414             mov dword ptr [esp + 0x14], ecx
// 004626e5  85c0                 test eax, eax
// 004626e7  7463                 je 0x46274c
// 004626e9  dd07                 fld qword ptr [edi]
// 004626eb  8d442408             lea eax, [esp + 8]
// 004626ef  50                   push eax
// 004626f0  83ec08               sub esp, 8
// 004626f3  dd1c24               fstp qword ptr [esp]
// 004626f6  ff1504ea8900         call dword ptr [0x89ea04]
// 004626fc  85c0                 test eax, eax
// 004626fe  744c                 je 0x46274c
// 00462700  668b0e               mov cx, word ptr [esi]
// 00462703  663b4c2408           cmp cx, word ptr [esp + 8]
// 00462708  7542                 jne 0x46274c
// 0046270a  668b5602             mov dx, word ptr [esi + 2]
// 0046270e  663b54240a           cmp dx, word ptr [esp + 0xa]
// 00462713  7537                 jne 0x46274c
// 00462715  668b4606             mov ax, word ptr [esi + 6]
// 00462719  663b44240e           cmp ax, word ptr [esp + 0xe]
// 0046271e  752c                 jne 0x46274c
// 00462720  668b4e08             mov cx, word ptr [esi + 8]
// 00462724  663b4c2410           cmp cx, word ptr [esp + 0x10]
// 00462729  7521                 jne 0x46274c
// 0046272b  668b560a             mov dx, word ptr [esi + 0xa]
// 0046272f  663b542412           cmp dx, word ptr [esp + 0x12]
// 00462734  7516                 jne 0x46274c
// 00462736  668b460c             mov ax, word ptr [esi + 0xc]
// 0046273a  663b442414           cmp ax, word ptr [esp + 0x14]
// 0046273f  750b                 jne 0x46274c
// 00462741  5e                   pop esi
// 00462742  b801000000           mov eax, 1
// 00462747  5f                   pop edi
// 00462748  83c410               add esp, 0x10
// 0046274b  c3                   ret 
// 0046274c  5e                   pop esi
// 0046274d  33c0                 xor eax, eax
// 0046274f  5f                   pop edi
// 00462750  83c410               add esp, 0x10
// 00462753  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxshelllistctrl.cpp (function ?AtlConvertSystemTimeToVariantTime@ATL@@YAHABU_SYSTEMTIME@@PAN@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxshelllistctrl.cpp
