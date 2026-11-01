// from server: 100% by auto
// roc 2012-06 00437690  unit: VCMDIFrameWnd::?$CXTPCommandBarsSiteBase  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00437690
//
// 00437690  53                   push ebx
// 00437691  56                   push esi
// 00437692  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00437696  8b4604               mov eax, dword ptr [esi + 4]
// 00437699  57                   push edi
// 0043769a  8bd9                 mov ebx, ecx
// 0043769c  3d00010000           cmp eax, 0x100
// 004376a1  723c                 jb 0x4376df
// 004376a3  3d09010000           cmp eax, 0x109
// 004376a8  7735                 ja 0x4376df
// 004376aa  8b4608               mov eax, dword ptr [esi + 8]
// 004376ad  83f80d               cmp eax, 0xd
// 004376b0  742d                 je 0x4376df
// 004376b2  83f809               cmp eax, 9
// 004376b5  7428                 je 0x4376df
// 004376b7  83f81b               cmp eax, 0x1b
// 004376ba  7423                 je 0x4376df
// 004376bc  ff15e83bb200         call dword ptr [0xb23be8]
// 004376c2  50                   push eax
// 004376c3  e89eaf5400           call 0x982666
// 004376c8  8bf8                 mov edi, eax
// 004376ca  85ff                 test edi, edi
// 004376cc  7411                 je 0x4376df
// 004376ce  e8cd6c5500           call 0x98e3a0
// 004376d3  50                   push eax
// 004376d4  8bcf                 mov ecx, edi
// 004376d6  e8bbaf5400           call 0x982696
// 004376db  85c0                 test eax, eax
// 004376dd  752b                 jne 0x43770a
// 004376df  56                   push esi
// 004376e0  8bcb                 mov ecx, ebx
// 004376e2  e871b45400           call 0x982b58
// 004376e7  85c0                 test eax, eax
// 004376e9  740b                 je 0x4376f6
// 004376eb  5f                   pop edi
// 004376ec  5e                   pop esi
// 004376ed  b801000000           mov eax, 1
// 004376f2  5b                   pop ebx
// 004376f3  c20400               ret 4
// 004376f6  8b8bec000000         mov ecx, dword ptr [ebx + 0xec]
// 004376fc  85c9                 test ecx, ecx
// 004376fe  740a                 je 0x43770a
// 00437700  56                   push esi
// 00437701  e8baca5600           call 0x9a41c0
// 00437706  85c0                 test eax, eax
// 00437708  75e1                 jne 0x4376eb
// 0043770a  5f                   pop edi
// 0043770b  5e                   pop esi
// 0043770c  33c0                 xor eax, eax
// 0043770e  5b                   pop ebx
// 0043770f  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPFrameWnd.cpp (function ?PreTranslateMessage@?$CXTPCommandBarsSiteBase@VCMDIFrameWnd@@@@MAEHPAUtagMSG@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPFrameWnd.cpp
