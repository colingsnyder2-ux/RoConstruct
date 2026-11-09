// from server: 100% by auto
// roc 2009-06 007659d0  unit: CXTPCustomizeCommandsPage  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007659d0
//
// 007659d0  56                   push esi
// 007659d1  8bf1                 mov esi, ecx
// 007659d3  8b8638010000         mov eax, dword ptr [esi + 0x138]
// 007659d9  8b5620               mov edx, dword ptr [esi + 0x20]
// 007659dc  8b88b8000000         mov ecx, dword ptr [eax + 0xb8]
// 007659e2  52                   push edx
// 007659e3  e8d854fcff           call 0x72aec0
// 007659e8  8bc8                 mov ecx, eax
// 007659ea  e8f1e50200           call 0x793fe0
// 007659ef  8bce                 mov ecx, esi
// 007659f1  5e                   pop esi
// 007659f2  e9f73afbff           jmp 0x7194ee
// library xtp-13.2.1/Source\CommandBars\XTPCustomizeCommandsPage.cpp (function ?OnDestroy@CXTPCustomizeCommandsPage@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCustomizeCommandsPage.cpp
