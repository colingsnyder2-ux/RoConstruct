// from server: 100% by auto
// roc 2010-06 0089f380  unit: CXTPRibbonTab  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0089f380
//
// 0089f380  56                   push esi
// 0089f381  57                   push edi
// 0089f382  8bf1                 mov esi, ecx
// 0089f384  e8672efeff           call 0x8821f0
// 0089f389  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0089f38d  3bf8                 cmp edi, eax
// 0089f38f  7428                 je 0x89f3b9
// 0089f391  57                   push edi
// 0089f392  8bce                 mov ecx, esi
// 0089f394  e8672efeff           call 0x882200
// 0089f399  85ff                 test edi, edi
// 0089f39b  751c                 jne 0x89f3b9
// 0089f39d  8b4e60               mov ecx, dword ptr [esi + 0x60]
// 0089f3a0  397104               cmp dword ptr [ecx + 4], esi
// 0089f3a3  7514                 jne 0x89f3b9
// 0089f3a5  6a01                 push 1
// 0089f3a7  6aff                 push -1
// 0089f3a9  e8b245feff           call 0x883960
// 0089f3ae  85c0                 test eax, eax
// 0089f3b0  7407                 je 0x89f3b9
// 0089f3b2  8bc8                 mov ecx, eax
// 0089f3b4  e8272efeff           call 0x8821e0
// 0089f3b9  5f                   pop edi
// 0089f3ba  5e                   pop esi
// 0089f3bb  c20400               ret 4
// library xtp-13.2.1/Source\Ribbon\XTPRibbonTab.cpp (function ?SetVisible@CXTPRibbonTab@@UAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Ribbon/XTPRibbonTab.cpp
