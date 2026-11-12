// from server: 100% by auto
// roc 2008-06 004c9910  unit: RBX::Network::InterpolatingPhysicsReceiver  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c9910
//
// 004c9910  e87bfeffff           call 0x4c9790
// 004c9915  6a00                 push 0
// 004c9917  68e8030000           push 0x3e8
// 004c991c  52                   push edx
// 004c991d  50                   push eax
// 004c991e  e80d831d00           call 0x6a1c30
// 004c9923  c3                   ret 
// library openrbx-raknet/GetTime.cpp (function ?GetTime@RakNet@@YAIXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet GetTime.cpp
