// from server: 100% by auto
// roc 2007-03 0062b3c0  unit: seg_00620000  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0062b3c0
//
// 0062b3c0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0062b3c4  85c9                 test ecx, ecx
// 0062b3c6  740f                 je 0x62b3d7
// 0062b3c8  e893370100           call 0x63eb60
// 0062b3cd  85c0                 test eax, eax
// 0062b3cf  7406                 je 0x62b3d7
// 0062b3d1  b801000000           mov eax, 1
// 0062b3d6  c3                   ret 
// 0062b3d7  33c0                 xor eax, eax
// 0062b3d9  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?IsToolBarVisible@@YAHPAVCXTPToolBar@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBars.cpp
