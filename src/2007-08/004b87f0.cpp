// from server: 100% by colin
// roc 2007-08 004b87f0  unit: RakPeerInterface  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004b87f0
//
// 004b87f0  6a1c                 push 0x1c
// 004b87f2  ff15d0e67700         call dword ptr [0x77e6d0]
// 004b87f8  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004b87fc  8b542408             mov edx, dword ptr [esp + 8]
// 004b8800  83c404               add esp, 4
// 004b8803  894814               mov dword ptr [eax + 0x14], ecx
// 004b8806  89500c               mov dword ptr [eax + 0xc], edx
// 004b8809  c6401801             mov byte ptr [eax + 0x18], 1
// 004b880d  c3                   ret 
// copied from an identical function in another client (function ?AllocPacket@@YAPAUPacket@@IPAE@Z)

// from server: 100% by tester
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lang: cpp
// roc-lib: openrbx-raknet RakPeer.cpp