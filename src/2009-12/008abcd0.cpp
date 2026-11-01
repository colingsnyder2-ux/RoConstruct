// from server: 100% by auto
// roc 2009-12 008abcd0  unit: CXTPDockingPaneAutoHidePanel  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008abcd0
//
// 008abcd0  8b442404             mov eax, dword ptr [esp + 4]
// 008abcd4  56                   push esi
// 008abcd5  50                   push eax
// 008abcd6  8bf1                 mov esi, ecx
// 008abcd8  e853a70700           call 0x926430
// 008abcdd  85c0                 test eax, eax
// 008abcdf  7408                 je 0x8abce9
// 008abce1  50                   push eax
// 008abce2  8bce                 mov ecx, esi
// 008abce4  e887f1ffff           call 0x8aae70
// 008abce9  b801000000           mov eax, 1
// 008abcee  5e                   pop esi
// 008abcef  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPScrollBase.cpp (function ?OnPrintClient@CXTPCommandBarScrollBarCtrl@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPScrollBase.cpp
