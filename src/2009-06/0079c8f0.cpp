// from server: 100% by auto
// roc 2009-06 0079c8f0  unit: CXTPControlGallery  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0079c8f0
//
// 0079c8f0  8b8118ffffff         mov eax, dword ptr [ecx - 0xe8]
// 0079c8f6  83f8ff               cmp eax, -1
// 0079c8f9  750c                 jne 0x79c907
// 0079c8fb  8b49d8               mov ecx, dword ptr [ecx - 0x28]
// 0079c8fe  85c9                 test ecx, ecx
// 0079c900  7405                 je 0x79c907
// 0079c902  e99935f8ff           jmp 0x71fea0
// 0079c907  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPControlGallery.cpp (function ?IsScrollBarEnabled@CXTPControlGallery@@UBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlGallery.cpp
