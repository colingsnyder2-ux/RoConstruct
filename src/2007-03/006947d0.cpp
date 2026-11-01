// from server: 100% by auto
// roc 2007-03 006947d0  unit: seg_00690000  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006947d0
//
// 006947d0  56                   push esi
// 006947d1  8b742408             mov esi, dword ptr [esp + 8]
// 006947d5  56                   push esi
// 006947d6  e8ab99f8ff           call 0x61e186
// 006947db  85c0                 test eax, eax
// 006947dd  7504                 jne 0x6947e3
// 006947df  5e                   pop esi
// 006947e0  c20400               ret 4
// 006947e3  814e2000000004       or dword ptr [esi + 0x20], 0x4000000
// 006947ea  b801000000           mov eax, 1
// 006947ef  5e                   pop esi
// 006947f0  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPDockBar.cpp (function ?PreCreateWindow@CXTPDockBar@@MAEHAAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDockBar.cpp
