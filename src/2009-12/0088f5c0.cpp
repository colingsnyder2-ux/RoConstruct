// from server: 100% by auto
// roc 2009-12 0088f5c0  unit: ATL::D::DV?$ChTraitsCRT::DV?$StrTraitMFC_DLL::IIV?$CStringT::?$CMap  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0088f5c0
//
// 0088f5c0  51                   push ecx
// 0088f5c1  56                   push esi
// 0088f5c2  57                   push edi
// 0088f5c3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0088f5c7  8bf1                 mov esi, ecx
// 0088f5c9  8d442410             lea eax, [esp + 0x10]
// 0088f5cd  50                   push eax
// 0088f5ce  8d4c240c             lea ecx, [esp + 0xc]
// 0088f5d2  51                   push ecx
// 0088f5d3  57                   push edi
// 0088f5d4  8bce                 mov ecx, esi
// 0088f5d6  e8d5c2f7ff           call 0x80b8b0
// 0088f5db  85c0                 test eax, eax
// 0088f5dd  753f                 jne 0x88f61e
// 0088f5df  394604               cmp dword ptr [esi + 4], eax
// 0088f5e2  7518                 jne 0x88f5fc
// 0088f5e4  8b5608               mov edx, dword ptr [esi + 8]
// 0088f5e7  6a01                 push 1
// 0088f5e9  52                   push edx
// 0088f5ea  8bce                 mov ecx, esi
// 0088f5ec  e8bfefffff           call 0x88e5b0
// 0088f5f1  837e0400             cmp dword ptr [esi + 4], 0
// 0088f5f5  7505                 jne 0x88f5fc
// 0088f5f7  e81045f6ff           call 0x7f3b0c
// 0088f5fc  57                   push edi
// 0088f5fd  8bce                 mov ecx, esi
// 0088f5ff  e86cfdffff           call 0x88f370
// 0088f604  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0088f608  89480c               mov dword ptr [eax + 0xc], ecx
// 0088f60b  8b5604               mov edx, dword ptr [esi + 4]
// 0088f60e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0088f612  8b148a               mov edx, dword ptr [edx + ecx*4]
// 0088f615  895008               mov dword ptr [eax + 8], edx
// 0088f618  8b5604               mov edx, dword ptr [esi + 4]
// 0088f61b  89048a               mov dword ptr [edx + ecx*4], eax
// 0088f61e  5f                   pop edi
// 0088f61f  83c004               add eax, 4
// 0088f622  5e                   pop esi
// 0088f623  59                   pop ecx
// 0088f624  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??A?$CMap@PAUHICON__@@PAU1@HH@@QAEAAHPAUHICON__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
