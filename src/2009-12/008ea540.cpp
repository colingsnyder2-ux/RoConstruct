// from server: 100% by auto
// roc 2009-12 008ea540  unit: CXTPRibbonTab  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008ea540
//
// 008ea540  56                   push esi
// 008ea541  57                   push edi
// 008ea542  8bf1                 mov esi, ecx
// 008ea544  e8a78ee8ff           call 0x7733f0
// 008ea549  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 008ea54d  3bf8                 cmp edi, eax
// 008ea54f  7428                 je 0x8ea579
// 008ea551  57                   push edi
// 008ea552  8bce                 mov ecx, esi
// 008ea554  e8c73afeff           call 0x8ce020
// 008ea559  85ff                 test edi, edi
// 008ea55b  751c                 jne 0x8ea579
// 008ea55d  8b4e60               mov ecx, dword ptr [esi + 0x60]
// 008ea560  397104               cmp dword ptr [ecx + 4], esi
// 008ea563  7514                 jne 0x8ea579
// 008ea565  6a01                 push 1
// 008ea567  6aff                 push -1
// 008ea569  e81252feff           call 0x8cf780
// 008ea56e  85c0                 test eax, eax
// 008ea570  7407                 je 0x8ea579
// 008ea572  8bc8                 mov ecx, eax
// 008ea574  e8973afeff           call 0x8ce010
// 008ea579  5f                   pop edi
// 008ea57a  5e                   pop esi
// 008ea57b  c20400               ret 4
// library xtp-15.2.1/Source\Ribbon\XTPRibbonTab.cpp (function ?SetVisible@CXTPRibbonTab@@UAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonTab.cpp
