// from server: 100% by auto
// roc 2009-06 00729360  unit: CXTPCommandBars  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00729360
//
// 00729360  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00729364  85c9                 test ecx, ecx
// 00729366  740f                 je 0x729377
// 00729368  e8f32a0100           call 0x73be60
// 0072936d  85c0                 test eax, eax
// 0072936f  7406                 je 0x729377
// 00729371  b801000000           mov eax, 1
// 00729376  c3                   ret 
// 00729377  33c0                 xor eax, eax
// 00729379  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?IsToolBarVisible@@YAHPAVCXTPToolBar@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBars.cpp
