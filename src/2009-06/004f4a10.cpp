// from server: 100% by auto
// roc 2009-06 004f4a10  unit: Exposer  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004f4a10
//
// 004f4a10  0fb6442404           movzx eax, byte ptr [esp + 4]
// 004f4a15  6a0a                 push 0xa
// 004f4a17  68f0f4a300           push 0xa3f4f0
// 004f4a1c  50                   push eax
// 004f4a1d  e8ee8b0000           call 0x4fd610
// 004f4a22  83c40c               add esp, 0xc
// 004f4a25  b8f0f4a300           mov eax, 0xa3f4f0
// 004f4a2a  c20400               ret 4
// library raknet-4.081/PacketLogger.cpp (function ?UserIDTOString@PacketLogger@RakNet@@MAEPBDE@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 PacketLogger.cpp
