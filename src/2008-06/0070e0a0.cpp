// from server: 100% by auto
// roc 2008-06 0070e0a0  unit: CXTPStatusBar  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0070e0a0
//
// 0070e0a0  56                   push esi
// 0070e0a1  8bf1                 mov esi, ecx
// 0070e0a3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0070e0a7  57                   push edi
// 0070e0a8  8bbe84000000         mov edi, dword ptr [esi + 0x84]
// 0070e0ae  8bc7                 mov eax, edi
// 0070e0b0  25fff0ffff           and eax, 0xfffff0ff
// 0070e0b5  51                   push ecx
// 0070e0b6  8bce                 mov ecx, esi
// 0070e0b8  898684000000         mov dword ptr [esi + 0x84], eax
// 0070e0be  e863e70a00           call 0x7bc826
// 0070e0c3  89be84000000         mov dword ptr [esi + 0x84], edi
// 0070e0c9  5f                   pop edi
// 0070e0ca  5e                   pop esi
// 0070e0cb  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\bardock.cpp (function ?OnWindowPosChanging@CDockBar@@IAEXPAUtagWINDOWPOS@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/bardock.cpp
