// from server: 100% by auto
// roc 2007-03 006541b0  unit: seg_00650000  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006541b0
//
// 006541b0  51                   push ecx
// 006541b1  56                   push esi
// 006541b2  57                   push edi
// 006541b3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 006541b7  8bf1                 mov esi, ecx
// 006541b9  8d442410             lea eax, [esp + 0x10]
// 006541bd  50                   push eax
// 006541be  8d4c240c             lea ecx, [esp + 0xc]
// 006541c2  51                   push ecx
// 006541c3  57                   push edi
// 006541c4  8bce                 mov ecx, esi
// 006541c6  e805ebffff           call 0x652cd0
// 006541cb  85c0                 test eax, eax
// 006541cd  753f                 jne 0x65420e
// 006541cf  394604               cmp dword ptr [esi + 4], eax
// 006541d2  7518                 jne 0x6541ec
// 006541d4  8b5608               mov edx, dword ptr [esi + 8]
// 006541d7  6a01                 push 1
// 006541d9  52                   push edx
// 006541da  8bce                 mov ecx, esi
// 006541dc  e8bfc40200           call 0x6806a0
// 006541e1  837e0400             cmp dword ptr [esi + 4], 0
// 006541e5  7505                 jne 0x6541ec
// 006541e7  e8c2a1fcff           call 0x61e3ae
// 006541ec  57                   push edi
// 006541ed  8bce                 mov ecx, esi
// 006541ef  e8fcf5ffff           call 0x6537f0
// 006541f4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006541f8  89484c               mov dword ptr [eax + 0x4c], ecx
// 006541fb  8b5604               mov edx, dword ptr [esi + 4]
// 006541fe  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00654202  8b148a               mov edx, dword ptr [edx + ecx*4]
// 00654205  895048               mov dword ptr [eax + 0x48], edx
// 00654208  8b5604               mov edx, dword ptr [esi + 4]
// 0065420b  89048a               mov dword ptr [edx + ecx*4], eax
// 0065420e  5f                   pop edi
// 0065420f  83c004               add eax, 4
// 00654212  5e                   pop esi
// 00654213  59                   pop ecx
// 00654214  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ??A?$CMap@PAXPAXUCLRFONT@CXTPTreeBase@@AAU12@@@QAEAAUCLRFONT@CXTPTreeBase@@PAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
