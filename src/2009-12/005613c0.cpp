// from server: 100% by auto
// roc 2009-12 005613c0  unit: RBX::Network::RoundRobinPhysicsSender  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005613c0
//
// 005613c0  e80bffffff           call 0x5612d0
// 005613c5  6a00                 push 0
// 005613c7  68e8030000           push 0x3e8
// 005613cc  52                   push edx
// 005613cd  50                   push eax
// 005613ce  e85d372900           call 0x7f4b30
// 005613d3  c3                   ret 
// library raknet-4.081/GetTime.cpp (function ?GetTime@RakNet@@YA_KXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 GetTime.cpp
