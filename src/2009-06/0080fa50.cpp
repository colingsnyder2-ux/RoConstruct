// from server: 100% by auto
// roc 2009-06 0080fa50  unit: CXTPRibbonTab  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0080fa50
//
// 0080fa50  56                   push esi
// 0080fa51  57                   push edi
// 0080fa52  8bf1                 mov esi, ecx
// 0080fa54  e8e766e9ff           call 0x6a6140
// 0080fa59  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0080fa5d  3bf8                 cmp edi, eax
// 0080fa5f  7428                 je 0x80fa89
// 0080fa61  57                   push edi
// 0080fa62  8bce                 mov ecx, esi
// 0080fa64  e8073afeff           call 0x7f3470
// 0080fa69  85ff                 test edi, edi
// 0080fa6b  751c                 jne 0x80fa89
// 0080fa6d  8b4e60               mov ecx, dword ptr [esi + 0x60]
// 0080fa70  397104               cmp dword ptr [ecx + 4], esi
// 0080fa73  7514                 jne 0x80fa89
// 0080fa75  6a01                 push 1
// 0080fa77  6aff                 push -1
// 0080fa79  e85251feff           call 0x7f4bd0
// 0080fa7e  85c0                 test eax, eax
// 0080fa80  7407                 je 0x80fa89
// 0080fa82  8bc8                 mov ecx, eax
// 0080fa84  e8d739feff           call 0x7f3460
// 0080fa89  5f                   pop edi
// 0080fa8a  5e                   pop esi
// 0080fa8b  c20400               ret 4
// library xtp-15.2.1/Source\Ribbon\XTPRibbonTab.cpp (function ?SetVisible@CXTPRibbonTab@@UAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonTab.cpp
