// from server: 100% by auto
// roc 2007-03 0069ff00  unit: seg_00690000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0069ff00
//
// 0069ff00  e8abf8ffff           call 0x69f7b0
// 0069ff05  85c0                 test eax, eax
// 0069ff07  7407                 je 0x69ff10
// 0069ff09  8bc8                 mov ecx, eax
// 0069ff0b  e9e0b7fcff           jmp 0x66b6f0
// 0069ff10  33c0                 xor eax, eax
// 0069ff12  c3                   ret 
// library xtp-13.2.1/Source\SyntaxEdit\XTPSyntaxEditView.cpp (function ?GetDataManager@CXTPSyntaxEditView@@QAEPAVCXTPSyntaxEditBufferManager@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/SyntaxEdit/XTPSyntaxEditView.cpp
