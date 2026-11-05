// from server: 100% by auto
// roc 2008-06 00461a40  unit: Scintilla::CScintillaView  size: 164 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00461a40
//
// 00461a40  83ec10               sub esp, 0x10
// 00461a43  57                   push edi
// 00461a44  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00461a48  85ff                 test edi, edi
// 00461a4a  750a                 jne 0x461a56
// 00461a4c  6805400080           push 0x80004005
// 00461a51  e8aaf5f9ff           call 0x401000
// 00461a56  56                   push esi
// 00461a57  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00461a5b  57                   push edi
// 00461a5c  56                   push esi
// 00461a5d  ff15c8288000         call dword ptr [0x8028c8]
// 00461a63  33c9                 xor ecx, ecx
// 00461a65  894c2408             mov dword ptr [esp + 8], ecx
// 00461a69  894c240c             mov dword ptr [esp + 0xc], ecx
// 00461a6d  894c2410             mov dword ptr [esp + 0x10], ecx
// 00461a71  894c2414             mov dword ptr [esp + 0x14], ecx
// 00461a75  85c0                 test eax, eax
// 00461a77  7463                 je 0x461adc
// 00461a79  dd07                 fld qword ptr [edi]
// 00461a7b  8d442408             lea eax, [esp + 8]
// 00461a7f  50                   push eax
// 00461a80  83ec08               sub esp, 8
// 00461a83  dd1c24               fstp qword ptr [esp]
// 00461a86  ff15cc288000         call dword ptr [0x8028cc]
// 00461a8c  85c0                 test eax, eax
// 00461a8e  744c                 je 0x461adc
// 00461a90  668b0e               mov cx, word ptr [esi]
// 00461a93  663b4c2408           cmp cx, word ptr [esp + 8]
// 00461a98  7542                 jne 0x461adc
// 00461a9a  668b5602             mov dx, word ptr [esi + 2]
// 00461a9e  663b54240a           cmp dx, word ptr [esp + 0xa]
// 00461aa3  7537                 jne 0x461adc
// 00461aa5  668b4606             mov ax, word ptr [esi + 6]
// 00461aa9  663b44240e           cmp ax, word ptr [esp + 0xe]
// 00461aae  752c                 jne 0x461adc
// 00461ab0  668b4e08             mov cx, word ptr [esi + 8]
// 00461ab4  663b4c2410           cmp cx, word ptr [esp + 0x10]
// 00461ab9  7521                 jne 0x461adc
// 00461abb  668b560a             mov dx, word ptr [esi + 0xa]
// 00461abf  663b542412           cmp dx, word ptr [esp + 0x12]
// 00461ac4  7516                 jne 0x461adc
// 00461ac6  668b460c             mov ax, word ptr [esi + 0xc]
// 00461aca  663b442414           cmp ax, word ptr [esp + 0x14]
// 00461acf  750b                 jne 0x461adc
// 00461ad1  5e                   pop esi
// 00461ad2  b801000000           mov eax, 1
// 00461ad7  5f                   pop edi
// 00461ad8  83c410               add esp, 0x10
// 00461adb  c3                   ret 
// 00461adc  5e                   pop esi
// 00461add  33c0                 xor eax, eax
// 00461adf  5f                   pop edi
// 00461ae0  83c410               add esp, 0x10
// 00461ae3  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxshelllistctrl.cpp (function ?AtlConvertSystemTimeToVariantTime@ATL@@YAHABU_SYSTEMTIME@@PAN@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxshelllistctrl.cpp
