// from server: 100% by auto
// roc 2007-03 00681570  unit: seg_00680000  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00681570
//
// 00681570  51                   push ecx
// 00681571  56                   push esi
// 00681572  57                   push edi
// 00681573  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00681577  8bf1                 mov esi, ecx
// 00681579  8d442410             lea eax, [esp + 0x10]
// 0068157d  50                   push eax
// 0068157e  8d4c240c             lea ecx, [esp + 0xc]
// 00681582  51                   push ecx
// 00681583  57                   push edi
// 00681584  8bce                 mov ecx, esi
// 00681586  e8a55b0100           call 0x697130
// 0068158b  85c0                 test eax, eax
// 0068158d  753f                 jne 0x6815ce
// 0068158f  394604               cmp dword ptr [esi + 4], eax
// 00681592  7518                 jne 0x6815ac
// 00681594  8b5608               mov edx, dword ptr [esi + 8]
// 00681597  6a01                 push 1
// 00681599  52                   push edx
// 0068159a  8bce                 mov ecx, esi
// 0068159c  e8fff0ffff           call 0x6806a0
// 006815a1  837e0400             cmp dword ptr [esi + 4], 0
// 006815a5  7505                 jne 0x6815ac
// 006815a7  e802cef9ff           call 0x61e3ae
// 006815ac  57                   push edi
// 006815ad  8bce                 mov ecx, esi
// 006815af  e8fc86ffff           call 0x679cb0
// 006815b4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006815b8  89480c               mov dword ptr [eax + 0xc], ecx
// 006815bb  8b5604               mov edx, dword ptr [esi + 4]
// 006815be  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006815c2  8b148a               mov edx, dword ptr [edx + ecx*4]
// 006815c5  895008               mov dword ptr [eax + 8], edx
// 006815c8  8b5604               mov edx, dword ptr [esi + 4]
// 006815cb  89048a               mov dword ptr [edx + ecx*4], eax
// 006815ce  5f                   pop edi
// 006815cf  83c004               add eax, 4
// 006815d2  5e                   pop esi
// 006815d3  59                   pop ecx
// 006815d4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??A?$CMap@PAUHICON__@@PAU1@HH@@QAEAAHPAUHICON__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
