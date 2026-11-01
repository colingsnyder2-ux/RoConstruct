// from server: 100% by auto
// roc 2009-06 0072b230  unit: CXTPCommandBar  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0072b230
//
// 0072b230  85c9                 test ecx, ecx
// 0072b232  7518                 jne 0x72b24c
// 0072b234  68f0b87100           push 0x71b8f0
// 0072b239  b99426a500           mov ecx, 0xa52694
// 0072b23e  e8bd0c1200           call 0x84bf00
// 0072b243  85c0                 test eax, eax
// 0072b245  750a                 jne 0x72b251
// 0072b247  e998dafeff           jmp 0x718ce4
// 0072b24c  e86ffcffff           call 0x72aec0
// 0072b251  8bc8                 mov ecx, eax
// 0072b253  e9688d0600           jmp 0x793fc0
// library xtp-15.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?ClosePopups@CXTPCommandBars@@QBEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBars.cpp
