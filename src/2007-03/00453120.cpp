// from server: 100% by auto
// roc 2007-03 00453120  unit: seg_00450000  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00453120
//
// 00453120  e84b840300           call 0x48b570
// 00453125  f6d8                 neg al
// 00453127  1bc0                 sbb eax, eax
// 00453129  83c001               add eax, 1
// 0045312c  c3                   ret 
// library raknet-4.081/CloudClient.cpp (function ?DoEndianSwap@BitStream@RakNet@@SA_NXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 CloudClient.cpp
