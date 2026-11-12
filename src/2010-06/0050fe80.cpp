// from server: 100% by auto
// roc 2010-06 0050fe80  unit: RBX::Network::RoundRobinPhysicsSender  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0050fe80
//
// 0050fe80  e80bffffff           call 0x50fd90
// 0050fe85  6a00                 push 0
// 0050fe87  68e8030000           push 0x3e8
// 0050fe8c  52                   push edx
// 0050fe8d  50                   push eax
// 0050fe8e  e8dd8d2900           call 0x7a8c70
// 0050fe93  c3                   ret 
// library openrbx-raknet/GetTime.cpp (function ?GetTime@RakNet@@YAIXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet GetTime.cpp
