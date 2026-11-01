// from server: 100% by auto
// roc 2009-06 00729390  unit: CXTPCommandBars  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00729390
//
// 00729390  85c9                 test ecx, ecx
// 00729392  7505                 jne 0x729399
// 00729394  33c0                 xor eax, eax
// 00729396  c20400               ret 4
// 00729399  8b89bc000000         mov ecx, dword ptr [ecx + 0xbc]
// 0072939f  e91c6bffff           jmp 0x71fec0
// library xtp-15.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?FindAction@CXTPCommandBars@@QBEPAVCXTPControlAction@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBars.cpp
