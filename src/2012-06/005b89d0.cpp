// roc 2012-06 005b89d0  unit: RBX::Network::InterpolatingPhysicsReceiver::Job  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005b89d0
//
// 005b89d0  e83bffffff           call 0x5b8910
// 005b89d5  6a00                 push 0
// 005b89d7  68e8030000           push 0x3e8
// 005b89dc  52                   push edx
// 005b89dd  50                   push eax
// 005b89de  e8fda93c00           call 0x9833e0
// 005b89e3  c3                   ret 
// library openrbx-raknet/GetTime.cpp (function ?GetTime@RakNet@@YAIXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet GetTime.cpp
