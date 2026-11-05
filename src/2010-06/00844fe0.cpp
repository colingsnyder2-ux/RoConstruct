// from server: 100% by auto
// roc 2010-06 00844fe0  unit: CXTPDockBar  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00844fe0
//
// 00844fe0  56                   push esi
// 00844fe1  8b742408             mov esi, dword ptr [esp + 8]
// 00844fe5  56                   push esi
// 00844fe6  e8392af6ff           call 0x7a7a24
// 00844feb  85c0                 test eax, eax
// 00844fed  7504                 jne 0x844ff3
// 00844fef  5e                   pop esi
// 00844ff0  c20400               ret 4
// 00844ff3  814e2000000004       or dword ptr [esi + 0x20], 0x4000000
// 00844ffa  b801000000           mov eax, 1
// 00844fff  5e                   pop esi
// 00845000  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPDockBar.cpp (function ?PreCreateWindow@CXTPDockBar@@MAEHAAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPDockBar.cpp
