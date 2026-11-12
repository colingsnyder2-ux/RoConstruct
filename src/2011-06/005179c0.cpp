// from server: 100% by auto
// roc 2011-06 005179c0  unit: RBX::Network::NetworkOwnerJob  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005179c0
//
// 005179c0  e83bffffff           call 0x517900
// 005179c5  6a00                 push 0
// 005179c7  68e8030000           push 0x3e8
// 005179cc  52                   push edx
// 005179cd  50                   push eax
// 005179ce  e88d392f00           call 0x80b360
// 005179d3  c3                   ret 
// library openrbx-raknet/GetTime.cpp (function ?GetTime@RakNet@@YAIXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet GetTime.cpp
