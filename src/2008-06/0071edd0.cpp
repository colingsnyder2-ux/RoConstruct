// from server: 100% by auto
// roc 2008-06 0071edd0  unit: ATL::D::DV?$ChTraitsCRT::DV?$StrTraitMFC_DLL::IIV?$CStringT::?$CMap  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0071edd0
//
// 0071edd0  51                   push ecx
// 0071edd1  56                   push esi
// 0071edd2  57                   push edi
// 0071edd3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0071edd7  8bf1                 mov esi, ecx
// 0071edd9  8d442410             lea eax, [esp + 0x10]
// 0071eddd  50                   push eax
// 0071edde  8d4c240c             lea ecx, [esp + 0xc]
// 0071ede2  51                   push ecx
// 0071ede3  57                   push edi
// 0071ede4  8bce                 mov ecx, esi
// 0071ede6  e89592feff           call 0x708080
// 0071edeb  85c0                 test eax, eax
// 0071eded  753f                 jne 0x71ee2e
// 0071edef  394604               cmp dword ptr [esi + 4], eax
// 0071edf2  7518                 jne 0x71ee0c
// 0071edf4  8b5608               mov edx, dword ptr [esi + 8]
// 0071edf7  6a01                 push 1
// 0071edf9  52                   push edx
// 0071edfa  8bce                 mov ecx, esi
// 0071edfc  e84f9ad1ff           call 0x438850
// 0071ee01  837e0400             cmp dword ptr [esi + 4], 0
// 0071ee05  7505                 jne 0x71ee0c
// 0071ee07  e8381bf8ff           call 0x6a0944
// 0071ee0c  57                   push edi
// 0071ee0d  8bce                 mov ecx, esi
// 0071ee0f  e86cfdffff           call 0x71eb80
// 0071ee14  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0071ee18  89480c               mov dword ptr [eax + 0xc], ecx
// 0071ee1b  8b5604               mov edx, dword ptr [esi + 4]
// 0071ee1e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0071ee22  8b148a               mov edx, dword ptr [edx + ecx*4]
// 0071ee25  895008               mov dword ptr [eax + 8], edx
// 0071ee28  8b5604               mov edx, dword ptr [esi + 4]
// 0071ee2b  89048a               mov dword ptr [edx + ecx*4], eax
// 0071ee2e  5f                   pop edi
// 0071ee2f  83c004               add eax, 4
// 0071ee32  5e                   pop esi
// 0071ee33  59                   pop ecx
// 0071ee34  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??A?$CMap@PAUHICON__@@PAU1@HH@@QAEAAHPAUHICON__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
