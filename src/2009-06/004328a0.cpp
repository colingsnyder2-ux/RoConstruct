// from server: 100% by auto
// roc 2009-06 004328a0  unit: IIHAAH::?$CMap  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004328a0
//
// 004328a0  51                   push ecx
// 004328a1  56                   push esi
// 004328a2  57                   push edi
// 004328a3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004328a7  8bf1                 mov esi, ecx
// 004328a9  8d442410             lea eax, [esp + 0x10]
// 004328ad  50                   push eax
// 004328ae  8d4c240c             lea ecx, [esp + 0xc]
// 004328b2  51                   push ecx
// 004328b3  57                   push edi
// 004328b4  8bce                 mov ecx, esi
// 004328b6  e8e5f9ffff           call 0x4322a0
// 004328bb  85c0                 test eax, eax
// 004328bd  753f                 jne 0x4328fe
// 004328bf  394604               cmp dword ptr [esi + 4], eax
// 004328c2  7518                 jne 0x4328dc
// 004328c4  8b5608               mov edx, dword ptr [esi + 8]
// 004328c7  6a01                 push 1
// 004328c9  52                   push edx
// 004328ca  8bce                 mov ecx, esi
// 004328cc  e8bf1c3800           call 0x7b4590
// 004328d1  837e0400             cmp dword ptr [esi + 4], 0
// 004328d5  7505                 jne 0x4328dc
// 004328d7  e808642e00           call 0x718ce4
// 004328dc  57                   push edi
// 004328dd  8bce                 mov ecx, esi
// 004328df  e81c303000           call 0x735900
// 004328e4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004328e8  89480c               mov dword ptr [eax + 0xc], ecx
// 004328eb  8b5604               mov edx, dword ptr [esi + 4]
// 004328ee  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004328f2  8b148a               mov edx, dword ptr [edx + ecx*4]
// 004328f5  895008               mov dword ptr [eax + 8], edx
// 004328f8  8b5604               mov edx, dword ptr [esi + 4]
// 004328fb  89048a               mov dword ptr [edx + ecx*4], eax
// 004328fe  5f                   pop edi
// 004328ff  83c004               add eax, 4
// 00432902  5e                   pop esi
// 00432903  59                   pop ecx
// 00432904  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??A?$CMap@PAUHICON__@@PAU1@HH@@QAEAAHPAUHICON__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
