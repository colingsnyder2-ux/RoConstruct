// from server: 100% by auto
// roc 2008-06 004bb5b0  unit: RakPeerInterface  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bb5b0
//
// 004bb5b0  6a1c                 push 0x1c
// 004bb5b2  ff15b0288000         call dword ptr [0x8028b0]
// 004bb5b8  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004bb5bc  8b542408             mov edx, dword ptr [esp + 8]
// 004bb5c0  83c404               add esp, 4
// 004bb5c3  894814               mov dword ptr [eax + 0x14], ecx
// 004bb5c6  89500c               mov dword ptr [eax + 0xc], edx
// 004bb5c9  c6401801             mov byte ptr [eax + 0x18], 1
// 004bb5cd  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ?AllocPacket@@YAPAUPacket@@IPAE@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
