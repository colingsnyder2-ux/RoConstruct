// from server: 100% by auto
// roc 2007-08 006a54d0  unit: ATL::D::DV?$ChTraitsCRT::DV?$StrTraitMFC_DLL::IIV?$CStringT::?$CMap  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006a54d0
//
// 006a54d0  51                   push ecx
// 006a54d1  56                   push esi
// 006a54d2  57                   push edi
// 006a54d3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 006a54d7  8bf1                 mov esi, ecx
// 006a54d9  8d442410             lea eax, [esp + 0x10]
// 006a54dd  50                   push eax
// 006a54de  8d4c240c             lea ecx, [esp + 0xc]
// 006a54e2  51                   push ecx
// 006a54e3  57                   push edi
// 006a54e4  8bce                 mov ecx, esi
// 006a54e6  e8e52c0300           call 0x6d81d0
// 006a54eb  85c0                 test eax, eax
// 006a54ed  753f                 jne 0x6a552e
// 006a54ef  394604               cmp dword ptr [esi + 4], eax
// 006a54f2  7518                 jne 0x6a550c
// 006a54f4  8b5608               mov edx, dword ptr [esi + 8]
// 006a54f7  6a01                 push 1
// 006a54f9  52                   push edx
// 006a54fa  8bce                 mov ecx, esi
// 006a54fc  e86f3bd9ff           call 0x439070
// 006a5501  837e0400             cmp dword ptr [esi + 4], 0
// 006a5505  7505                 jne 0x6a550c
// 006a5507  e814aaf8ff           call 0x62ff20
// 006a550c  57                   push edi
// 006a550d  8bce                 mov ecx, esi
// 006a550f  e85cfdffff           call 0x6a5270
// 006a5514  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006a5518  89480c               mov dword ptr [eax + 0xc], ecx
// 006a551b  8b5604               mov edx, dword ptr [esi + 4]
// 006a551e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006a5522  8b148a               mov edx, dword ptr [edx + ecx*4]
// 006a5525  895008               mov dword ptr [eax + 8], edx
// 006a5528  8b5604               mov edx, dword ptr [esi + 4]
// 006a552b  89048a               mov dword ptr [edx + ecx*4], eax
// 006a552e  5f                   pop edi
// 006a552f  83c004               add eax, 4
// 006a5532  5e                   pop esi
// 006a5533  59                   pop ecx
// 006a5534  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??A?$CMap@PAUHICON__@@PAU1@HH@@QAEAAHPAUHICON__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
