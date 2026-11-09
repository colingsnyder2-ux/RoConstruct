// from server: 100% by auto
// roc 2010-06 007c8120  unit: CXTPCommandBars  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c8120
//
// 007c8120  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007c8124  85c9                 test ecx, ecx
// 007c8126  740f                 je 0x7c8137
// 007c8128  e8e3eeffff           call 0x7c7010
// 007c812d  85c0                 test eax, eax
// 007c812f  7406                 je 0x7c8137
// 007c8131  b801000000           mov eax, 1
// 007c8136  c3                   ret 
// 007c8137  33c0                 xor eax, eax
// 007c8139  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?IsToolBarVisible@@YAHPAVCXTPToolBar@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCommandBars.cpp
