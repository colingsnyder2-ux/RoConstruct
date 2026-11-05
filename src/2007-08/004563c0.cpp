// from server: 100% by auto
// roc 2007-08 004563c0  unit: RBX::Network::VPlayers::?$Listener  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004563c0
//
// 004563c0  56                   push esi
// 004563c1  8bf1                 mov esi, ecx
// 004563c3  e8769e1d00           call 0x63023e
// 004563c8  8bce                 mov ecx, esi
// 004563ca  e811ffffff           call 0x4562e0
// 004563cf  5e                   pop esi
// 004563d0  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxcolorpropertysheet.cpp (function ?OnSize@CMFCColorPropertySheet@@IAEXIHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorpropertysheet.cpp
