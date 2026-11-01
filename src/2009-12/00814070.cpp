// from server: 100% by auto
// roc 2009-12 00814070  unit: CXTPCommandBars  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00814070
//
// 00814070  85c9                 test ecx, ecx
// 00814072  7505                 jne 0x814079
// 00814074  33c0                 xor eax, eax
// 00814076  c20400               ret 4
// 00814079  8b89bc000000         mov ecx, dword ptr [ecx + 0xbc]
// 0081407f  e94c25feff           jmp 0x7f65d0
// library xtp-15.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?FindAction@CXTPCommandBars@@QBEPAVCXTPControlAction@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBars.cpp
