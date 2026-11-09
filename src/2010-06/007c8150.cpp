// from server: 100% by auto
// roc 2010-06 007c8150  unit: CXTPCommandBars  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c8150
//
// 007c8150  85c9                 test ecx, ecx
// 007c8152  7505                 jne 0x7c8159
// 007c8154  33c0                 xor eax, eax
// 007c8156  c20400               ret 4
// 007c8159  8b89bc000000         mov ecx, dword ptr [ecx + 0xbc]
// 007c815f  e94c25feff           jmp 0x7aa6b0
// library xtp-13.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?FindAction@CXTPCommandBars@@QBEPAVCXTPControlAction@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCommandBars.cpp
