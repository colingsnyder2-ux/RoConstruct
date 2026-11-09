// from server: 100% by auto
// roc 2012-06 00798890  unit: RBX::Reflection::$$A6AXPBVPropertyDescriptor::?$signal::Vslot::?$callable  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00798890
//
// 00798890  6a03                 push 3
// 00798892  e829ffffff           call 0x7987c0
// 00798897  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\viewrich.cpp (function ?OnParaCenter@CRichEditView@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/viewrich.cpp
