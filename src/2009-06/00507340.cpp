// from server: 100% by auto
// roc 2009-06 00507340  unit: RakPeer  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00507340
//
// 00507340  e80bffffff           call 0x507250
// 00507345  6a00                 push 0
// 00507347  68e8030000           push 0x3e8
// 0050734c  52                   push edx
// 0050734d  50                   push eax
// 0050734e  e8ad292100           call 0x719d00
// 00507353  c3                   ret 
// library openrbx-raknet/GetTime.cpp (function ?GetTime@RakNet@@YAIXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet GetTime.cpp
