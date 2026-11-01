// from server: 100% by auto
// roc 2009-12 00834650  unit: CRobloxTreeCtrl  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00834650
//
// 00834650  51                   push ecx
// 00834651  56                   push esi
// 00834652  57                   push edi
// 00834653  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00834657  8bf1                 mov esi, ecx
// 00834659  8d442410             lea eax, [esp + 0x10]
// 0083465d  50                   push eax
// 0083465e  8d4c240c             lea ecx, [esp + 0xc]
// 00834662  51                   push ecx
// 00834663  57                   push edi
// 00834664  8bce                 mov ecx, esi
// 00834666  e815ebffff           call 0x833180
// 0083466b  85c0                 test eax, eax
// 0083466d  753f                 jne 0x8346ae
// 0083466f  394604               cmp dword ptr [esi + 4], eax
// 00834672  7518                 jne 0x83468c
// 00834674  8b5608               mov edx, dword ptr [esi + 8]
// 00834677  6a01                 push 1
// 00834679  52                   push edx
// 0083467a  8bce                 mov ecx, esi
// 0083467c  e82f9f0500           call 0x88e5b0
// 00834681  837e0400             cmp dword ptr [esi + 4], 0
// 00834685  7505                 jne 0x83468c
// 00834687  e880f4fbff           call 0x7f3b0c
// 0083468c  57                   push edi
// 0083468d  8bce                 mov ecx, esi
// 0083468f  e80cf6ffff           call 0x833ca0
// 00834694  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00834698  89484c               mov dword ptr [eax + 0x4c], ecx
// 0083469b  8b5604               mov edx, dword ptr [esi + 4]
// 0083469e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 008346a2  8b148a               mov edx, dword ptr [edx + ecx*4]
// 008346a5  895048               mov dword ptr [eax + 0x48], edx
// 008346a8  8b5604               mov edx, dword ptr [esi + 4]
// 008346ab  89048a               mov dword ptr [edx + ecx*4], eax
// 008346ae  5f                   pop edi
// 008346af  83c004               add eax, 4
// 008346b2  5e                   pop esi
// 008346b3  59                   pop ecx
// 008346b4  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ??A?$CMap@PAXPAXUCLRFONT@CXTPTreeBase@@AAU12@@@QAEAAUCLRFONT@CXTPTreeBase@@PAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
