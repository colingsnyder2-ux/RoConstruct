// from server: 100% by auto
// roc 2010-06 008253e0  unit: CXTPControlGallery  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008253e0
//
// 008253e0  e86bf1ffff           call 0x824550
// 008253e5  85c0                 test eax, eax
// 008253e7  7407                 je 0x8253f0
// 008253e9  8bc8                 mov ecx, eax
// 008253eb  e9d09dfdff           jmp 0x7ff1c0
// 008253f0  33c0                 xor eax, eax
// 008253f2  c3                   ret 
// library xtp-13.2.1/Source\SyntaxEdit\XTPSyntaxEditView.cpp (function ?GetDataManager@CXTPSyntaxEditView@@QAEPAVCXTPSyntaxEditBufferManager@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/SyntaxEdit/XTPSyntaxEditView.cpp
