// from server: 100% by auto
// roc 2008-06 005bbeb0  unit: RBX::Soundscape::SoundService  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005bbeb0
//
// 005bbeb0  e8abf9ffff           call 0x5bb860
// 005bbeb5  e816faffff           call 0x5bb8d0
// 005bbeba  e931f9ffff           jmp 0x5bb7f0
// library raknet-4.081/RakString.cpp (function ?FreeMemory@RakString@RakNet@@SAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O1 /GS- /EHsc /MD
// roc-lib: raknet-4.081 RakString.cpp
