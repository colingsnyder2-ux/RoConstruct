// from server: 100% by auto
// roc 2011-06 00881b10  unit: CXTPControlGallery  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00881b10
//
// 00881b10  8b8118ffffff         mov eax, dword ptr [ecx - 0xe8]
// 00881b16  83f8ff               cmp eax, -1
// 00881b19  750c                 jne 0x881b27
// 00881b1b  8b49d8               mov ecx, dword ptr [ecx - 0x28]
// 00881b1e  85c9                 test ecx, ecx
// 00881b20  7405                 je 0x881b27
// 00881b22  e939b1f8ff           jmp 0x80cc60
// 00881b27  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPControlGallery.cpp (function ?IsScrollBarEnabled@CXTPControlGallery@@UBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlGallery.cpp
