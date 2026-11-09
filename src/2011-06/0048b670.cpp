// from server: 100% by auto
// roc 2011-06 0048b670  unit: Scintilla::CScintillaView  size: 164 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0048b670
//
// 0048b670  83ec10               sub esp, 0x10
// 0048b673  57                   push edi
// 0048b674  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0048b678  85ff                 test edi, edi
// 0048b67a  750a                 jne 0x48b686
// 0048b67c  6805400080           push 0x80004005
// 0048b681  e81a7ff7ff           call 0x4035a0
// 0048b686  56                   push esi
// 0048b687  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0048b68b  57                   push edi
// 0048b68c  56                   push esi
// 0048b68d  ff15900aa400         call dword ptr [0xa40a90]
// 0048b693  33c9                 xor ecx, ecx
// 0048b695  894c2408             mov dword ptr [esp + 8], ecx
// 0048b699  894c240c             mov dword ptr [esp + 0xc], ecx
// 0048b69d  894c2410             mov dword ptr [esp + 0x10], ecx
// 0048b6a1  894c2414             mov dword ptr [esp + 0x14], ecx
// 0048b6a5  85c0                 test eax, eax
// 0048b6a7  7463                 je 0x48b70c
// 0048b6a9  dd07                 fld qword ptr [edi]
// 0048b6ab  8d442408             lea eax, [esp + 8]
// 0048b6af  50                   push eax
// 0048b6b0  83ec08               sub esp, 8
// 0048b6b3  dd1c24               fstp qword ptr [esp]
// 0048b6b6  ff15940aa400         call dword ptr [0xa40a94]
// 0048b6bc  85c0                 test eax, eax
// 0048b6be  744c                 je 0x48b70c
// 0048b6c0  668b0e               mov cx, word ptr [esi]
// 0048b6c3  663b4c2408           cmp cx, word ptr [esp + 8]
// 0048b6c8  7542                 jne 0x48b70c
// 0048b6ca  668b5602             mov dx, word ptr [esi + 2]
// 0048b6ce  663b54240a           cmp dx, word ptr [esp + 0xa]
// 0048b6d3  7537                 jne 0x48b70c
// 0048b6d5  668b4606             mov ax, word ptr [esi + 6]
// 0048b6d9  663b44240e           cmp ax, word ptr [esp + 0xe]
// 0048b6de  752c                 jne 0x48b70c
// 0048b6e0  668b4e08             mov cx, word ptr [esi + 8]
// 0048b6e4  663b4c2410           cmp cx, word ptr [esp + 0x10]
// 0048b6e9  7521                 jne 0x48b70c
// 0048b6eb  668b560a             mov dx, word ptr [esi + 0xa]
// 0048b6ef  663b542412           cmp dx, word ptr [esp + 0x12]
// 0048b6f4  7516                 jne 0x48b70c
// 0048b6f6  668b460c             mov ax, word ptr [esi + 0xc]
// 0048b6fa  663b442414           cmp ax, word ptr [esp + 0x14]
// 0048b6ff  750b                 jne 0x48b70c
// 0048b701  5e                   pop esi
// 0048b702  b801000000           mov eax, 1
// 0048b707  5f                   pop edi
// 0048b708  83c410               add esp, 0x10
// 0048b70b  c3                   ret 
// 0048b70c  5e                   pop esi
// 0048b70d  33c0                 xor eax, eax
// 0048b70f  5f                   pop edi
// 0048b710  83c410               add esp, 0x10
// 0048b713  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxshelllistctrl.cpp (function ?AtlConvertSystemTimeToVariantTime@ATL@@YAHABU_SYSTEMTIME@@PAN@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxshelllistctrl.cpp
