// from server: 100% by auto
// roc 2011-06 0086c0b0  unit: CXTPStatusBar  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0086c0b0
//
// 0086c0b0  56                   push esi
// 0086c0b1  8bf1                 mov esi, ecx
// 0086c0b3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0086c0b7  57                   push edi
// 0086c0b8  8bbe84000000         mov edi, dword ptr [esi + 0x84]
// 0086c0be  8bc7                 mov eax, edi
// 0086c0c0  25fff0ffff           and eax, 0xfffff0ff
// 0086c0c5  51                   push ecx
// 0086c0c6  8bce                 mov ecx, esi
// 0086c0c8  898684000000         mov dword ptr [esi + 0x84], eax
// 0086c0ce  e81f0a1600           call 0x9ccaf2
// 0086c0d3  89be84000000         mov dword ptr [esi + 0x84], edi
// 0086c0d9  5f                   pop edi
// 0086c0da  5e                   pop esi
// 0086c0db  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\bardock.cpp (function ?OnWindowPosChanging@CDockBar@@IAEXPAUtagWINDOWPOS@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/bardock.cpp
