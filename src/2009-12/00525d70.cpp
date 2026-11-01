// from server: 100% by auto
// roc 2009-12 00525d70  unit: RBX::Network::VClient::?$FactoryProduct  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00525d70
//
// 00525d70  68b80b0000           push 0xbb8
// 00525d75  e876ffffff           call 0x525cf0
// 00525d7a  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\array_b.cpp (function ??__E_init_CByteArray@@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/array_b.cpp
