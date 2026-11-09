// from server: 100% by auto
// roc 2010-06 004352d0  unit: CPropGrid::UpdateItemsJob  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004352d0
//
// 004352d0  51                   push ecx
// 004352d1  56                   push esi
// 004352d2  57                   push edi
// 004352d3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004352d7  8bf1                 mov esi, ecx
// 004352d9  8d442410             lea eax, [esp + 0x10]
// 004352dd  50                   push eax
// 004352de  8d4c240c             lea ecx, [esp + 0xc]
// 004352e2  51                   push ecx
// 004352e3  57                   push edi
// 004352e4  8bce                 mov ecx, esi
// 004352e6  e8b5f6ffff           call 0x4349a0
// 004352eb  85c0                 test eax, eax
// 004352ed  753f                 jne 0x43532e
// 004352ef  394604               cmp dword ptr [esi + 4], eax
// 004352f2  7518                 jne 0x43530c
// 004352f4  8b5608               mov edx, dword ptr [esi + 8]
// 004352f7  6a01                 push 1
// 004352f9  52                   push edx
// 004352fa  8bce                 mov ecx, esi
// 004352fc  e8df063b00           call 0x7e59e0
// 00435301  837e0400             cmp dword ptr [esi + 4], 0
// 00435305  7505                 jne 0x43530c
// 00435307  e840293700           call 0x7a7c4c
// 0043530c  57                   push edi
// 0043530d  8bce                 mov ecx, esi
// 0043530f  e87cdb4300           call 0x872e90
// 00435314  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00435318  89480c               mov dword ptr [eax + 0xc], ecx
// 0043531b  8b5604               mov edx, dword ptr [esi + 4]
// 0043531e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00435322  8b148a               mov edx, dword ptr [edx + ecx*4]
// 00435325  895008               mov dword ptr [eax + 8], edx
// 00435328  8b5604               mov edx, dword ptr [esi + 4]
// 0043532b  89048a               mov dword ptr [edx + ecx*4], eax
// 0043532e  5f                   pop edi
// 0043532f  83c004               add eax, 4
// 00435332  5e                   pop esi
// 00435333  59                   pop ecx
// 00435334  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??A?$CMap@PAUHICON__@@PAU1@HH@@QAEAAHPAUHICON__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
