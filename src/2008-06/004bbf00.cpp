// from server: 100% by auto
// roc 2008-06 004bbf00  unit: ProfiledRakPeer  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bbf00
//
// 004bbf00  d9ee                 fldz 
// 004bbf02  dc9938070000         fcomp qword ptr [ecx + 0x738]
// 004bbf08  dfe0                 fnstsw ax
// 004bbf0a  f6c405               test ah, 5
// 004bbf0d  7b17                 jnp 0x4bbf26
// 004bbf0f  6683b94007000000     cmp word ptr [ecx + 0x740], 0
// 004bbf17  770d                 ja 0x4bbf26
// 004bbf19  6683b94207000000     cmp word ptr [ecx + 0x742], 0
// 004bbf21  7703                 ja 0x4bbf26
// 004bbf23  33c0                 xor eax, eax
// 004bbf25  c3                   ret 
// 004bbf26  b801000000           mov eax, 1
// 004bbf2b  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ?IsNetworkSimulatorActive@RakPeer@@UAE_NXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
