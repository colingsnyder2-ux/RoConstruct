// from server: 100% by auto
// roc 2007-03 0062b3f0  unit: seg_00620000  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0062b3f0
//
// 0062b3f0  85c9                 test ecx, ecx
// 0062b3f2  7505                 jne 0x62b3f9
// 0062b3f4  33c0                 xor eax, eax
// 0062b3f6  c20400               ret 4
// 0062b3f9  8b89bc000000         mov ecx, dword ptr [ecx + 0xbc]
// 0062b3ff  e90c470000           jmp 0x62fb10
// library xtp-15.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?FindAction@CXTPCommandBars@@QBEPAVCXTPControlAction@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBars.cpp
