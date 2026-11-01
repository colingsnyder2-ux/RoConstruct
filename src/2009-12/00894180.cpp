// from server: 100% by auto
// roc 2009-12 00894180  unit: CXTPMenuBar  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00894180
//
// 00894180  51                   push ecx
// 00894181  56                   push esi
// 00894182  57                   push edi
// 00894183  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00894187  8bf1                 mov esi, ecx
// 00894189  8d442410             lea eax, [esp + 0x10]
// 0089418d  50                   push eax
// 0089418e  8d4c240c             lea ecx, [esp + 0xc]
// 00894192  51                   push ecx
// 00894193  57                   push edi
// 00894194  8bce                 mov ecx, esi
// 00894196  e81577f7ff           call 0x80b8b0
// 0089419b  85c0                 test eax, eax
// 0089419d  753f                 jne 0x8941de
// 0089419f  394604               cmp dword ptr [esi + 4], eax
// 008941a2  7518                 jne 0x8941bc
// 008941a4  8b5608               mov edx, dword ptr [esi + 8]
// 008941a7  6a01                 push 1
// 008941a9  52                   push edx
// 008941aa  8bce                 mov ecx, esi
// 008941ac  e8ffa3ffff           call 0x88e5b0
// 008941b1  837e0400             cmp dword ptr [esi + 4], 0
// 008941b5  7505                 jne 0x8941bc
// 008941b7  e850f9f5ff           call 0x7f3b0c
// 008941bc  57                   push edi
// 008941bd  8bce                 mov ecx, esi
// 008941bf  e8ec87f7ff           call 0x80c9b0
// 008941c4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008941c8  89480c               mov dword ptr [eax + 0xc], ecx
// 008941cb  8b5604               mov edx, dword ptr [esi + 4]
// 008941ce  8b4c2408             mov ecx, dword ptr [esp + 8]
// 008941d2  8b148a               mov edx, dword ptr [edx + ecx*4]
// 008941d5  895008               mov dword ptr [eax + 8], edx
// 008941d8  8b5604               mov edx, dword ptr [esi + 4]
// 008941db  89048a               mov dword ptr [edx + ecx*4], eax
// 008941de  5f                   pop edi
// 008941df  83c004               add eax, 4
// 008941e2  5e                   pop esi
// 008941e3  59                   pop ecx
// 008941e4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??A?$CMap@PAUHICON__@@PAU1@HH@@QAEAAHPAUHICON__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
