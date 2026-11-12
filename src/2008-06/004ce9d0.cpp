// from server: 100% by auto
// roc 2008-06 004ce9d0  unit: RBX::Network::PhysicsSender  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004ce9d0
//
// 004ce9d0  8b442404             mov eax, dword ptr [esp + 4]
// 004ce9d4  81c128050000         add ecx, 0x528
// 004ce9da  85c0                 test eax, eax
// 004ce9dc  7409                 je 0x4ce9e7
// 004ce9de  89442404             mov dword ptr [esp + 4], eax
// 004ce9e2  e9b96f0000           jmp 0x4d59a0
// 004ce9e7  e804700000           call 0x4d59f0
// 004ce9ec  c20400               ret 4
// library openrbx-raknet/ReliabilityLayer.cpp (function ?SetEncryptionKey@ReliabilityLayer@@QAEXPBE@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
