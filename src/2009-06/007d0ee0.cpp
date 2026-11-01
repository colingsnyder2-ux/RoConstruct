// from server: 100% by auto
// roc 2009-06 007d0ee0  unit: CXTPDockingPaneAutoHidePanel  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007d0ee0
//
// 007d0ee0  8b442404             mov eax, dword ptr [esp + 4]
// 007d0ee4  56                   push esi
// 007d0ee5  50                   push eax
// 007d0ee6  8bf1                 mov esi, ecx
// 007d0ee8  e81fb00700           call 0x84bf0c
// 007d0eed  85c0                 test eax, eax
// 007d0eef  7408                 je 0x7d0ef9
// 007d0ef1  50                   push eax
// 007d0ef2  8bce                 mov ecx, esi
// 007d0ef4  e857f1ffff           call 0x7d0050
// 007d0ef9  b801000000           mov eax, 1
// 007d0efe  5e                   pop esi
// 007d0eff  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPScrollBase.cpp (function ?OnPrintClient@CXTPCommandBarScrollBarCtrl@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPScrollBase.cpp
