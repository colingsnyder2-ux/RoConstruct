// from server: 100% by auto
// roc 2011-06 0050fe10  unit: Exposer  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0050fe10
//
// 0050fe10  0fb6442404           movzx eax, byte ptr [esp + 4]
// 0050fe15  6a0a                 push 0xa
// 0050fe17  688086cb00           push 0xcb8680
// 0050fe1c  50                   push eax
// 0050fe1d  e84eedffff           call 0x50eb70
// 0050fe22  83c40c               add esp, 0xc
// 0050fe25  b88086cb00           mov eax, 0xcb8680
// 0050fe2a  c20400               ret 4
// library raknet-4.081/PacketLogger.cpp (function ?UserIDTOString@PacketLogger@RakNet@@MAEPBDE@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 PacketLogger.cpp
