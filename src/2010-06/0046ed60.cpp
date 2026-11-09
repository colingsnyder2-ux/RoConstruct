// from server: 100% by auto
// roc 2010-06 0046ed60  unit: Scintilla::CScintillaView  size: 164 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0046ed60
//
// 0046ed60  83ec10               sub esp, 0x10
// 0046ed63  57                   push edi
// 0046ed64  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0046ed68  85ff                 test edi, edi
// 0046ed6a  750a                 jne 0x46ed76
// 0046ed6c  6805400080           push 0x80004005
// 0046ed71  e85a3ef9ff           call 0x402bd0
// 0046ed76  56                   push esi
// 0046ed77  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0046ed7b  57                   push edi
// 0046ed7c  56                   push esi
// 0046ed7d  ff1530aa9e00         call dword ptr [0x9eaa30]
// 0046ed83  33c9                 xor ecx, ecx
// 0046ed85  894c2408             mov dword ptr [esp + 8], ecx
// 0046ed89  894c240c             mov dword ptr [esp + 0xc], ecx
// 0046ed8d  894c2410             mov dword ptr [esp + 0x10], ecx
// 0046ed91  894c2414             mov dword ptr [esp + 0x14], ecx
// 0046ed95  85c0                 test eax, eax
// 0046ed97  7463                 je 0x46edfc
// 0046ed99  dd07                 fld qword ptr [edi]
// 0046ed9b  8d442408             lea eax, [esp + 8]
// 0046ed9f  50                   push eax
// 0046eda0  83ec08               sub esp, 8
// 0046eda3  dd1c24               fstp qword ptr [esp]
// 0046eda6  ff1534aa9e00         call dword ptr [0x9eaa34]
// 0046edac  85c0                 test eax, eax
// 0046edae  744c                 je 0x46edfc
// 0046edb0  668b0e               mov cx, word ptr [esi]
// 0046edb3  663b4c2408           cmp cx, word ptr [esp + 8]
// 0046edb8  7542                 jne 0x46edfc
// 0046edba  668b5602             mov dx, word ptr [esi + 2]
// 0046edbe  663b54240a           cmp dx, word ptr [esp + 0xa]
// 0046edc3  7537                 jne 0x46edfc
// 0046edc5  668b4606             mov ax, word ptr [esi + 6]
// 0046edc9  663b44240e           cmp ax, word ptr [esp + 0xe]
// 0046edce  752c                 jne 0x46edfc
// 0046edd0  668b4e08             mov cx, word ptr [esi + 8]
// 0046edd4  663b4c2410           cmp cx, word ptr [esp + 0x10]
// 0046edd9  7521                 jne 0x46edfc
// 0046eddb  668b560a             mov dx, word ptr [esi + 0xa]
// 0046eddf  663b542412           cmp dx, word ptr [esp + 0x12]
// 0046ede4  7516                 jne 0x46edfc
// 0046ede6  668b460c             mov ax, word ptr [esi + 0xc]
// 0046edea  663b442414           cmp ax, word ptr [esp + 0x14]
// 0046edef  750b                 jne 0x46edfc
// 0046edf1  5e                   pop esi
// 0046edf2  b801000000           mov eax, 1
// 0046edf7  5f                   pop edi
// 0046edf8  83c410               add esp, 0x10
// 0046edfb  c3                   ret 
// 0046edfc  5e                   pop esi
// 0046edfd  33c0                 xor eax, eax
// 0046edff  5f                   pop edi
// 0046ee00  83c410               add esp, 0x10
// 0046ee03  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxshelllistctrl.cpp (function ?AtlConvertSystemTimeToVariantTime@ATL@@YAHABU_SYSTEMTIME@@PAN@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxshelllistctrl.cpp
