// from server: 100% by auto
// roc 2009-06 007b55a0  unit: ATL::D::DV?$ChTraitsCRT::DV?$StrTraitMFC_DLL::IIV?$CStringT::?$CMap  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007b55a0
//
// 007b55a0  51                   push ecx
// 007b55a1  56                   push esi
// 007b55a2  57                   push edi
// 007b55a3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007b55a7  8bf1                 mov esi, ecx
// 007b55a9  8d442410             lea eax, [esp + 0x10]
// 007b55ad  50                   push eax
// 007b55ae  8d4c240c             lea ecx, [esp + 0xc]
// 007b55b2  51                   push ecx
// 007b55b3  57                   push edi
// 007b55b4  8bce                 mov ecx, esi
// 007b55b6  e815d0fcff           call 0x7825d0
// 007b55bb  85c0                 test eax, eax
// 007b55bd  753f                 jne 0x7b55fe
// 007b55bf  394604               cmp dword ptr [esi + 4], eax
// 007b55c2  7518                 jne 0x7b55dc
// 007b55c4  8b5608               mov edx, dword ptr [esi + 8]
// 007b55c7  6a01                 push 1
// 007b55c9  52                   push edx
// 007b55ca  8bce                 mov ecx, esi
// 007b55cc  e8bfefffff           call 0x7b4590
// 007b55d1  837e0400             cmp dword ptr [esi + 4], 0
// 007b55d5  7505                 jne 0x7b55dc
// 007b55d7  e80837f6ff           call 0x718ce4
// 007b55dc  57                   push edi
// 007b55dd  8bce                 mov ecx, esi
// 007b55df  e86cfdffff           call 0x7b5350
// 007b55e4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007b55e8  89480c               mov dword ptr [eax + 0xc], ecx
// 007b55eb  8b5604               mov edx, dword ptr [esi + 4]
// 007b55ee  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007b55f2  8b148a               mov edx, dword ptr [edx + ecx*4]
// 007b55f5  895008               mov dword ptr [eax + 8], edx
// 007b55f8  8b5604               mov edx, dword ptr [esi + 4]
// 007b55fb  89048a               mov dword ptr [edx + ecx*4], eax
// 007b55fe  5f                   pop edi
// 007b55ff  83c004               add eax, 4
// 007b5602  5e                   pop esi
// 007b5603  59                   pop ecx
// 007b5604  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??A?$CMap@PAUHICON__@@PAU1@HH@@QAEAAHPAUHICON__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
