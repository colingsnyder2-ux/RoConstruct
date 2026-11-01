// from server: 100% by auto
// roc 2009-12 008781e0  unit: CXTPControlGallery  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008781e0
//
// 008781e0  e86bf1ffff           call 0x877350
// 008781e5  85c0                 test eax, eax
// 008781e7  7407                 je 0x8781f0
// 008781e9  8bc8                 mov ecx, eax
// 008781eb  e9a025feff           jmp 0x85a790
// 008781f0  33c0                 xor eax, eax
// 008781f2  c3                   ret 
// library xtp-13.2.1/Source\SyntaxEdit\XTPSyntaxEditView.cpp (function ?GetDataManager@CXTPSyntaxEditView@@QAEPAVCXTPSyntaxEditBufferManager@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/SyntaxEdit/XTPSyntaxEditView.cpp
