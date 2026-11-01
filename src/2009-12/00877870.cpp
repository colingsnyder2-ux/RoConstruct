// from server: 100% by auto
// roc 2009-12 00877870  unit: CXTPControlGallery  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00877870
//
// 00877870  8b8118ffffff         mov eax, dword ptr [ecx - 0xe8]
// 00877876  83f8ff               cmp eax, -1
// 00877879  750c                 jne 0x877887
// 0087787b  8b49d8               mov ecx, dword ptr [ecx - 0x28]
// 0087787e  85c9                 test ecx, ecx
// 00877880  7405                 je 0x877887
// 00877882  e929edf7ff           jmp 0x7f65b0
// 00877887  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPControlGallery.cpp (function ?IsScrollBarEnabled@CXTPControlGallery@@UBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlGallery.cpp
