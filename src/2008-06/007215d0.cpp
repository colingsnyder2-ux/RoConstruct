// from server: 100% by auto
// roc 2008-06 007215d0  unit: CXTPMenuBar  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007215d0
//
// 007215d0  51                   push ecx
// 007215d1  56                   push esi
// 007215d2  57                   push edi
// 007215d3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007215d7  8bf1                 mov esi, ecx
// 007215d9  8d442410             lea eax, [esp + 0x10]
// 007215dd  50                   push eax
// 007215de  8d4c240c             lea ecx, [esp + 0xc]
// 007215e2  51                   push ecx
// 007215e3  57                   push edi
// 007215e4  8bce                 mov ecx, esi
// 007215e6  e8956afeff           call 0x708080
// 007215eb  85c0                 test eax, eax
// 007215ed  753f                 jne 0x72162e
// 007215ef  394604               cmp dword ptr [esi + 4], eax
// 007215f2  7518                 jne 0x72160c
// 007215f4  8b5608               mov edx, dword ptr [esi + 8]
// 007215f7  6a01                 push 1
// 007215f9  52                   push edx
// 007215fa  8bce                 mov ecx, esi
// 007215fc  e84f72d1ff           call 0x438850
// 00721601  837e0400             cmp dword ptr [esi + 4], 0
// 00721605  7505                 jne 0x72160c
// 00721607  e838f3f7ff           call 0x6a0944
// 0072160c  57                   push edi
// 0072160d  8bce                 mov ecx, esi
// 0072160f  e82cfeffff           call 0x721440
// 00721614  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00721618  89480c               mov dword ptr [eax + 0xc], ecx
// 0072161b  8b5604               mov edx, dword ptr [esi + 4]
// 0072161e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00721622  8b148a               mov edx, dword ptr [edx + ecx*4]
// 00721625  895008               mov dword ptr [eax + 8], edx
// 00721628  8b5604               mov edx, dword ptr [esi + 4]
// 0072162b  89048a               mov dword ptr [edx + ecx*4], eax
// 0072162e  5f                   pop edi
// 0072162f  83c004               add eax, 4
// 00721632  5e                   pop esi
// 00721633  59                   pop ecx
// 00721634  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??A?$CMap@PAUHICON__@@PAU1@HH@@QAEAAHPAUHICON__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
