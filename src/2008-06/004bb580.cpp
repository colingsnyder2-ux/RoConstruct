// from server: 100% by auto
// roc 2008-06 004bb580  unit: RakPeerInterface  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bb580
//
// 004bb580  56                   push esi
// 004bb581  8b742408             mov esi, dword ptr [esp + 8]
// 004bb585  8d461c               lea eax, [esi + 0x1c]
// 004bb588  50                   push eax
// 004bb589  ff15b0288000         call dword ptr [0x8028b0]
// 004bb58f  83c404               add esp, 4
// 004bb592  8d481c               lea ecx, [eax + 0x1c]
// 004bb595  89700c               mov dword ptr [eax + 0xc], esi
// 004bb598  894814               mov dword ptr [eax + 0x14], ecx
// 004bb59b  c6401800             mov byte ptr [eax + 0x18], 0
// 004bb59f  5e                   pop esi
// 004bb5a0  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ?AllocPacket@@YAPAUPacket@@I@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
