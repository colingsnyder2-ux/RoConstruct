// from server: 100% by auto
// roc 2011-06 00882470  unit: CXTPControlGallery  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00882470
//
// 00882470  e87bf1ffff           call 0x8815f0
// 00882475  85c0                 test eax, eax
// 00882477  7407                 je 0x882480
// 00882479  8bc8                 mov ecx, eax
// 0088247b  e9c0a7fdff           jmp 0x85cc40
// 00882480  33c0                 xor eax, eax
// 00882482  c3                   ret 
// library xtp-13.2.1/Source\SyntaxEdit\XTPSyntaxEditView.cpp (function ?GetDataManager@CXTPSyntaxEditView@@QAEPAVCXTPSyntaxEditBufferManager@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/SyntaxEdit/XTPSyntaxEditView.cpp
