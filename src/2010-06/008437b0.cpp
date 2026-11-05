// from server: 100% by auto
// roc 2010-06 008437b0  unit: ATL::D::DV?$ChTraitsCRT::DV?$StrTraitMFC_DLL::IIV?$CStringT::?$CMap  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008437b0
//
// 008437b0  51                   push ecx
// 008437b1  56                   push esi
// 008437b2  57                   push edi
// 008437b3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 008437b7  8bf1                 mov esi, ecx
// 008437b9  8d442410             lea eax, [esp + 0x10]
// 008437bd  50                   push eax
// 008437be  8d4c240c             lea ecx, [esp + 0xc]
// 008437c2  51                   push ecx
// 008437c3  57                   push edi
// 008437c4  8bce                 mov ecx, esi
// 008437c6  e84583f6ff           call 0x7abb10
// 008437cb  85c0                 test eax, eax
// 008437cd  753f                 jne 0x84380e
// 008437cf  394604               cmp dword ptr [esi + 4], eax
// 008437d2  7518                 jne 0x8437ec
// 008437d4  8b5608               mov edx, dword ptr [esi + 8]
// 008437d7  6a01                 push 1
// 008437d9  52                   push edx
// 008437da  8bce                 mov ecx, esi
// 008437dc  e8ff21faff           call 0x7e59e0
// 008437e1  837e0400             cmp dword ptr [esi + 4], 0
// 008437e5  7505                 jne 0x8437ec
// 008437e7  e86044f6ff           call 0x7a7c4c
// 008437ec  57                   push edi
// 008437ed  8bce                 mov ecx, esi
// 008437ef  e86cfdffff           call 0x843560
// 008437f4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008437f8  89480c               mov dword ptr [eax + 0xc], ecx
// 008437fb  8b5604               mov edx, dword ptr [esi + 4]
// 008437fe  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00843802  8b148a               mov edx, dword ptr [edx + ecx*4]
// 00843805  895008               mov dword ptr [eax + 8], edx
// 00843808  8b5604               mov edx, dword ptr [esi + 4]
// 0084380b  89048a               mov dword ptr [edx + ecx*4], eax
// 0084380e  5f                   pop edi
// 0084380f  83c004               add eax, 4
// 00843812  5e                   pop esi
// 00843813  59                   pop ecx
// 00843814  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??A?$CMap@PAUHICON__@@PAU1@HH@@QAEAAHPAUHICON__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
