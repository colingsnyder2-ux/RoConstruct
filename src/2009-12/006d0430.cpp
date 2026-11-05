// from server: 100% by auto
// roc 2009-12 006d0430  unit: RBX::VPVInstance::?$NonFactoryProduct  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006d0430
//
// 006d0430  68402ab900           push 0xb92a40
// 006d0435  e846bcd3ff           call 0x40c080
// 006d043a  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\auxdata.cpp (function ??__FafxData@@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/auxdata.cpp
