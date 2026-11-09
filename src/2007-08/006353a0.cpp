// from server: 100% by auto
// roc 2007-08 006353a0  unit: MyXTPCommandBars  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006353a0
//
// 006353a0  51                   push ecx
// 006353a1  56                   push esi
// 006353a2  57                   push edi
// 006353a3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 006353a7  8bf1                 mov esi, ecx
// 006353a9  8d442410             lea eax, [esp + 0x10]
// 006353ad  50                   push eax
// 006353ae  8d4c240c             lea ecx, [esp + 0xc]
// 006353b2  51                   push ecx
// 006353b3  57                   push edi
// 006353b4  8bce                 mov ecx, esi
// 006353b6  e8152e0a00           call 0x6d81d0
// 006353bb  85c0                 test eax, eax
// 006353bd  753f                 jne 0x6353fe
// 006353bf  394604               cmp dword ptr [esi + 4], eax
// 006353c2  7518                 jne 0x6353dc
// 006353c4  8b5608               mov edx, dword ptr [esi + 8]
// 006353c7  6a01                 push 1
// 006353c9  52                   push edx
// 006353ca  8bce                 mov ecx, esi
// 006353cc  e89f3ce0ff           call 0x439070
// 006353d1  837e0400             cmp dword ptr [esi + 4], 0
// 006353d5  7505                 jne 0x6353dc
// 006353d7  e844abffff           call 0x62ff20
// 006353dc  57                   push edi
// 006353dd  8bce                 mov ecx, esi
// 006353df  e8bcad0500           call 0x6901a0
// 006353e4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006353e8  89480c               mov dword ptr [eax + 0xc], ecx
// 006353eb  8b5604               mov edx, dword ptr [esi + 4]
// 006353ee  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006353f2  8b148a               mov edx, dword ptr [edx + ecx*4]
// 006353f5  895008               mov dword ptr [eax + 8], edx
// 006353f8  8b5604               mov edx, dword ptr [esi + 4]
// 006353fb  89048a               mov dword ptr [edx + ecx*4], eax
// 006353fe  5f                   pop edi
// 006353ff  83c004               add eax, 4
// 00635402  5e                   pop esi
// 00635403  59                   pop ecx
// 00635404  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??A?$CMap@PAUHICON__@@PAU1@HH@@QAEAAHPAUHICON__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
