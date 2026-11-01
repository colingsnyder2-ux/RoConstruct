// from server: 100% by auto
// roc 2009-06 007b2420  unit: CXTPDockBar  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007b2420
//
// 007b2420  56                   push esi
// 007b2421  8b742408             mov esi, dword ptr [esp + 8]
// 007b2425  56                   push esi
// 007b2426  e89166f6ff           call 0x718abc
// 007b242b  85c0                 test eax, eax
// 007b242d  7504                 jne 0x7b2433
// 007b242f  5e                   pop esi
// 007b2430  c20400               ret 4
// 007b2433  814e2000000004       or dword ptr [esi + 0x20], 0x4000000
// 007b243a  b801000000           mov eax, 1
// 007b243f  5e                   pop esi
// 007b2440  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPDockBar.cpp (function ?PreCreateWindow@CXTPDockBar@@MAEHAAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDockBar.cpp
