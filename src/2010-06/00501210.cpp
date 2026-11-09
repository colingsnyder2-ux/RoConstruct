// from server: 100% by auto
// roc 2010-06 00501210  unit: Exposer  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00501210
//
// 00501210  0fb6442404           movzx eax, byte ptr [esp + 4]
// 00501215  6a0a                 push 0xa
// 00501217  68e069c000           push 0xc069e0
// 0050121c  50                   push eax
// 0050121d  e8ee240100           call 0x513710
// 00501222  83c40c               add esp, 0xc
// 00501225  b8e069c000           mov eax, 0xc069e0
// 0050122a  c20400               ret 4
// library raknet-4.081/PacketLogger.cpp (function ?UserIDTOString@PacketLogger@RakNet@@MAEPBDE@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 PacketLogger.cpp
