// from server: 100% by auto
// roc 2010-06 00824a70  unit: CXTPControlGallery  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00824a70
//
// 00824a70  8b8118ffffff         mov eax, dword ptr [ecx - 0xe8]
// 00824a76  83f8ff               cmp eax, -1
// 00824a79  750c                 jne 0x824a87
// 00824a7b  8b49d8               mov ecx, dword ptr [ecx - 0x28]
// 00824a7e  85c9                 test ecx, ecx
// 00824a80  7405                 je 0x824a87
// 00824a82  e9095cf8ff           jmp 0x7aa690
// 00824a87  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPControlGallery.cpp (function ?IsScrollBarEnabled@CXTPControlGallery@@UBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlGallery.cpp
