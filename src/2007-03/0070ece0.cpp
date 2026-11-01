// from server: 100% by auto
// roc 2007-03 0070ece0  unit: seg_00700000  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0070ece0
//
// 0070ece0  56                   push esi
// 0070ece1  57                   push edi
// 0070ece2  8bf1                 mov esi, ecx
// 0070ece4  e8c768fdff           call 0x6e55b0
// 0070ece9  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0070eced  3bf8                 cmp edi, eax
// 0070ecef  7428                 je 0x70ed19
// 0070ecf1  57                   push edi
// 0070ecf2  8bce                 mov ecx, esi
// 0070ecf4  e8c768fdff           call 0x6e55c0
// 0070ecf9  85ff                 test edi, edi
// 0070ecfb  751c                 jne 0x70ed19
// 0070ecfd  8b4e60               mov ecx, dword ptr [esi + 0x60]
// 0070ed00  397104               cmp dword ptr [ecx + 4], esi
// 0070ed03  7514                 jne 0x70ed19
// 0070ed05  6a01                 push 1
// 0070ed07  6aff                 push -1
// 0070ed09  e84281fdff           call 0x6e6e50
// 0070ed0e  85c0                 test eax, eax
// 0070ed10  7407                 je 0x70ed19
// 0070ed12  8bc8                 mov ecx, eax
// 0070ed14  e88768fdff           call 0x6e55a0
// 0070ed19  5f                   pop edi
// 0070ed1a  5e                   pop esi
// 0070ed1b  c20400               ret 4
// library xtp-15.2.1/Source\Ribbon\XTPRibbonTab.cpp (function ?SetVisible@CXTPRibbonTab@@UAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonTab.cpp
