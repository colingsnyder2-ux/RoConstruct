// from server: 100% by auto
// roc 2008-06 004bb670  unit: ProfiledRakPeer  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bb670
//
// 004bb670  8a4104               mov al, byte ptr [ecx + 4]
// 004bb673  84c0                 test al, al
// 004bb675  7407                 je 0x4bb67e
// 004bb677  c6819d08000000       mov byte ptr [ecx + 0x89d], 0
// 004bb67e  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ?DisableSecurity@RakPeer@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
