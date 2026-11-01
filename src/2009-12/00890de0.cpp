// from server: 100% by auto
// roc 2009-12 00890de0  unit: CXTPDockBar  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00890de0
//
// 00890de0  56                   push esi
// 00890de1  8b742408             mov esi, dword ptr [esp + 8]
// 00890de5  56                   push esi
// 00890de6  e8f92af6ff           call 0x7f38e4
// 00890deb  85c0                 test eax, eax
// 00890ded  7504                 jne 0x890df3
// 00890def  5e                   pop esi
// 00890df0  c20400               ret 4
// 00890df3  814e2000000004       or dword ptr [esi + 0x20], 0x4000000
// 00890dfa  b801000000           mov eax, 1
// 00890dff  5e                   pop esi
// 00890e00  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPDockBar.cpp (function ?PreCreateWindow@CXTPDockBar@@MAEHAAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDockBar.cpp
