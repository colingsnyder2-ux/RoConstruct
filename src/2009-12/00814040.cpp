// from server: 100% by auto
// roc 2009-12 00814040  unit: CXTPCommandBars  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00814040
//
// 00814040  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00814044  85c9                 test ecx, ecx
// 00814046  740f                 je 0x814057
// 00814048  e8e3eeffff           call 0x812f30
// 0081404d  85c0                 test eax, eax
// 0081404f  7406                 je 0x814057
// 00814051  b801000000           mov eax, 1
// 00814056  c3                   ret 
// 00814057  33c0                 xor eax, eax
// 00814059  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?IsToolBarVisible@@YAHPAVCXTPToolBar@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBars.cpp
