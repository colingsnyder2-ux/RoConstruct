// from server: 100% by auto
// roc 2009-06 007597d0  unit: CRobloxTreeCtrl  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007597d0
//
// 007597d0  51                   push ecx
// 007597d1  56                   push esi
// 007597d2  57                   push edi
// 007597d3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007597d7  8bf1                 mov esi, ecx
// 007597d9  8d442410             lea eax, [esp + 0x10]
// 007597dd  50                   push eax
// 007597de  8d4c240c             lea ecx, [esp + 0xc]
// 007597e2  51                   push ecx
// 007597e3  57                   push edi
// 007597e4  8bce                 mov ecx, esi
// 007597e6  e815ebffff           call 0x758300
// 007597eb  85c0                 test eax, eax
// 007597ed  753f                 jne 0x75982e
// 007597ef  394604               cmp dword ptr [esi + 4], eax
// 007597f2  7518                 jne 0x75980c
// 007597f4  8b5608               mov edx, dword ptr [esi + 8]
// 007597f7  6a01                 push 1
// 007597f9  52                   push edx
// 007597fa  8bce                 mov ecx, esi
// 007597fc  e88fad0500           call 0x7b4590
// 00759801  837e0400             cmp dword ptr [esi + 4], 0
// 00759805  7505                 jne 0x75980c
// 00759807  e8d8f4fbff           call 0x718ce4
// 0075980c  57                   push edi
// 0075980d  8bce                 mov ecx, esi
// 0075980f  e80cf6ffff           call 0x758e20
// 00759814  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00759818  89484c               mov dword ptr [eax + 0x4c], ecx
// 0075981b  8b5604               mov edx, dword ptr [esi + 4]
// 0075981e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00759822  8b148a               mov edx, dword ptr [edx + ecx*4]
// 00759825  895048               mov dword ptr [eax + 0x48], edx
// 00759828  8b5604               mov edx, dword ptr [esi + 4]
// 0075982b  89048a               mov dword ptr [edx + ecx*4], eax
// 0075982e  5f                   pop edi
// 0075982f  83c004               add eax, 4
// 00759832  5e                   pop esi
// 00759833  59                   pop ecx
// 00759834  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ??A?$CMap@PAXPAXUCLRFONT@CXTPTreeBase@@AAU12@@@QAEAAUCLRFONT@CXTPTreeBase@@PAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
