// from server: 100% by auto
// roc 2009-06 0079d250  unit: CXTPControlGallery  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0079d250
//
// 0079d250  e87bf1ffff           call 0x79c3d0
// 0079d255  85c0                 test eax, eax
// 0079d257  7407                 je 0x79d260
// 0079d259  8bc8                 mov ecx, eax
// 0079d25b  e9407ffeff           jmp 0x7851a0
// 0079d260  33c0                 xor eax, eax
// 0079d262  c3                   ret 
// library xtp-13.2.1/Source\SyntaxEdit\XTPSyntaxEditView.cpp (function ?GetDataManager@CXTPSyntaxEditView@@QAEPAVCXTPSyntaxEditBufferManager@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/SyntaxEdit/XTPSyntaxEditView.cpp
