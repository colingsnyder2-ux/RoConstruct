// from server: 100% by auto
// roc 2009-06 00736420  unit: KKPAVCXTPImageManagerResource::?$CMap  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00736420
//
// 00736420  51                   push ecx
// 00736421  56                   push esi
// 00736422  57                   push edi
// 00736423  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00736427  8bf1                 mov esi, ecx
// 00736429  8d442410             lea eax, [esp + 0x10]
// 0073642d  50                   push eax
// 0073642e  8d4c240c             lea ecx, [esp + 0xc]
// 00736432  51                   push ecx
// 00736433  57                   push edi
// 00736434  8bce                 mov ecx, esi
// 00736436  e895c10400           call 0x7825d0
// 0073643b  85c0                 test eax, eax
// 0073643d  753f                 jne 0x73647e
// 0073643f  394604               cmp dword ptr [esi + 4], eax
// 00736442  7518                 jne 0x73645c
// 00736444  8b5608               mov edx, dword ptr [esi + 8]
// 00736447  6a01                 push 1
// 00736449  52                   push edx
// 0073644a  8bce                 mov ecx, esi
// 0073644c  e83fe10700           call 0x7b4590
// 00736451  837e0400             cmp dword ptr [esi + 4], 0
// 00736455  7505                 jne 0x73645c
// 00736457  e88828feff           call 0x718ce4
// 0073645c  57                   push edi
// 0073645d  8bce                 mov ecx, esi
// 0073645f  e89cf4ffff           call 0x735900
// 00736464  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00736468  89480c               mov dword ptr [eax + 0xc], ecx
// 0073646b  8b5604               mov edx, dword ptr [esi + 4]
// 0073646e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00736472  8b148a               mov edx, dword ptr [edx + ecx*4]
// 00736475  895008               mov dword ptr [eax + 8], edx
// 00736478  8b5604               mov edx, dword ptr [esi + 4]
// 0073647b  89048a               mov dword ptr [edx + ecx*4], eax
// 0073647e  5f                   pop edi
// 0073647f  83c004               add eax, 4
// 00736482  5e                   pop esi
// 00736483  59                   pop ecx
// 00736484  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??A?$CMap@PAUHICON__@@PAU1@HH@@QAEAAHPAUHICON__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
