// from server: 100% by auto
// roc 2009-12 00552920  unit: Exposer  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00552920
//
// 00552920  0fb6442404           movzx eax, byte ptr [esp + 4]
// 00552925  6a0a                 push 0xa
// 00552927  683809b800           push 0xb80938
// 0055292c  50                   push eax
// 0055292d  e89e230100           call 0x564cd0
// 00552932  83c40c               add esp, 0xc
// 00552935  b83809b800           mov eax, 0xb80938
// 0055293a  c20400               ret 4
// library raknet-4.081/PacketLogger.cpp (function ?UserIDTOString@PacketLogger@RakNet@@MAEPBDE@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 PacketLogger.cpp
