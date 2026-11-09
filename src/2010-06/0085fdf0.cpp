// from server: 100% by auto
// roc 2010-06 0085fdf0  unit: CXTPDockingPaneAutoHidePanel  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0085fdf0
//
// 0085fdf0  8b442404             mov eax, dword ptr [esp + 4]
// 0085fdf4  56                   push esi
// 0085fdf5  50                   push eax
// 0085fdf6  8bf1                 mov esi, ecx
// 0085fdf8  e86fcf1100           call 0x97cd6c
// 0085fdfd  85c0                 test eax, eax
// 0085fdff  7408                 je 0x85fe09
// 0085fe01  50                   push eax
// 0085fe02  8bce                 mov ecx, esi
// 0085fe04  e897f1ffff           call 0x85efa0
// 0085fe09  b801000000           mov eax, 1
// 0085fe0e  5e                   pop esi
// 0085fe0f  c20800               ret 8
// library xtp-13.2.1/Source\CommandBars\XTPScrollBase.cpp (function ?OnPrintClient@CXTPCommandBarScrollBarCtrl@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPScrollBase.cpp
